NAME = harlFilter
SOURCE = Harl.cpp main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
SANITIZE = -fsanitize=address
CC = c++

all: $(NAME)

$(NAME): $(SOURCE)
	$(CC) $(FLAGS) $^ -o $@

debug: $(SOURCE)
	$(CC) $(SANITIZE) $(FLAGS) $^ -o $@

fclean:
	rm -f $(NAME)

re: fclean all
