/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:28:57 by jaubert           #+#    #+#             */
/*   Updated: 2013/11/27 18:30:47 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s++)
	{
		if (*(s - 1) == c)
			return ((char *)(s - 1));
	}
	if (c == '\0')
		return ((char *)(s - 1));
	return (NULL);
}
