NAME 	= 	libftprintf.a

SRC = 	ft_printf.c \
		ft_print_hexa.c \
		ft_print_ptr.c \
		ft_print_utils2.c \
		ft_print_unsigned.c \
		ft_print_utils.c 
		
OBJ = $(SRC:.c=.o)

CC = cc

RM = rm -f 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ)
	ar rcs ${NAME} ${OBJ}

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all
