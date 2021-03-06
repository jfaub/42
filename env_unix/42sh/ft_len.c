/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:04:02 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:08:21 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_slist_len(t_sl *list)
{
	int		i;
	t_sl	*move;

	move = list;
	i = 0;
	while (move)
	{
		++i;
		move = move->next;
	}
	return (i);
}

int			ft_hlist_len(t_hl *hlist)
{
	int		i;
	t_hl	*move;

	move = hlist;
	i = 0;
	while (move)
	{
		++i;
		move = move->next;
	}
	return (i);
}
