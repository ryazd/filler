/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:22:52 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/06 13:35:36 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strrchr(const char *s, int c)
{
	int			pos;
	const char	*str;

	pos = 0;
	while (s[pos])
		pos++;
	while (s[pos] != c && pos >= 0)
		pos--;
	if (s[pos] == c)
	{
		str = &(s[pos]);
		return ((char *)str);
	}
	return (NULL);
}
