/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:49:13 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/11 18:05:21 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			pos;
	unsigned char	c1;
	size_t			n1;

	pos = 0;
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	n1 = n;
	c1 = (unsigned char)c;
	while (n1 > pos)
	{
		str1[pos] = str2[pos];
		if (str1[pos] == c1)
			return (&str1[pos + 1]);
		pos++;
	}
	return (NULL);
}
