PROGRAM_NAME= megaphone
COMPILER = c++
CPP_VERSION = c++98
FLAGS = -Wall -Wextra -Werror -std=$(CPP_VERSION)
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ)
	$(COMPILER) $(FLAGS) -o $(PROGRAM_NAME) $(OBJ)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re