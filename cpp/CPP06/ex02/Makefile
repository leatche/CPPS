# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/23 11:00:50 by tcherepoff        #+#    #+#              #
#    Updated: 2025/12/09 18:44:13 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Identify

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	main.cpp A.cpp B.cpp C.cpp Base.cpp
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
