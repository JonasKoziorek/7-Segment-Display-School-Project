CC = gcc
CFLAGS = -fsanitize=address -g
NAME = program

$(NAME): main.c
	$(CC) $(CFLAGS) main.c Number.c Frame.c -o $(NAME)

