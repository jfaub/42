/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:01:51 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/10 19:51:21 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_read(char *buf, int fd, int ret)
{
	ret = read(fd, buf, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	buf[ret] = '\0';
	return (ret);
}

static int		ft_is_new_line(char **line, char *buf, int i)
{
		ft_strncat(*line, buf, i);
		ft_strcpy(buf, ft_strsub(buf, i + 1, BUFF_SIZE - i - 1));
		return (1);
}

static int		ft_no_new_line(char **line, char *buf)
{
	static int		j;
	char			*tmp;

	j++;
	tmp = (char *)malloc(sizeof(*tmp) * BUFF_SIZE * j + 1);
	if (tmp == NULL)
		return (-1);
	ft_strclr(tmp);
	ft_strcpy(tmp, *line);
	free((void *)*line);
	*line = (char *)malloc(sizeof(**line) * BUFF_SIZE * (j + 1) + 1);
	if (*line == NULL)
		return (-1);
	ft_strclr(*line);
	ft_strcpy(*line, tmp);
	free((void *)tmp);
	ft_strcat(*line, buf);
	buf[0] = '\0';
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	static char		buf[BUFF_SIZE + 1];
	int				i;

	if (!(*line = (char *)malloc(sizeof(**line) * (BUFF_SIZE + 1))))
			return (-1);
	ft_strclr(*line);
	ret = 1;
	while (ret > 0)
	{
		if (buf[0] == '\0')
		{
			if (!(ret = ft_read(buf, fd, ret)) && *line[0] != '\0')
				return (1);
		}
		i = 0;
		while (buf[i] && buf[i] != '\n' && ret > 0)
			i++;
		if (buf[i] == '\n' && ret > 0)
			return (ft_is_new_line(line, buf, i));
		else if (ret > 0 &&	ft_no_new_line(line, buf) != 1)
			return (-1);
	}
	return (ret);
}
