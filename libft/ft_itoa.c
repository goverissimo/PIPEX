/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:42:30 by gverissi          #+#    #+#             */
/*   Updated: 2023/04/28 14:56:29 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static signed int	ft_count_int(signed long long int n, signed int *sign)
{
	signed int	c;

	c = 0;
	*sign = 0;
	if (n < 0)
	{
		*sign = 1;
		c++;
		n = -n;
	}
	if (n == 0)
	{
		c = 1;
		*sign = -1;
	}
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static void	ft_iterate(char *str, signed int len, signed long long int nb)
{
	while (nb > 0)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
}

char	*ft_itoa(signed int n)
{
	signed int				sign;
	signed long long int	nb;
	signed int				len;
	char					*str;

	nb = n;
	len = ft_count_int(nb, &sign);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (sign && (sign != -1))
	{
		nb = -nb;
		str[0] = '-';
	}
	else if (sign == -1)
		str[0] = '0';
	str[len--] = '\0';
	ft_iterate(str, len, nb);
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("Output -> %s, %s, %s, %s, %s\n", ft_itoa(0), ft_itoa(40)
	, ft_itoa(-45), ft_itoa(-2147483648), ft_itoa(2147483647));
}
*/