NAME			= client

FILES			= client.c
OBJS			= $(FILES:%.c=%.o)

FUNCTIONS		= ../ft_mtlk_utils.o
PRINTF			= ../printf

BONUS 			= 0

CC				= cc -g
CFLAGS			=

all				: $(NAME)

%.o				: %.c
					@if [ $(BONUS) = 0 ]; then\
						$(CC) -c $< -o $@; \
					else \
						$(CC) -c $< -D ACTIVATE_BONUS=1 -o $@; \
					fi


$(NAME)			: override BONUS=0
$(NAME)			: $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(FUNCTIONS) -L $(PRINTF) -lftprintf -o $@

clean			:
					rm -rf $(OBJS)

bonus			: override BONUS=1
bonus			: $(OBJS) 
					$(CC) $(CFLAGS) $(OBJS) $(FUNCTIONS) -L $(PRINTF) -lftprintf -o $(NAME)	

fclean			: clean
					rm -rf $(NAME)

re				: fclean all
.PHONY			: clean fclean re all