NAME = libft.a
SHELL = bash

CC = cc
CFLAG = -Wall -Wextra -Werror

RM = rm -f

AR = ar
ARFLAGS = crs

SRCS_1 = ft_strlen.c	\
		 ft_strlcpy.c	\
	 	 ft_strlcat.c	\
 		 ft_strchr.c	\
 		 ft_strnstr.c	\
 		 ft_strncmp.c	\
	 	 ft_strdup.c	\
		 ft_strndup.c	\
		 ft_strrchr.c	\
	 	 ft_memset.c	\
 		 ft_memcpy.c	\
 		 ft_memmove.c	\
 		 ft_memchr.c	\
 		 ft_memcmp.c	\
 		 ft_bzero.c		\
 		 ft_atoi.c		\
		 ft_calloc.c	\
	 	 ft_isalnum.c	\
		 ft_isalpha.c	\
 		 ft_isascii.c	\
 		 ft_isdigit.c	\
		 ft_isprint.c	\
	 	 ft_strdup.c	\
 		 ft_tolower.c	\
 		 ft_toupper.c	\
			
SRCS_2 = ft_substr.c	\
	 	 ft_strjoin.c	\
 		 ft_strtrim.c	\
 		 ft_split.c		\
 		 ft_strmapi.c	\
		 ft_striteri.c	\
 		 ft_itoa.c		\
 		 ft_putchar_fd.c\
 		 ft_putstr_fd.c	\
 		 ft_putendl_fd.c\
 		 ft_putnbr_fd.c	\
		 get_next_line.c\

SRCS = $(SRCS_1) \
		$(SRCS_2) \

OBJS_SRC = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_SRC)
	@./make_libft.sh
	@$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@

clean :
	@$(RM) $(RMFLAG) $(OBJS_SRC)

fclean : clean
	@$(RM) $(RMFLAG) $(NAME)

re : fclean all

.PHONY : all clean fclean re
