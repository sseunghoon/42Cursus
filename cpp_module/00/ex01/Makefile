# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 00:37:40 by seunghso          #+#    #+#              #
#    Updated: 2023/03/21 19:07:45 by songseunghu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

SRCS	=	main.cpp PhoneBook.cpp Contact.cpp 
OBJS	=	$(SRCS:%.cpp=%.o)

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all

.PHONY: all clean fclean re
