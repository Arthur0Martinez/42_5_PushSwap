# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 08:06:32 by artmarti          #+#    #+#              #
#    Updated: 2023/07/04 10:24:14 by artmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALLFILES = push_swap.c utils.c instructions.c error.c radix.c ft_split.c ft_split2.c very_and_short_list.c others.c

OBJECTS = $(ALLFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
