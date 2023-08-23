# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 15:06:58 by seunghso          #+#    #+#              #
#    Updated: 2023/08/23 12:31:09 by songseunghu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	easyfind

SRCS	=	main.cpp
OBJS	=	$(SRCS:%.cpp=%.o)
HEADER	=	easyfind.hpp 

CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o	:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -include $(HEADER)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all

.PHONY: all clean fclean re
