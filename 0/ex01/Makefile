NAME = phonkbutt
SOURCE = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SOURCE:.c=.o)
HEADERS = Contact.hpp PhoneBook.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -IContact.hpp -IPhoneBook.hpp $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -IContact.hpp -IPhoneBook.hpp -c $(<) -o $(@)
