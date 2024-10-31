#ifndef __S21_MAZE_API_H__
#define __S21_MAZE_API_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOUND_TOP 0
#define MAX_BOUND_BOT 50
#define MAX_BOUND_LEFT 0
#define MAX_BOUND_RIGHT 50

#define DEAD 0
#define ALIVE 1

#define SUCCESS 0
#define ERROR 1

#define EPS_QLEARNING 0.05
#define ALPHA_QLEARNING 0.3
#define GAMMA_QLEARNING 0.6

// Maze struct
typedef struct Maze {
  int size_x;
  int size_y;
  int **right_bounds;
  int **bot_bounds;
} maze;

maze *init_maze();
int set_maze_size(maze *mz, int x, int y);
// int fill_maze(maze *mz, int **bots, int **rights);
void free_maze(maze *mz);
// void clear_maze(maze *mz);

int load_maze(maze *mz, const char *path);
void save_maze(maze mz, const char *path);

#endif