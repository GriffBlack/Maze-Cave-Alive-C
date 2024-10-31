#include "s21_maze_api.h"

/// @brief Выделение памяти для структуры maze
/// @return Структура maze
maze *init_maze() {
  maze *mz = (maze *)malloc(sizeof(maze));
  if (mz != NULL) {
    mz->size_x = 0;
    mz->size_y = 0;
    mz->bot_bounds = NULL;
    mz->right_bounds = NULL;
  }
  return mz;
}

/// @brief Установка размеров maze, выделение памяти для массивов bot/right
/// @param mz структура maze
/// @param x ширина
/// @param y высота
/// @return 1 = error, 0 = success
int set_maze_size(maze *mz, int x, int y) {
  int error = (x <= 0 || y <= 0 || x > MAX_BOUND_RIGHT || y > MAX_BOUND_BOT);
  if (!error && mz != NULL) {
    if (mz->bot_bounds != NULL) {
      for (int i = 0; i < mz->size_x; i++) {
        free(mz->bot_bounds[i]);
        free(mz->right_bounds[i]);
      }
      free(mz->bot_bounds);
      free(mz->right_bounds);
    }
    mz->size_x = x;
    mz->size_y = y;
    mz->bot_bounds = (int **)calloc(x, sizeof(int *));
    mz->right_bounds = (int **)calloc(x, sizeof(int *));
    for (int i = 0; !error && i < mz->size_x; i++) {
      mz->bot_bounds[i] = (int *)calloc(y, sizeof(int));
      mz->right_bounds[i] = (int *)calloc(y, sizeof(int));
      if (!mz->bot_bounds[i] || !mz->right_bounds[i]) {
        free_maze(mz);
        error = 1;
      }
    }
  }
  return error;
}

/// @brief Установка размеров поля
/// @param fld поле
/// @param x по ширине
/// @param y по высоте
/// @return 1 = error, 0 = success
// int fill_maze(maze *mz, int **bots, int **rights) {
//   int error = bots == NULL || rights == NULL;
//   if (!error && mz != NULL && mz->size_x > 0 && mz->size_y > 0) {
//     for (int i = 0; !error && i < mz->size_x; i++) {
//       if (bots[i] == NULL || rights[i] == NULL) {
//         error = 1;
//         clear_maze(mz);
//       }
//       for (int j = 0; !error && j < mz->size_y; j++) {
//         mz->bot_bounds[i][j] = bots[i][j];
//         mz->right_bounds[i][j] = rights[i][j];
//       }
//     }
//   }
//   return error;
// }

/// @brief Освобождение памяти
void free_maze(maze *mz) {
  if (mz != NULL) {
    for (int i = 0; i < mz->size_x; i++) {
      if (mz->bot_bounds != NULL) free(mz->bot_bounds[i]);
      if (mz->right_bounds != NULL) free(mz->right_bounds[i]);
    }
    free(mz->bot_bounds);
    free(mz->right_bounds);
    free(mz);
  }
}