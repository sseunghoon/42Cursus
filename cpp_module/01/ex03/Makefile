# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 00:37:40 by seunghso          #+#    #+#              #
#    Updated: 2023/03/22 01:32:22 by songseunghu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	UnnecessaryViolence

SRCS	=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS	=	$(SRCS:%.cpp=%.o)
HEADER	=	Weapon.hpp HumanA.hpp HumanB.hpp

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
