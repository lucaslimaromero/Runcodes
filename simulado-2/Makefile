APPS =./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libed myapps

libed:
	gcc -c $(SRC)/tree.c -I $(INCLUDE) -o $(OBJ)/tree.o

myapps:
	gcc $(APPS)/app.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

run:
	$(BIN)/app

clean:
	rm $(BIN)/* $(OBJ)/*