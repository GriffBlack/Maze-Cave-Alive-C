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