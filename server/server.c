/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:25:26 by ballain           #+#    #+#             */
/*   Updated: 2024/06/20 15:26:21 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_lstclear(t_mess **lst)
{
	t_mess	*tmp;
	t_mess	*to_free;

	if (!(*lst))
		return ;
	tmp = (*lst)->next;
	to_free = NULL;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free);
	}
	free(*lst);
	*lst = NULL;
}

void	ft_show_mess(t_mess **list)
{
	t_mess	*tmp;

	tmp = *list;
	while (tmp)
	{
		ft_printf("%c", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_recept_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 8;
	static t_mess			*mess = NULL;

	c |= (signal == SIGUSR1);
	if (--i == 0)
	{
		ft_lstadd_back(&mess, ft_lstnew(c));
		if (c == 0)
		{
			ft_show_mess(&mess);
			ft_lstclear(&mess);
			kill(info->si_pid, SIGUSR1);
		}
		i = 8;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	action.sa_sigaction = ft_recept_signal;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	ft_printf("PID	: [%d]\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
	}
	return (0);
}
