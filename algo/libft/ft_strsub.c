/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 13:06:50 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/22 17:23:04 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (!(str = (char *)gmalloc(sizeof(*str) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(str + i) = *(s + start);
		++i;
		++start;
	}
	*(str + i) = '\0';
	return (str);
}
