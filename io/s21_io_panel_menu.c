#include <string.h>

#include "s21_io_api.h"

void printline(int lin, int *line, int *group, maze *mz) {
  // for (int i = 0; i < mz->size_x; i++) {
  int i = 0;
  for (int j = 0; j < mz->size_y; j++, i++) {
    mvprintw(30 + lin, 25 + j, "%d |", line[j]);
  }
  for (int j = 0; j < mz->size_y * mz->size_x; j++, i++) {
    mvprintw(10 + lin, 20 + j, "%d+", group[j]);

    // mz->size_y * mz->size_x
  }
}

int validatorInput(int value) {
  int error = 0;
  if (value > 50 || value <= 0) {
    value = 0;
    clearExtraInformation();
    textMsg(1, 25, 1);
    error = 1;
  }
  return error;
}
/// @brief Отроисовка текста запроса в окне меню
/// @param numberRow номер строки отображения
/// @param numberPosition номер расположения на строке
/// @param numberItem номер запроса в массиве item
/// @param value значение возвращаемое запросом
void inputMenu(int numberRow, int numberPosition, int numberItem, int *value) {
  echo();
  char item[3][30] = {
      "FileName: ",                // 0
      "Count of rows: [max 50] ",  // 1
      "Count of cols: [max 50] "   // 2
  };
  mvprintw(numberRow, numberPosition, "%s", item[numberItem]);
  if (numberItem != 0) scanw("%d", value);
}
/// @brief Отроисовка текста сообщений в окне меню
/// @param numberRow номер строки отображения
/// @param numberPosition номер расположения на строке
/// @param numberItem номер запроса в массиве item
void textMsg(int numberRow, int numberPosition, int numberItem) {
  char error[4][30] = {"Failed to load from file",  // 0
                       "Out of range maze!"};       // 1
  mvprintw(numberRow, numberPosition, "%s", error[numberItem]);
}
/// @brief Меню загрузки лабиринта из файла
/// @param mz структура лабиринта
void menuLoadMaze(maze *mz) {
  char fileName[100];
  inputMenu(3, 25, 0, &mz->size_x);
  scanw("%s", fileName);
  if (loadMaze(mz, fileName) != 1) {
    draw_maze(mz);
  } else {
    textMsg(4, 25, 0);
  }
}
/// @brief Меню генерации лабиринта
/// @param mz структура лабиринта
void menuGenerateMaze(maze *mz) {
  int rows, cols;
  do {
    inputMenu(3, 25, 1, &rows);
    inputMenu(4, 25, 2, &cols);
  } while (validatorInput(rows) || validatorInput(cols));
  set_maze_size(mz, rows, cols);
  generateEller(mz);
  clearExtraInformation();
  draw_maze(mz);
}
