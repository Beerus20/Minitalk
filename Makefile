NAME	= minitalk

PID		?= ""
MESS	?= ""

PRINTF			= ./printf
FILES			= ft_mtlk_utils.c
OBJS			= $(FILES:%.c=%.o)

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

all				: $(NAME)

run\:%			:
					@if [ "$(subst run:,,$@)" = "server" ]; then \
						gnome-terminal & \
					fi
					./$(subst run:,,$@)/$(subst run:,,$@) $(PID) $(MESS)

printf			:
					make -C $(PRINFT)

%.o				: %.c
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME)			: $(OBJS) printf
					make -C ./server
					make -C ./client

clean			:
					make clean -C $(PRINFT)
					make clean -C ./server
					make clean -C ./client

fclean			:
					make fclean -C $(PRINTF)
					make fclean -C ./server
					make fclean -C ./client

re				: fclean all
.PHONY			: clean fclean re all $(NAME)