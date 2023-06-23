# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 00:37:40 by seunghso          #+#    #+#              #
#    Updated: 2023/06/22 16:32:31 by songseunghu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out

SRCS	=	main.cpp Fixed.cpp
OBJS	=	$(SRCS:%.cpp=%.o)
HEADER	=	Fixed.hpp

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
