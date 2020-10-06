/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 00:29:39 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/10 00:46:08 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			pos;
	unsigned char	*str1;
	unsigned char	*str2;

	pos = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (pos < n)
	{
		if (str1[pos] != str2[pos])
			return (str1[pos] - str2[pos]);
		pos++;
	}
	return (0);
}
