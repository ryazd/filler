/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:25:43 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/07 18:49:45 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			pos;
	unsigned char	*str;

	str = b;
	pos = 0;
	while (len - pos)
	{
		str[pos] = c;
		pos++;
	}
	return (str);
}
