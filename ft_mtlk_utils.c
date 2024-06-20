/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtlk_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:25:32 by ballain           #+#    #+#             */
/*   Updated: 2024/06/20 15:25:32 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mtlk.h"

static int	ft_isspace(const int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr != '\0')
	{
		if (!ft_isdigit(*nptr))
			break ;
		result = result * 10 + (*nptr - 48);
		nptr++;
	}
	return (sign * result);
}

t_mess	*ft_lstnew(unsigned char content)
{
	t_mess	*r_value;

	r_value = (t_mess *)malloc(sizeof(t_mess));
	if (!r_value)
		return (0);
	r_value->content = content;
	r_value->next = NULL;
	return (r_value);
}

void	ft_lstadd_back(t_mess **lst, t_mess *new)
{
	t_mess	*tmp;

	tmp = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
