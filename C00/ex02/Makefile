PROGRAM_NAME= money
COMPILER = cc
CPP_VERSION = c++98
FLAGS = -Wall -Wextra -Werror -std=$(CPP_VERSION)
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ)
	$(COMPILER) $(FLAGS) -o $(PROGRAM_NAME) $(OBJ) -lstdc++

clean:
	rm -rf *.o *.out *.gch .vscode *.txt *.log

fclean: clean
	rm -rf $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re