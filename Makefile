NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

SRC =		ft_printf.c \
			checkers.c \
			ft_itoa.c \
			extras.c \
			machines.c \
			ft_atoi.c \
			printers_1.c \
			modifiers_handler.c \
			ft_u_itoa.c \
			ft_putnbr_base.c \

OBJ = $(SRC:%.c=%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -c $(FLAG) $(OPTION) $(SRC)
	@ar -rcv $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re