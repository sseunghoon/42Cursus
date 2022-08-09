# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 13:49:39 by seunghso          #+#    #+#              #
#    Updated: 2022/08/09 22:08:01 by seunghso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS_DIR_M	=	src/
SRCS_BASE_M	=	push_swap.c utils.c greedy.c command.c command2.c etc.c parse.c
OBJS_M		=	$(SRCS_M:%.c=%.o)
SRCS_M		=	$(addprefix $(SRCS_DIR_M), $(SRCS_BASE_M))

SRCS_DIR_B 	=	src_bonus/
SRCS_BASE_B	=	push_swap.c utils.c greedy.c command.c command2.c etc.c parse.c
OBJS_B		=	$(SRCS_B:%.c=%.o)
SRCS_B		=	$(addprefix $(SRCS_DIR_B), $(SRCS_BASE_B))

INC_M	=	include
INC_B	=	include_bonus

ifdef WITH_BONUS
	OBJS	= $(OBJS_B)
	INC		= $(INC_M)
else
	OBJS = $(OBJS_M)
	INC		= $(INC_B)
endif

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Llibft -l_seunghso
LIBFT	=	libft
MLX		=	mlx

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(CLIB) -I $(INC) $(OBJS) -o $(NAME) -fsanitize=address

%.o	:%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus :
	make WITH_BONUS=1

clean	:
	rm -rf $(OBJS_M)
	rm -rf $(OBJS_B)
	make -C $(LIBFT) clean

fclean	: clean
	rm -rf	$(NAME)
	make -C $(LIBFT) fclean

re		: fclean all

.PHONY: all bonus clean fclean re
