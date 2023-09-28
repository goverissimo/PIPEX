/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:50:34 by gverissi          #+#    #+#             */
/*   Updated: 2023/04/24 10:26:02 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	c;
	size_t	d_len;

	c = 0;
	d_len = ft_strlen(dest);
	if (!n || d_len >= n)
	{
		return (ft_strlen(src) + n);
	}
	while (src[c] && c < (n - d_len - 1))
	{
		dest[d_len + c] = src[c];
		c++;
	}
	dest[d_len + c] = '\0';
	return (ft_strlen(src) + d_len);
}
