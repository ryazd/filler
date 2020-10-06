/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:39:11 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/14 04:15:01 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*iskl(void)
{
	char	*str;

	if (!(str = (char *)malloc(1)))
		return (NULL);
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		stop;
	char	*str;
	int		pos;

	pos = 0;
	start = 0;
	if (s == NULL)
		return (NULL);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	stop = ft_strlen((char *)s) - 1;
	while (s[stop] == ' ' || s[stop] == '\n' || s[stop] == '\t')
		stop--;
	if (start >= stop)
		return (iskl());
	if (!(str = (char *)malloc(stop - start + 2)))
		return (NULL);
	while (start + pos < stop + 1)
	{
		str[pos] = s[start + pos];
		pos++;
	}
	str[pos] = '\0';
	return (str);
}
