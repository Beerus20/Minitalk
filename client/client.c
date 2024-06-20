/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:25:07 by ballain           #+#    #+#             */
/*   Updated: 2024/06/20 15:32:27 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_show_bit(char c)
{
	int	i;

	i = 8;
	while (i--)
		ft_printf("%d", (c >> i) % 2);
}

void	ft_recept(int signal)
{
	if (ACTIVATE_BONUS)
		ft_printf("Message received ...\n");
}

void	ft_send_signal(int pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	tmp = 0;
	signal(SIGUSR1, ft_recept);
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
}

int	main(int argc, char **argv)
{
	while (*argv[2])
	{
		ft_send_signal(ft_atoi(argv[1]), *argv[2]);
		argv[2]++;
	}
	ft_send_signal(ft_atoi(argv[1]), '\0');
	return (0);
}
