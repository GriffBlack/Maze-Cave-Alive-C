#include "s21_gui_maze.h"

WINDOW *menu_win;
WINDOW *maze_win;
// WINDOW *cave_win;

#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

void set_ncurses() {
  initscr();  // Инициализация ncurses
  cbreak();   // Отключение буферизации ввода
  noecho();  // Отключение отображения вводимых символов
  keypad(stdscr, TRUE);  // Включение обработки функциональных клавиш
  curs_set(0);           // Скрытие курсора
  scrollok(stdscr, TRUE);  // Отключает скролл
  // nodelay(stdscr, TRUE);  // Отключчает задержку при вызове функции getch

  menu_win = newwin(MENU_HEIGHT, COLS, 0, 0);
  maze_win = newwin(LINES - MENU_HEIGHT, COLS, MENU_HEIGHT, 0);

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BG);
  init_pair(2, COLOR_WHITE, COLOR_PATH);
}

void cleanup_ncurses() {
  delwin(maze_win);  // Удаление окна лабиринта
  delwin(menu_win);  // Удаление окна пещеры
  endwin();
}

void draw_menu() {
  wclear(menu_win);
  box(menu_win, 0, 0);
  box(maze_win, 0, 0);
  mvwprintw(menu_win, 1, 2, "Menu:");
  mvwprintw(menu_win, 2, 2, "1 - read maze");
  mvwprintw(menu_win, 3, 2, "2 - generate maze");
  mvwprintw(menu_win, 4, 2, "3 - search path");
  mvwprintw(menu_win, 5, 2, "4 - generate cave");
  mvwprintw(menu_win, 6, 2, "5 - q-learining");
  mvwprintw(menu_win, 7, 2, "6 - web");
  mvwprintw(menu_win, 8, 2, "q - quit");
  wrefresh(menu_win);
}

void clearExtraInformation() {
  for (int i = 1; i < 7; ++i) {
    move(i, 25);
    wclrtoeol(stdscr);
  }
}

void resize_handler(int sig) {
  if (sig == SIGWINCH) {
    endwin();
    refresh();
    clear();

    wresize(menu_win, MENU_HEIGHT, COLS);  // Изменяем размер окна меню
    wresize(maze_win, LINES - MENU_HEIGHT,
            COLS);  // Изменяем размер окна лабиринта

    mvwin(maze_win, MENU_HEIGHT, 0);  // Перемещаем окно лабиринта после меню

    wclear(menu_win);
    wclear(maze_win);
    box(menu_win, 0, 0);
    box(maze_win, 0, 0);
  }
}

void draw_maze(maze *mz) {
  int max_y, max_x;
  getmaxyx(maze_win, max_y, max_x);
  int scale_x = (int)floor(1.0 * max_x / (mz->size_y));  // ceil - to max size
  int scale_y = (int)floor(1.0 * max_y / (mz->size_x));  // ceil - to max size

  wclear(maze_win);
  box(maze_win, 0, 0);

  for (int i = 0; i < mz->size_x; i++) {
    for (int j = 0; j < mz->size_y; j++) {
      if (mz->bot_bounds[i][j] == 1 || (i == mz->size_x - 1)) {
        for (int n = 1; n < scale_x; n++)
          mvwaddch(maze_win, i * scale_y + scale_y, j * scale_x + n, WALL_H);
        if (mz->right_bounds[i][j] == 1 || j == (mz->size_y - 1))
          for (int n = 1; n <= scale_y; n++)
            mvwaddch(maze_win, i * scale_y + n, j * scale_x + scale_x, WALL_V);
        else
          mvwaddch(maze_win, i * scale_y + scale_y, j * scale_x + scale_x,
                   WALL_H);
      } else if (mz->right_bounds[i][j] == 1 || j == (mz->size_y - 1)) {
        for (int n = 1; n <= scale_y; n++)
          mvwaddch(maze_win, i * scale_y + n, j * scale_x + scale_x, WALL_V);
      }
    }
  }
  wrefresh(maze_win);
}