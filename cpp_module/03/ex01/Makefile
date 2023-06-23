# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 00:37:40 by seunghso          #+#    #+#              #
#    Updated: 2023/06/23 17:05:19 by seunghso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	FragTrap

SRCS	=	main.cpp ClapTrap.cpp FragTrap.cpp
OBJS	=	$(SRCS:%.cpp=%.o)
HEADER	=	ClapTrap.hpp FragTrap.hpp

CPP		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

%.o	:%.c
	$(CPP) $(CFLAGS) -c $< -o $@ -include $(HEADER)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all

.PHONY: all clean fclean re
