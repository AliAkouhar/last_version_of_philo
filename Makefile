CC = cc
NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRC = main.c parcing.c philo.c philo2.c
SRC += routine.c get_set.c ft_death.c actions.c
SRC += utils/ft_atol.c utils/time.c 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean : $(OBJ)
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

