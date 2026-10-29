NAME = codexion
CC = cc -Wall -Wextra -Werror -pthread
SRCS =	src/main.c \
		src/parsing/parse_args.c \
		src/parsing/validation.c \
		src/utils/utils.c \
		src/utils/time.c \
		src/init/init_data.c \
		src/init/init_dongles.c \
		src/init/init_coders.c \
		src/cleanup.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -I include -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re