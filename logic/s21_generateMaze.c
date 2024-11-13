// #include "s21_io_api.h"
#include "s21_maze_api.h"

// void printline(int *line, int *group, maze *mz) {
//   // for (int i = 0; i < mz->size_x; i++) {
//   int i = 0;
//   for (int j = 0; j < mz->size_y; j++, i++) {
//     mvprintw(1 + i * 2, 20 + j, "%s-", line[j]);
//     mvprintw(2 + i * 2, 20 + j, "%s-", group[j]);
//   }
//   // }
// }

void generateEller(maze *mz) {
  int *line = calloc(mz->size_y, sizeof(int));
  int *group = calloc(mz->size_y * mz->size_x, sizeof(int));
  int count = 1;
  for (int i = 0; i < mz->size_y; i++) {
    line[i] = count;
    group[count] = 1;
    count++;
  }
  for (int i = 0; i < mz->size_x; i++) {
    printline(i, line, group, mz);

    for (int j = 0; j < mz->size_y; j++) {
      mz->right_bounds[i][j] = 0;
      mz->bot_bounds[i][j] = 0;
      if (rand() % 2 == 0) {
        mz->right_bounds[i][j] = 1;
      } else {
        if (j > 0 && line[j] == line[j - 1]) {
          mz->right_bounds[i][j - 1] = 1;
        } else {
          int oldGroup = line[j];

          for (int k = 0; k < mz->size_y; k++) {
            if (j > 0 && line[k] == oldGroup) {
              line[k] = line[j - 1];
              group[line[j - 1]]++;
              group[oldGroup]--;
            }
          }
          // line[j] = line[j - 1];
          // while (group[oldGroup] > 0) {
          //   group[line[j]]++;
          //   group[oldGroup]--;
          // }
        }
        // }

        // if (i == 0) {
        //   if (rand() % 2 == 0) {
        //     mz->right_bounds[i][j] = 1;
        //   }
        //   line[j] = count;
        //   group[count] = 1;
        //   count++;
        // } else {
        //   if (rand() % 2 == 0) {
        //     mz->right_bounds[i][j] = 1;
        //   } else {
        //     if (j > 0 && line[j] == line[j - 1]) {
        //       mz->right_bounds[i][j - 1] = 1;
        //     } else {
        //       int oldGroup = line[j];
        //       line[j] = line[j - 1];
        //       while (group[oldGroup] > 0) {
        //         group[line[j]]++;
        //         group[oldGroup]--;
        //       }
        //     }
        //   }
        // if (i < (mz->size_x - 1)) {
        //   mz->right_bounds[i][j] = mz->right_bounds[i + 1][j];
        // }
      }
      if (j == mz->size_y - 1) mz->right_bounds[i][j] = 1;
    }
    mz->right_bounds[i][mz->size_y - 1] = 1;
    for (int j = 0; j < mz->size_y; j++) {
      if (i > 0 && mz->bot_bounds[i - 1][j] == 1) {
        line[j] = count;
        group[count] = 1;
        count++;
      }
      if (i == (mz->size_x - 1) && j > 0 && line[j] != line[j - 1])
        mz->right_bounds[i][j - 1] = 0;
      if (rand() % 2 != 0 && group[line[j]] > 1) {
        mz->bot_bounds[i][j] = 1;
        group[line[j]]--;
      }
    }
    // printline(i, line, group, mz);
  }
  free(line);
  free(group);
}