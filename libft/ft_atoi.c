/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:17:47 by gverissi          #+#    #+#             */
/*   Updated: 2023/09/23 17:25:59 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_isspace(unsigned int ch)
{
	if (ch == 9 || ch == 10 || ch == 11
		|| ch == 12 || ch == 13 || ch == 32)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	c;
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	c = 0;
	while (ft_isspace(str[c]))
	{
		c++;
	}
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
		{
			sign *= -1;
		}
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = res * 10 + (str[c] - '0');
		c++;
	}
	return ((int)(sign * res));
}
