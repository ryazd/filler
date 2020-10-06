/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:05:03 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/07 16:16:32 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void				*ft_memcpy(void *dst,
					const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			pos;

	pos = 0;
	str1 = dst;
	str2 = (unsigned char *)src;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	while (n > 0)
	{
		str1[pos] = str2[pos];
		pos++;
		n--;
	}
	return (str1);
}
