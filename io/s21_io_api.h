#ifndef __S21_IO_API_H__
#define __S21_IO_API_H__

#include "gui/s21_gui_maze.h"
#include "s21_maze_api.h"

void menuLoadMaze(maze *mz);
void menuGenerateMaze(maze *mz);
int loadMaze(maze *mz, char *fileName);
void textMsg(int numberRow, int numberPosition, int numberItem);
int validatorInput(int value);
#endif