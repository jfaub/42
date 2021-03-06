/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:51:48 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/10 11:28:41 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_digit(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	return (i);
}
