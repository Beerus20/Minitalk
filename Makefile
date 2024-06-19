NAME_1	= server 
NAME_2	= client 

ARGS	?= 123

PRINTF			= ./printf
SERVER_FILES	= server.c
CLIENT_FILES	= client.c

LIB_PRINTF		= libftprintf.a
SERVER_OBJS		= $(SERVER_FILES:%.c=%.o)
CLIENT_OBJS		= $(CLIENT_FILES:%.c=%.o)

CC				= cc
CFLAGS			= 

all				: $(NAME_1) $(NAME_2)

%.o				: %.c
					$(CC) -c $< -o $@

run_server			:
						./$(NAME_1)

run_client\:%		:
						./client $(subst run_client:,,$@)

printf				:
						make -C $(PRINFT)

$(NAME_1)			: $(SERVER_OBJS) printf
						$(CC) $(CFLAGS) $(SERVER_OBJS) -I $(PRINTF) -L $(PRINTF) -lftprintf -o $@

$(NAME_2)			: $(CLIENT_OBJS) printf
						$(CC) $(CFLAGS) $(CLIENT_OBJS) -I $(PRINTF) -L $(PRINTF) -lftprintf -o $@

clean			: 
					rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

fclean			:
					rm -rf $(NAME_1) $(NAME_2)


re				: fclean all
.PHONY			: clean fclean re all