NAME = a.out
SOURCE = Garbage.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
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
