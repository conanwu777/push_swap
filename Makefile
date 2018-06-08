NAME1 = push_swap
NAME2 = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC1 = in_out.c p_s.c r_rr.c recur.c lists.c add_on.c push_swap.c 
OBJ1 = $(SRC1:.c=.o)
SRC2 = in_out.c p_s.c r_rr.c lists.c add_on.c cw_support.c cw_display.c
OBJ2 = $(SRC2:.c=.o)

FT_LNK = -L ./libft -lft

all:
	$(CC) $(CFLAGS) $(FT_LNK) $(SRC1) -o $(NAME1)
	$(CC) $(CFLAGS) $(FT_LNK) $(SRC2) -o $(NAME2)

clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re:	fclean all
