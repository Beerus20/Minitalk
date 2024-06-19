#include "server.h"

// void	ft_print_bit(unsigned char c)
// {
//     int	i;

//     i = 0;
//     printf("\n==========================================\n");
//     while (i < 8)
//     {
//         printf("bit : [%d]\n", (c >> i) % 2);
//         i++;
//     }
//     printf("\n==========================================\n");
// }

// void    nothing()
// {
// 	int				i;
// 	unsigned char	str;
// 	unsigned char	test;

// 	i = 8;
// 	str = 'a';
// 	test = 0;
// 	while (i--)
// 	{
// 		test |= ((str >> i) % 2);
// 		printf("VALUE (%d)  : [%d]\n", i, (str >> i) % 2);
// 		if (i != 0)
// 			test <<= 1;
// 	}
// 	// test >>= 1;
// 	ft_print_bit(test);
// 	printf("\nRESULT  : [%c]\n\n", test);
// }

void	ft_signal(int signal)
{
	// printf("test");
	// if (signal == SIGINT)
	// 	printf("SIGINT active");
	if (signal == SIGUSR1)
		ft_printf("test\n");
	if (signal == SIGUSR2)
		write(1, "test2", 5);
	// if (signal == SIGUSR2)
	// 	printf("SIGUSR1 active");
}
 
int main(int argc, char **argv)
{
	printf("PID	: [%d]\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
		sleep(1);
	}
	return (0);
}
