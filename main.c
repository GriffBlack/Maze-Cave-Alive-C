// #include "business_logic/web_server.h"
#include <pthread.h>
#include <signal.h>  // для использования потоков

#include "gui/s21_gui_maze.h"
#include "io/s21_io_api.h"

int main() {
  //   srand(time(NULL));
  int error = 0;
  int ch = 0;
  set_ncurses();
  maze *mz = init_maze();
  signal(SIGWINCH, resize_handler);

  //   initscr();  // Initialize ncurses
  //   keypad(stdscr, TRUE);  // Enable keypad for arrow keys
  //   start_color();
  //   srand(time(NULL));
  //   init_pair(1, COLOR_BLACK, COLOR_YELLOW);
  //   maze_initializer();

  while (ch != 'q' && error == 0) {
    ch = getch();
    draw_menu();
    clearExtraInformation();
    if (mz->bot_bounds != NULL) draw_maze(mz);
    // добавить проверку на пещеру
    // добавить очиску лобиринта
    switch (ch) {
      case '1':
        menuLoadMaze(mz);
        break;
      case '2':
        menuGenerateMaze(mz);
        break;
      case '3':
        menuLoadMaze(mz);
        break;
      case '4':
        menuLoadMaze(mz);
        break;
      case '5':
        menuLoadMaze(mz);
        break;
      case '6':
        menuLoadMaze(mz);
        break;
      case 'q':
        break;
    }
    // clearExtraInformation();
  }
  free_maze(mz);
  cleanup_ncurses();
}