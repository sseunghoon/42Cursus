# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 00:37:40 by seunghso          #+#    #+#              #
#    Updated: 2023/08/23 10:31:25 by seunghso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	whatever

SRCS	=	main.cpp
OBJS	=	$(SRCS:%.cpp=%.o)

CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

all		:	$(NAME)
	$(info Build Success)

$(NAME)	:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o	:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean
	@make all

.PHONY: all clean fclean re
