# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 18:53:42 by seunghso          #+#    #+#              #
#    Updated: 2022/07/15 16:09:23 by seunghso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -c -Wall -Wextra -Werror
RM = rm -f

NAME = libftprintf.a
INC = libftprintf.h
SRCS_M = ft_printf.c ft_init_get.c ft_printf_detail.c ft_printf_utils.c
SRCS_B = ft_printf_bonus.c ft_init_get_bonus.c ft_printf_detail_bonus.c ft_printf_utils_bonus.c
OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	OBJS = $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

LIBFT = libft
LIBFT_LIB = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar -rcsv $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $< -I $(INC) -o $@

bonus :
	make WITH_BONUS=1

clean:
	$(RM) $(OBJS_M) $(OBJS_B)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean bonus fclean re bonus
