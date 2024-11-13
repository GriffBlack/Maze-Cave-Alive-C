#include <ctype.h>

#include "s21_io_api.h"
int loadMaze(maze *mz, char *fileName) {
  int error = 0;
  int rows, cols;
  FILE *f = fopen(fileName, "r");
  if (f != NULL) {
    fscanf(f, "%d %d\n", &rows, &cols);
    error = set_maze_size(mz, rows, cols);
    int i = 0;
    int ch;
    char buf[101];

    // for (int i = 0; i < rows; i++)
    //   if ((fgets(buf, 101, f)) != NULL && error != 1) {
    //     mvprintw(i, 60, "%s", buf);
    //     char *str = buf;
    //     for (int j = 0; j < cols; j++) {
    //       while (!isdigit(*str) && *str != '\n') str++;
    //       ch = atoi(str);
    //       if (ch != 0 && ch != 1) error = 1;
    //       mvprintw(i, 35 + j, "%d", ch);
    //       while (!isdigit(*str) && *str != '\n') str++;
    //       str++;
    //     }
    //   } else
    //     error = 1;

    // mvprintw(7, 25, "%d", 12);
    // fgetc(f);  // Read newline character

    while ((fgets(buf, 101, f)) != NULL && error != 1) {
      // while ((ch = getc(f)) != EOF) {
      // while (fgetc(f) != EOF) {
      // mvprintw(i, 60, "%s", buf);
      // mvprintw(1, 25, "start");
      int j = 0;

      char *str = buf;
      while (!isdigit(*str) && *str != '\n') str++;
      while (j < cols && *str != '\0' && error != 1) {
        ch = atoi(str);
        if (ch != 0 && ch != 1) error = 1;
        while (!isdigit(*str) && *str != '\n') str++;
        // fscanf(buf, "%d", &ch);

        //   mvprintw(i, 35, "%s", buf);
        if (*str == '\n' && (j) < cols && j > 0) {
          // mvprintw(i, 55, "error");
          error = 1;
        } else {
          // mvprintw(i, 35 + j, "%d", ch);
          if (*str == '\n' && j == 0)
            i--;
          else {
            if (rows <= i) {
              mz->bot_bounds[i % rows][j] = ch;
            } else {
              mz->right_bounds[i % rows][j] = ch;
            }
          }
        }
        // if (*str == '\n' && (j) < cols && j >= 0) mvprintw(i, 55, "error");
        str++;
        j++;
      }
      //   fgetc(f);
      i++;
    }
    // fscanf(f, " %d", &ch);
    fclose(f);
  } else {
    error = 1;
  }
  return error;
}