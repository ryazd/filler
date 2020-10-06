/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 00:15:18 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/11 18:26:14 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			pos;
	unsigned char	*str;
	size_t			n1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	n1 = n;
	pos = 0;
	str = (unsigned char *)s;
	while (pos < n1)
	{
		if (str[pos] == c1)
			return (&str[pos]);
		pos++;
	}
	return (NULL);
}
