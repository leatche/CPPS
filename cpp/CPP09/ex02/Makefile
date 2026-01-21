# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 12:01:33 by tcherepoff        #+#    #+#              #
#    Updated: 2026/01/14 12:02:32 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	main.cpp PmergeMe.cpp
OBJ		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean

