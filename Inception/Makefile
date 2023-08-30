# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 14:45:44 by seunghso          #+#    #+#              #
#    Updated: 2023/08/30 14:45:56 by seunghso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Inception

SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:%.cpp=%.o)

CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o	:%.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all

.PHONY: all clean fclean re
