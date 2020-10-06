/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 02:42:03 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/13 15:04:47 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	size_t	pos;
	char	*str;

	pos = 0;
	if (size + 1 == 0)
		return (NULL);
	str = (char *)malloc(size + 1);
	if (!(str))
		return (NULL);
	while (pos <= size)
	{
		str[pos] = '\0';
		pos++;
	}
	return (str);
}
