#include <string.h>

#include "s21_io_api.h"

/// @brief Отроисовка текста запроса в окне меню
/// @param numberRow номер строки отображения
/// @param numberPosition номер расположения на строке
/// @param numberItem номер запроса в массиве item
/// @param value значение возвращаемое запросом
void inputMenu(int numberRow, int numberPosition, int numberItem, int *value) {
  echo();
  char item[2][20] = {"1 FileName: ", "2 error"};
  mvprintw(numberRow, numberPosition, "%s", item[numberItem]);
  if (numberItem != 0) scanw("%d", value);

  // заглушка
  //   set_maze_size(mz, 3, 10);
}
void textMsg(int numberRow, int numberPosition, int numberItem) {
  char error[4][30] = {"1 Failed to load from file"};
  mvprintw(numberRow, numberPosition, "%s", error[numberItem]);
}

void menuItemLoadMaze(maze *mz) {
  char fileName[100];  //= "aa.txt";
  //   mvprintw(3, 25, "FileName: ");
  inputMenu(3, 25, 0, &mz->size_x);
  scanw("%s", fileName);
  if (loadMaze(mz, fileName) != 1) {
    mvprintw(4, 25, "%s", fileName);
    // set_maze_size(mz, 3, 10);
  } else {
    textMsg(4, 25, 0);
  }
  //   inputMenu(mz, 1, &mz->size_x);
}
