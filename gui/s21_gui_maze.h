#ifndef __S21_GUI_MAZE_H__
#define __S21_GUI_MAZE_H__

#include <math.h>
#include <ncurses.h>
#include <signal.h>

#include "s21_maze_api.h"

// #define BG_COLOR 11111111
// #define WALL_COLOR 11111111
// #define PATH_COLOR 11111111

#define MENU_HEIGHT 10

// #define WALL_H '_'
// #define WALL_V '|'

#define COLOR_BG COLOR_BLACK
#define COLOR_WALL COLOR_GREEN
#define COLOR_PATH COLOR_BLUE

void set_ncurses();
void cleanup_ncurses();
void draw_menu();
#endif