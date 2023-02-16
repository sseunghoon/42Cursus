NAME	=	philo

SRCS_DIR_M	=	src/
SRCS_BASE_M	=	main.c init.c mutex.c thread.c utils.c
OBJS_M		=	$(SRCS_M:%.c=%.o)
SRCS_M		=	$(addprefix $(SRCS_DIR_M), $(SRCS_BASE_M))

SRCS_DIR_B 	=	src_bonus/
SRCS_BASE_B	=	main.c
OBJS_B		=	$(SRCS_B:%.c=%.o)
SRCS_B		=	$(addprefix $(SRCS_DIR_B), $(SRCS_BASE_B))

INC_M	=	include
INC_B	=	include_bonus

ifdef WITH_BONUS
	OBJS	= $(OBJS_B)
	INC		= $(INC_B)
else
	OBJS = $(OBJS_M)
	INC		= $(INC_M)
endif

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) -I $(INC) $(OBJS) -o $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus :
	make WITH_BONUS=1

clean	:
	rm -rf $(OBJS_M)
	rm -rf $(OBJS_B)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all

.PHONY: all bonus clean fclean re
