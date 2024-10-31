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

  // signal(SIGWINCH, resize_handler);
  //   initscr();  // Initialize ncurses
  //   keypad(stdscr, TRUE);  // Enable keypad for arrow keys
  //   start_color();
  //   srand(time(NULL));
  //   init_pair(1, COLOR_BLACK, COLOR_YELLOW);
  //   maze_initializer();

  while (ch != 'q' && error == 0) {
    ch = getch();
    draw_menu();
    // draw_maze();

    switch (ch) {
      case '1':
        menuItemLoadMaze(mz);
        break;
      case 'q':
        break;
    }
  }
  free_maze(mz);
  cleanup_ncurses();
}