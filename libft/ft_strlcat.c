/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:57:47 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/11 19:06:01 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	pos1;
	size_t	pos2;
	size_t	s;
	size_t	k;

	pos1 = 0;
	pos2 = 0;
	s = size;
	k = ft_strlen(src);
	while (dst[pos1] && pos1 < s)
		pos1++;
	while (src[pos2] && pos1 + pos2 + 1 < s)
	{
		dst[pos1 + pos2] = src[pos2];
		pos2++;
	}
	if (pos1 != s)
		dst[pos1 + pos2] = '\0';
	return (pos1 + k);
}
