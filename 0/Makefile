NAME = learn
SOURCE = learning.cpp
OBJ = $(SOURCE:.c=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -I$(DIR_LIBFT) -c $(<) -o $(@)

