# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 00:37:40 by seunghso          #+#    #+#              #
#    Updated: 2023/08/28 12:53:12 by songseunghu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe

SRCS	=	main.cpp PmergeMe.cpp
OBJS	=	$(SRCS:%.cpp=%.o)

CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -fsanitize=address

all		:	$(NAME)

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
