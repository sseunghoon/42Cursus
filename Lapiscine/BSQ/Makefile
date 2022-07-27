# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 18:53:42 by seunghso          #+#    #+#              #
#    Updated: 2022/06/07 16:45:35 by seunghso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CFLAGS = -I$(INCLUDES_DIR) -Wall -Wextra -Werror
RM = rm -f

NAME = bsq
HEADER_BASE = bsq.h
SOURCE_BASE = app.c lines.c map.c ctor.c dtor.c exts.c ft_util.c
INCLUDES_DIR = ./includes/
SRCS_DIR = ./srcs/
INCS = $(addprefix $(INCLUDES_DIR), $(HEADER_BASE))
SRCS = $(addprefix $(SRCS_DIR), $(SOURCE_BASE))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): $(INCS)

