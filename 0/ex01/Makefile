NAME = phonkbutt
SOURCE = Contact.cpp PhoneBook.cpp main.cpp
OBJ = $(SOURCE:.c=.o)
# HEADERS = Contact.hpp PhoneBook.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

all: $(NAME)

$(NAME): $(SOURCE)
	$(CC) $(FLAGS) $^ -o $@

# %.o: %.c
# 	$(CC) $(FLAGS) -IContact.hpp -IPhoneBook.hpp -c $(<) -o $(@)
