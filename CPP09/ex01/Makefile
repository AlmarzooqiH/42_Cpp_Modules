PROGRAM_NAME=RPN

COMPILER=c++
STD_VERSION=c++98
FLAGS= -std=$(STD_VERSION) -Wall -Wextra -Werror -fsanitize=address
SRC= main.cpp RPN.cpp
OBJS= $(SRC:.cpp=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(PROGRAM_NAME)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re
