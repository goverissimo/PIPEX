/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:52:34 by gverissi          #+#    #+#             */
/*   Updated: 2023/04/19 16:29:07 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *str, size_t n)
{
	size_t	c;
	size_t	w;
	size_t	e;

	c = 0;
	w = 0;
	e = 0;
	while (str[e])
		e++;
	if (e == 0)
		return ((char *)big);
	while (big[c] && c < n)
	{
		while (big[c + w] == str[w] && (c + w) < n)
		{
			if (str[w + 1] == '\0')
			{
				return ((char *)&big[c]);
			}
			w++;
		}
		w = 0;
		c++;
	}
	return (NULL);
}
