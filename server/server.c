#include "server.h"

void	ft_show_bit(char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		ft_printf("%d", (c >> i) % 2);
	}
	ft_printf("\n");
}

void	ft_recept_signal(int signal)
{
	static unsigned char	c = 0;
	static int				i = 8;

	c |= (signal == SIGUSR1);
	if (--i == 0)
	{
		ft_printf("%c", c);
		i = 8;
		c = 0;
	}
	else
		c <<= 1;
}

int main(int argc, char **argv)
{
	printf("PID	: [%d]\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_recept_signal);
		signal(SIGUSR2, ft_recept_signal);
		usleep(1);
	}
	return (0);
}
