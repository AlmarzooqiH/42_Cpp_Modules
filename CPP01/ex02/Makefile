PROGRAM_NAME= high_on_pointers
COMPILER = c++
CPP_VERSION = c++98
FLAGS = -std=$(CPP_VERSION) -Wall -Wextra -Werror
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ)
	$(COMPILER) $(FLAGS) -o $(PROGRAM_NAME) $(OBJ)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o *.out *.gch .vscode *.txt

fclean: clean
	rm -rf $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re