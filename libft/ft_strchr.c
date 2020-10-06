/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:05:14 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/06 13:21:37 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strchr(const char *s, int c)
{
	int			pos;
	const char	*str;

	pos = 0;
	while (s[pos] != c && s[pos])
		pos++;
	if (s[pos] == c)
	{
		str = &(s[pos]);
		return ((char *)(str));
	}
	return (NULL);
}
