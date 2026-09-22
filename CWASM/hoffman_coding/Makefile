# main: main.c frequency.c sort.c tree.c assign_num.c compress.c
# 	gcc main.c frequency.c sort.c tree.c assign_num.c compress.c -o main
# debug: main.c frequency.c sort.c tree.c assign_num.c compress.c
# 	gcc main.c frequency.c sort.c tree.CC = gcc
CFLAGS = -Iinclude

SRC = src/main.c src/frequency.c src/sort.c src/tree.c src/assign_num.c src/compress.c
TARGET = C_build/main

$(TARGET): $(SRC)
	@mkdir -p C_build
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf C_buildc assign_num.c compress.c -g3 -Og -Wall -Wextra -fsanitize=address,undefined -o main
