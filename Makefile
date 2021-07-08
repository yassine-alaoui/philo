SRC =	main.c checkargs.c helperfuncs.c starterfuncs.c philofuncs.c

NAME = lib.a

EXC = philo

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME) : $(OBJ)
	@gcc $(FLAGS) -c $(SRC)
	@ar -rc $(NAME) $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(EXC)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME) $(EXC)

re:		fclean all