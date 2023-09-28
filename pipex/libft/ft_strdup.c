/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:36:33 by gverissi          #+#    #+#             */
/*   Updated: 2023/04/26 14:59:40 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	signed int	c;
	char		*cpy;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	cpy = (char *)malloc(sizeof(char) * (c + 1));
	c = 0;
	if (!cpy)
		return (0);
	while (str[c] != '\0')
	{
		cpy[c] = str[c];
		c++;
	}
	cpy[c] = '\0';
	return (cpy);
}
