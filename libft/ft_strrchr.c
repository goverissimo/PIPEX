/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:53:12 by gverissi          #+#    #+#             */
/*   Updated: 2023/04/24 10:26:02 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, unsigned char ch)
{
	size_t	len;
	char	*last;

	last = NULL;
	len = ft_strlen(str) + 1;
	while (len--)
	{
		if (str[len] == ch)
		{
			last = (char *)&str[len];
			return (last);
		}
	}
	return (last);
}
/*
#include <stdio.h>

int main(void)
{
    const char *str = "hello world";
    char ch = 'o';
    char *last = ft_strrchr(str, ch);
    
    if (last != NULL) {
        printf("'%c' found at index %ld\n", ch, last - str);
    } else {
        printf("'%c' not found in string\n", ch);
    }
    
    return 0;
}
*/