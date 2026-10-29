NAME = codexion
CC = cc -Wall -Wextra -Werror -pthread
SRCS =	src/main.c \
		src/parsing/parse_args.c \
		src/parsing/validation.c \
		src/utils/utils.c \
		src/utils/time.c \
		src/utils/logger.c \
		src/init/init_data.c \
		src/init/init_dongles.c \
		src/init/init_coders.c \
		src/simulation/simulation.c \
		src/coder/coder_routine.c \
		src/coder/actions.c \
		src/dongle/drop.c \
		src/dongle/take.c \
		src/monitor/monitor_routine.c \
		src/monitor/checks.c \
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