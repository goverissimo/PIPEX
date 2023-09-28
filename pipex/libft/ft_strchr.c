/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:35:43 by gverissi          #+#    #+#             */
/*   Updated: 2023/04/24 10:25:09 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, unsigned char ch)
{
	unsigned int	c;

	c = 0;
	while (str[c] != ch && str[c] != '\0')
	{
		c++;
	}
	if (str[c] == (char)ch)
	{
		return ((char *)&str[c]);
	}
	return (NULL);
}
