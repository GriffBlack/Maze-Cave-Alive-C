#include "test_maze.h"

START_TEST(test_init_maze) {
  maze *mz = init_maze();
  ck_assert_ptr_nonnull(mz);
  ck_assert_int_eq(mz->size_x, 0);
  ck_assert_int_eq(mz->size_y, 0);
  ck_assert_ptr_null(mz->bot_bounds);
  ck_assert_ptr_null(mz->right_bounds);
  free(mz);
}
END_TEST

START_TEST(test_set_maze_size) {
  maze *mz = init_maze();
  set_maze_size(mz, 30, 20);
  ck_assert_ptr_nonnull(mz);
  ck_assert_int_eq(mz->size_x, 30);
  ck_assert_int_eq(mz->size_y, 20);
  ck_assert_ptr_nonnull(mz->bot_bounds);
  ck_assert_ptr_nonnull(mz->right_bounds);
  // ck_assert_ptr_null(mz->bot_bounds);
  // ck_assert_ptr_null(mz->right_bounds);
  int error = set_maze_size(mz, 0, 20);
  ck_assert_int_eq(error, 1);
  error = set_maze_size(mz, 30, 0);
  ck_assert_int_eq(error, 1);
  error = set_maze_size(mz, 20, 30);
  ck_assert_int_eq(mz->size_x, 20);
  ck_assert_int_eq(mz->size_y, 30);
  ck_assert_ptr_nonnull(mz->bot_bounds);
  ck_assert_ptr_nonnull(mz->right_bounds);
  free_maze(mz);
}
END_TEST

Suite *maze_suite_memory(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Maze constructor");
  tc_core = tcase_create("Core");

  suite_add_tcase(s, tc_core);

  tcase_add_test(tc_core, test_init_maze);
  tcase_add_test(tc_core, test_set_maze_size);
  return s;
}
