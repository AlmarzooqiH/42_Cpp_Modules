PROGRAM_NAME = PoliticsIsAss
COMPILER = c++
STD_VERSION = c++98
FLAGS = -std=$(STD_VERSION) -Wall -Wextra -Werror

SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRC:.cpp=.o)

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
