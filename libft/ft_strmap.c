/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:22:42 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/13 15:25:51 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		pos;
	char	*str;

	pos = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[pos])
		pos++;
	str = (char *)malloc(pos + 1);
	if (!str)
		return (NULL);
	pos = 0;
	while (s[pos])
	{
		str[pos] = f(s[pos]);
		pos++;
	}
	str[pos] = '\0';
	return (str);
}
