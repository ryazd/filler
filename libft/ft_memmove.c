/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:55:45 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/12 18:33:32 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			pos;
	unsigned char	*str1;
	unsigned char	*str2;

	pos = 0;
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (str1 < str2)
	{
		while (pos < len)
		{
			str1[pos] = str2[pos];
			pos++;
		}
	}
	else if (str1 > str2)
	{
		pos = len - 1;
		while (pos + 1 != 0)
		{
			str1[pos] = str2[pos];
			pos--;
		}
	}
	return (str1);
}
