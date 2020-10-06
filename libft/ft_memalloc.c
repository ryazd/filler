/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 01:43:18 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/10 02:01:18 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void				*ft_memalloc(size_t size)
{
	unsigned char	*str;
	size_t			s;
	size_t			pos;

	pos = 0;
	s = size;
	str = (unsigned char *)malloc(sizeof(char) * s);
	if (!(str))
		return (NULL);
	while (pos < s)
	{
		str[pos] = 0;
		pos++;
	}
	return (str);
}
