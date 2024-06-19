NAME			= client

FILES			= client.c
OBJS			= $(FILES:%.c=%.o)

FUNCTIONS		= ../ft_mtlk_utils.o
PRINTF			= ../printf

CC				= cc
CFLAGS			=

all				: $(NAME)

%.o				: %.c
					$(CC) -c $< -o $@

$(NAME)			: $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(FUNCTIONS) -L $(PRINTF) -lftprintf -o $@

clean			:
					rm -rf $(OBJS)

fclean			: clean
					rm -rf $(NAME)

re				: fclean all
.PHONY			: clean fclean re all