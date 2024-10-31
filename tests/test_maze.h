#include <check.h>
// #include <ncurses.h>

#include "s21_maze_api.h"

FILE *create_temp_file(const char *content);
int compare_files(FILE *f1, FILE *f2);

void run_tests(void);
void run_testcase(Suite *testcase);

// Suite *maze_tests(void);
Suite *maze_suite_memory(void);