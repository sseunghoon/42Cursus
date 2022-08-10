# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 13:49:39 by seunghso          #+#    #+#              #
#    Updated: 2022/08/10 20:17:24 by seunghso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ps

PUSH_SWAP	=	ps_push_swap
CHECKER		=	ps_checker

all		:	$(NAME)

$(NAME)	:
	make -C $(PUSH_SWAP)

bonus	:
	make -C $(PUSH_SWAP)
	make -C $(CHECKER)

clean	:
	make -C $(PUSH_SWAP) clean
	make -C $(CHECKER) clean

fclean	: clean
	rm -rf	push_swap checker
	make -C $(PUSH_SWAP) fclean
	make -C $(CHECKER) fclean

re		: fclean all

.PHONY: all bonus clean fclean re
