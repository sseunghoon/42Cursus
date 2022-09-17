CC = cc
CFLAGS = -Wall -Wextra -Werror
# LINKING_FLAGS = -L/Users/yehyun/.brew/opt/readline/lib -lreadline
# COMFILE_FLAGS = -I/Users/yehyun/.brew/opt/readline/include/
LINKING_FLAGS = -L/opt/homebrew/Cellar/readline/8.1.2/lib -lreadline #키한
COMFILE_FLAGS = -I/opt/homebrew/Cellar/readline/8.1.2/include/

SHELL = bash

RM = rm -f

PARSER_DIR = parser
UTILS_DIR = utils
EXPAND_DIR = expand
EXCUTE_DIR = excute

SRCS =	minishell.c \
		signal.c \
		init.c \
		$(PARSER_DIR)/lexer.c \
		$(PARSER_DIR)/tokenize.c \
		$(PARSER_DIR)/input_check.c \
		$(PARSER_DIR)/syntax.c \
		$(PARSER_DIR)/syntax_table.c \
		$(UTILS_DIR)/doubly_list.c \
		$(UTILS_DIR)/tree.c \
		$(UTILS_DIR)/utils.c \
		$(UTILS_DIR)/utils2.c \
		$(EXPAND_DIR)/expand.c \
		$(EXPAND_DIR)/shell_var.c \
		$(EXPAND_DIR)/wild_card.c \
		$(EXPAND_DIR)/wild_card_utils.c \
		$(EXCUTE_DIR)/built_in.c \
		$(EXCUTE_DIR)/environ.c \
		$(EXCUTE_DIR)/cd.c \
		$(EXCUTE_DIR)/excute_redir.c \
		$(EXCUTE_DIR)/excute_redir_inout.c \
		$(EXCUTE_DIR)/excute_word.c \
		$(EXCUTE_DIR)/excute_pipe.c \
		$(EXCUTE_DIR)/excute_heredoc.c \
		$(EXCUTE_DIR)/excute.c \

OBJS = $(SRCS:%.c=%.o)

NAME = minishell

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libft
	@./make.sh
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LINKING_FLAGS) $(COMFILE_FLAGS) ./libft/libft.a

%.o : %.c
	@$(CC) $(COMFILE_FLAGS) -c $< -o $@

bonus :
	@make all

clean :
	@make -C ./libft fclean
	@$(RM) $(OBJS)

fclean :
	@make -C ./libft fclean
	@$(RM) $(OBJS) $(NAME)

re :
	@make fclean
	@make all

run :
	@cat ascii_art/sun
	@make re
	@make clean
	@exec ./minishell

.PHONY : all bonus clean fclean re
