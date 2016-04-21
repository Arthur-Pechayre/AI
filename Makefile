CC   =	gcc

NAME =	solve

SRC  =	libmy/isint.c 					\
		libmy/my_abs.c 					\
		libmy/my_getnbr.c 				\
		libmy/my_strcmp.c 				\
		libmy/my_put_nbr.c 				\
		libmy/my_putchar.c 				\
		libmy/my_putstr.c 				\
		libmy/readline.c 				\
		includes/main.c 				\
		includes/copy_game.c 			\
		includes/solve.c 				\
		includes/print.c 				\
		includes/check_params_map.c 	\
		includes/map_manager.c 			\
		includes/error_reporting.c 		\
		includes/error_reporting2.c 	\
		includes/list_manager.c 		\
		includes/list_manager2.c 		\
		includes/init.c

OBJ = $(SRC:%.c=%.o)

RM  = rm -f

CFLAGS = -W -Wall -Wextra -Werror

$(NAME) :	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all