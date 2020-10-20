.PHONY: all libmake hluthor.filler clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./libft -lft
NAME = hluthor.filler
SOURCES = filler.c get_next_line.c init.c hot_map.c free.c move1.c move2.c
OBJECTS = $(subst .c,.o,$(SOURCES))

all: $(NAME)

libmake:
		@(cd libft; make)

$(NAME): libmake $(OBJECTS)
		@$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) -o $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@(cd libft; make clean)
			@rm -rf $(OBJECTS)

fclean: clean
		@(cd libft; make fclean)
			@rm -rf $(NAME)

re: fclean all
