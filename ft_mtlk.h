/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtlk.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:25:37 by ballain           #+#    #+#             */
/*   Updated: 2024/06/20 15:25:38 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MTLK_H
# define FT_MTLK_H

# include <stdlib.h>

typedef struct s_mess
{
	unsigned char	content;
	struct s_mess	*next;
}	t_mess;

int		ft_atoi(const char *nptr);
t_mess	*ft_lstnew(unsigned char content);
void	ft_lstadd_back(t_mess **lst, t_mess *new);
#endif