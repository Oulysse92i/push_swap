# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 15:01:36 by ugaudich          #+#    #+#              #
#    Updated: 2024/12/10 15:40:05 by ugaudich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = srcs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRC = srcs/check_input.c \
srcs/init_stacks.c \
srcs/pa_pb.c \
srcs/push_swap.c \
srcs/ra_rb_rr.c \
srcs/rra_rrb_rrr.c \
srcs/sa_sb_ss.c \
srcs/sort_big.c \
srcs/sort_small.c \
srcs/utils.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/includes -c $< -o $@

$(NAME): $(OBJ)	$(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re:	fclean $(NAME)

.PHONY: all clean fclean re
