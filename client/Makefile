NAME			= client 
FILES			= client.c
OBJS			= $(FILES:%.c=%.o)
PRINTF			= ../printf

CC				= cc
CFLAGS			= 

all				: $(NAME)

%.o				: %.c
					$(CC) -c $< -o $@

run\:%			:
					./client $(subst run:,,$@)

$(NAME)			: $(OBJS) printf
					$(CC) $(CFLAGS) $(OBJS) -L $(PRINTF) -lftprintf -o $@

clean			: 
					rm -rf $(OBJS)

fclean			:
					rm -rf $(NAME)

re				: fclean all
.PHONY			: clean fclean re all