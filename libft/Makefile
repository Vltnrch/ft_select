# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroche <vroche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 17:32:05 by vroche            #+#    #+#              #
#    Updated: 2015/10/09 18:03:29 by vroche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HDR = -I./

CFLAGS = -Wall -Werror -Wextra

C = ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strncpy.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_realloc.c \
	ft_lstadd_back.c \
	ft_list_last.c \
	ft_list_size.c \
	ft_lltoa.c \
	ft_lltouab.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strlen.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strcat.c \
	get_next_line.c \
	ft_ft.c \
	ft_perc.c \
	ft_perc_part1.c \
	ft_perc_part2.c \
	ft_perch.c \
	ft_percopt.c \
	ft_printf.c \
	ft_put_di.c \
	ft_put_ou.c \
	ft_put_x.c \
	ft_put_p.c \
	ft_put_sc.c \
	ft_put_ss.c \
	ft_wctoa.c \
	ft_isspace.c

O = $(C:.c=.o)

$(NAME): $(O)
	ar rc $(NAME) $(O)
	ranlib $(NAME)

all: $(NAME)

%.o:%.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f $(O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
