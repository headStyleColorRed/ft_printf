NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

SRC =		ft_printf.c \
			checkers.c \
			funciones/ft_itoa.c \
			funciones/extras.c \
			machines.c \
			funciones/ft_atoi.c \
			printers_1.c \
			globals.c \
			global_get_set.c \
			modifiers_handler.c \
			flag_handlers.c \
			funciones/ft_u_itoa.c \
			funciones/prehandlers.c \
			funciones/ft_putnbr_base.c \

OBJ = $(SRC:%.c=%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -c $(FLAG) $(SRC)
	@ar -rcv $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *.o *.out *.gch

fclean: clean
	$(RM) $(NAME)
	$(RM) *.o *.out *.gch

re: fclean all

.PHONY: clean fclean all re