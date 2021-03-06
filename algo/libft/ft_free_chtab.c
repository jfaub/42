/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_chtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 12:10:56 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/22 17:05:53 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_chtab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		gofree((void *)tab[i]);
		++i;
	}
	gofree((void *)tab);
}
