CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g -I./src
OBJ = my_read_iso.o commands.o command_info.o command_ls.o useful_func.o
OBJ += command_cat.o command_cd.o command_get.o command_tree.o
EXEC = my_read_iso
VPATH = ./src

all: $(OBJ)
	$(CC) -o $(EXEC) $^ $(CFLAGS)

test: all
	./tests/testsuite/create_iso.sh
	cp ./tests/testsuite/commands.txt ./
	cp ./tests/testsuite/expected.txt ./
	cp ./tests/testsuite/output.txt ./
	./tests/testsuite/testsuite.sh ./my_read_iso ./tests/example.iso

clean:
	rm -f $(OBJ) $(EXEC) ./output.txt ./expected.txt ./commands.txt ./tests/example.iso
