/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:22:32 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/06 16:38:07 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	pos;

	pos = 0;
	while (len - pos && src[pos])
	{
		dst[pos] = src[pos];
		pos++;
	}
	while (len - pos)
	{
		dst[pos] = '\0';
		pos++;
	}
	return (dst);
}
