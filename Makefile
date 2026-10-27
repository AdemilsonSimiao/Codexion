NAME = Codexion
CC = cc -Wall -Wextra -Werror -pthread
SRCS =	src/main.c \
		src/parsing/parse_args.c \
		src/parsing/validation.c \
		src/utils/utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:

fclean:

re:

.PHONY: all clean fclean re