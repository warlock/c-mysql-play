CC = gcc
SRC = src
FLAGS = `mysql_config --cflags --libs`
all: clean game
game:
	@echo "Build project"
	@$(CC) -o $@ $(SRC)/game.c $(FLAGS)
	@echo "End build"
clean:
	@echo "Clean project"
	@rm -f *.o game