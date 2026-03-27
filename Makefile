CC      = g++
CFLAGS  = -Wall -Wextra -std=c++17
EXEC    = output/arena

# 1. On liste les sources et on calcule les objets
SRC     = main.cpp $(wildcard src/*.cpp)
OBJ     = $(SRC:.cpp=.o)

# 2. Règle par
all: $(EXEC)

# 3. L'édition de liens : on utilise $(OBJ)
$(EXEC) : $(OBJ)
	mkdir -p output
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

# 4. La compilation individuelle : transforme .cpp en .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# 5. Utilitaires
run: $(EXEC)
	./$(EXEC)

clean:
	rm -rf output/
	rm -f src/*.o
	rm -f *.o