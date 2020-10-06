/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:53:49 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/23 17:55:46 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	pos;

	pos = 0;
	if (s == NULL)
		return (NULL);
	if (len + 1 == 0)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (len)
	{
		str[pos] = s[start];
		len--;
		pos++;
		start++;
	}
	str[pos] = '\0';
	return (str);
}
