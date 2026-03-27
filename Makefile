CC = g++
CFLAGS = -Wall -Wextra -std=c++17
EXEC = output/arena
SRC = main.cpp

all: $(EXEC) run

$(EXEC) : $(SRC)
	mkdir -p output
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -rf output/
