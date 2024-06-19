#include "client.h"

void	ft_show_bit(char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		ft_printf("%d", (c >> i) % 2);
	}
}

void	ft_send_signal(int pid, unsigned char c)
{
	int	i;
	unsigned char	tmp;

	i = 8;
	tmp = 0;
	while (i)
	{
		i--;
		tmp |= ((c >> i) % 2);
		if (((c >> i) % 2) == 1)
			kill(pid, SIGUSR1);
		if (((c >> i) % 2) == 0)
			kill(pid, SIGUSR2);
		if (i != 0)
			tmp <<= 1;
		usleep(1);
	}
	ft_show_bit(tmp);
	ft_printf("\nGOT	: [%c]\n", tmp);
}

int main(int argc, char **argv)
{
	char	*mess;

	mess = argv[2];
	ft_printf("MESS	: [%s]\n", mess);
	while (*mess)
	{
		// ft_printf("value	: %c\n", *mess);
		ft_send_signal(ft_atoi(argv[1]), *mess);
		mess++;
	}
	return (0);
}
