/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:18:36 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/23 17:11:05 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*zap(char *str, char const *s1, char const *s2)
{
	int		pos;
	int		len;

	pos = 0;
	len = 0;
	if (s1 != NULL)
	{
		while (s1[pos])
		{
			str[len] = s1[pos];
			len++;
			pos++;
		}
	}
	pos = 0;
	while (s2[pos])
	{
		str[len] = s2[pos];
		pos++;
		len++;
	}
	str[len] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;
	int		pos;

	pos = 0;
	len = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[pos])
			pos++;
	}
	len = pos;
	pos = 0;
	while (s2[pos])
		pos++;
	len += pos;
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	return (zap(str, s1, s2));
}
