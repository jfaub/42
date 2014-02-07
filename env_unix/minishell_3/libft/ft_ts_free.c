/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ts_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 12:10:56 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/01 12:07:36 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ts_free(char **ts)
{
	int		i;

	i = 0;
	while (ts[i])
	{
		gofree((void *)ts[i]);
		++i;
	}
	gofree((void *)ts);
}
