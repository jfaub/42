/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_for_diag_up_right.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 18:02:44 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/09 21:21:43 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static void		ft_find_start_diag_up_right(t_all a, t_bound *b)
{
	int		k;

	k = 0;
	while (k < 3 && (a.i + k < a.li - 1) && (a.j - k > 0))
		++k;
	(*b).start_li = a.i + k;
	(*b).start_co = a.j - k;
}

static void		ft_find_end_diag_up_right(t_all a, t_bound *b)
{
	int		k;

	k = 0;
	while (k < 3 && ((*b).start_li - k > 0) && ((*b).start_co + k < a.co - 1))
		++k;
	(*b).end_li = (*b).start_li - k;
	(*b).end_co = (*b).start_co + k;
}

static int		ft_space_for_diag_ur(t_all a, t_bound b, t_s s)
{
	int		nb;

	nb = 1;
	while (b.start_li >= b.end_li)
	{
		if (a.grid[b.start_li][b.start_co] == s.symb2)
			return (1);
		if (a.grid[b.start_li][b.start_co] == s.symb1)
			++nb;
		--(b.start_li);
		++(b.start_co);
	}
	return (nb);
}

int				ft_find_nb_for_diag_up_right(t_all a, t_s s)
{
	t_bound		b;
	int			max;
	int			nb;

	max = 0;
	nb = 1;
	ft_find_start_diag_up_right(a, &b);
	while (b.start_li - a.i >= 0)
	{
		ft_find_end_diag_up_right(a, &b);
		if (b.start_li - b.end_li < 3)
			nb = 1;
		else
			nb = ft_space_for_diag_ur(a, b, s);
		if (nb > max)
			max = nb;
		--(b.start_li);
		++(b.start_co);
	}
	return (max);
}
