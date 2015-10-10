# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroche <vroche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 10:49:38 by vroche            #+#    #+#              #
#    Updated: 2015/10/09 18:03:21 by vroche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

LIB = -ltermcap -L./libft -lft

HDR = -I./libft

FLAGS = -Wall -Wextra -Werror

C =	ft_curs.c \
	ft_display.c \
	ft_init.c \
	ft_list.c \
	ft_manage.c \
	ft_term.c \
	main.c

O = $(C:.c=.o)

all: $(NAME)

$(NAME): $(O)
	make -C ./libft
	gcc $(FLAGS) $(HDR) $(LIB) $(O) -o $(NAME)

%.o:%.c
	gcc $(FLAGS) $(HDR) -c $<

clean:
	make -C ./libft clean
	rm -f $(O)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
