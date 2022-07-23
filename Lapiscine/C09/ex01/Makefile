CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
TARGET = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
INC = includes

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar -rcsv $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $< -I $(INC) -o $@
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(TARGET)
re : fclean all

.PHONY : all clean fclean re
