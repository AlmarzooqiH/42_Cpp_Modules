PROGRAM_NAME= i_want_problems_always
COMPILER = c++
CPP_VERSION = c++98
FLAGS = -Wall -Wextra -Werror -std=$(CPP_VERSION)
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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