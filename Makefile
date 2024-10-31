CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -pthread -g
LDFLAGS = -lncurses -lm  # Добавлен флаг -lm для математической библиотеки
TEST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit
# BL_FOLDER = business_logic/
MEMORY_FOLDER = memory/
IO_FOLDER = io/
SRC = $(MEMORY_FOLDER)s21_memory_maze.c \
		$(IO_FOLDER)s21_io_panel_menu.c \
		 $(IO_FOLDER)s21_io_maze.c \
		#  $(BL_FOLDER)maze_memory.c \
		#  $(BL_FOLDER)maze_eller.c \
		#  $(BL_FOLDER)maze_solution.c \
		#  $(BL_FOLDER)s21_maze_cell.c \
		#  $(BL_FOLDER)s21_maze_path.c \
		#  $(BL_FOLDER)s21_maze_field.c \
		#  $(BL_FOLDER)s21_maze_cave.c \
		#  $(BL_FOLDER)cave_IO.c 
# GUI_FOLDER = gui/
GUI_SRC = gui/s21_gui_maze.c
# WEB_SERVER_SRC = $(BL_FOLDER)web_server.c mongoose/mongoose.c
MAIN_SRC = main.c
TEST_FOLDER = tests/
TEST_SRC = $(TEST_FOLDER)maze_tests.c \
		   $(TEST_FOLDER)main_tests.c \
		#    $(TEST_FOLDER)suite_io.c
TARGET = s21_maze
TEST_TARGET = test_maze
BUILD = build
BINDIR = /usr/local/bin
FILES = files/
# DEPS = $(BL_FOLDER)s21_maze_api.h mongoose/mongoose.h $(BL_FOLDER)web_server.h

.PHONY: all install uninstall clean tests web_server

all: $(TARGET)

$(TARGET): $(MAIN_SRC) $(GUI_SRC) $(SRC) 
	$(CC) $(CFLAGS) $(MAIN_SRC) $(SRC) $(GUI_SRC) $(LDFLAGS) -o $(TARGET)

tests: $(TEST_SRC) $(SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(SRC) $(TEST_LIBS) -o $(TEST_TARGET) 
	./$(TEST_TARGET)

install: $(TARGET)
	mkdir -p $(BINDIR)
	cp $(TARGET) $(BINDIR)

uninstall:
	rm -f $(BINDIR)/$(TARGET)

valgrind: tests
	valgrind -s --trace-children=yes  --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TEST_TARGET)

hem:
	$(CC) $(CFLAGS) $(MAIN_SRC) $(GUI_SRC) $(BL_SRC) $(WEB_SERVER_SRC) $(LDFLAGS) -o $(TARGET)
	./$(TARGET) $(FILES)m1.txt

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.o

run: $(TARGET)
	./$(TARGET)