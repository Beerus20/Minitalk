NAME			= server

FILES			= server.c
OBJS			= $(FILES:%.c=%.o)
PRINTF			= ../printf
FUNCTIONS		= ../ft_mtlk_utils.o

CC				= cc -g
CFLAGS			=

all				: $(NAME)

%.o				: %.c
					$(CC) -c $< -o $@

$(NAME)			: $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(FUNCTIONS) -L $(PRINTF) -lftprintf -o $@

bonus			: $(NAME)

clean			:
					rm -rf $(OBJS)

fclean			: clean
					rm -rf $(NAME)

re				: fclean all
.PHONY			: clean fclean re all