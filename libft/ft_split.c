/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:26:56 by gverissi          #+#    #+#             */
/*   Updated: 2023/05/02 12:23:23 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char ch)
{
	int	c;
	int	w;

	c = 0;
	w = 0;
	if (ch == '\0')
		return (1);
	while (s[c] != '\0')
	{
		while (s[c] == ch)
			c++;
		if (s[c] != '\0')
			w++;
		while (s[c] != ch && s[c])
			c++;
	}
	return (w);
}

static char	*ft_wrdup(char const *s, char ch, char **strs)
{
	int		c;
	char	*str;

	c = 0;
	while (s[c] != ch && s[c] != '\0')
		c++;
	str = (char *)malloc((c + 1) * sizeof(char));
	if (!str)
		return (NULL);
	c = 0;
	while (s[c] != ch && s[c] != '\0')
	{
		str[c] = s[c];
		c++;
	}
	str[c] = '\0';
	*strs = str;
	return ((char *)s + c);
}

static void	clean_mem(char **strs)
{
	while (strs-- != 0)
		free(*strs);
}

char	**ft_split(char const *s, char ch)
{
	char	**strz;
	char	**strs;

	strs = (char **)malloc((ft_count_words(s, ch) + 1) * sizeof(char *));
	strz = strs;
	if (!strs)
	{
		clean_mem(strs);
		return (NULL);
	}
	if (*s != '\0' && ch == '\0')
	{
		*strs++ = ft_strdup((char *)s);
		*strs = NULL;
		return (strz);
	}
	while (*s != '\0')
	{
		if (*s != ch)
			s = ft_wrdup(s, ch, strs++);
		else
			s++;
	}
	*strs = NULL;
	return (strz);
}
