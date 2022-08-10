# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 13:49:39 by seunghso          #+#    #+#              #
#    Updated: 2022/08/10 17:57:01 by seunghso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker

SRCS_DIR	=	src/
SRCS_BASE	=	push_swap.c utils.c command.c command2.c parse.c
OBJS		=	$(SRCS:%.c=%.o)
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_BASE))

INC	=	include

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Llibft -l_seunghso
LIBFT	=	libft

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(CLIB) -I $(INC) $(OBJS) -o $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean	: clean
	rm -rf	$(NAME)
	make -C $(LIBFT) fclean

re		: fclean all

.PHONY: all bonus clean fclean re
