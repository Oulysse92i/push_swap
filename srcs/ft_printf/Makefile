# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 15:25:59 by ugaudich          #+#    #+#              #
#    Updated: 2024/12/10 15:39:48 by ugaudich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_printf.c \
ft_print_hex.c \
ft_print_ptr.c \
ft_print_unsigned.c \
ft_printchar.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)	
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $? $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
