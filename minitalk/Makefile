# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 13:49:39 by seunghso          #+#    #+#              #
#    Updated: 2022/07/29 12:23:28 by seunghso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk

CLIENT	=	mnt_client
SERVER	=	mnt_server

all		:	$(NAME)

$(NAME)	:
	make -C $(CLIENT)
	make -C $(SERVER)

bonus :
	make -C $(CLIENT) bonus
	make -C $(SERVER) bonus

clean	:
	make -C $(CLIENT) clean
	make -C $(SERVER) clean

fclean	: clean
	rm -rf	client server
	make -C $(CLIENT) fclean
	make -C $(SERVER) fclean

re		: fclean all

.PHONY: all bonus clean fclean re
