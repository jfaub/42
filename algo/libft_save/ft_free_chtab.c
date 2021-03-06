/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_chtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 12:10:56 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/17 21:28:29 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_chtab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free((void *)tab[i]);
		++i;
	}
	free((void *)tab);
}
