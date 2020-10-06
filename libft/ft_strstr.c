/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:44:34 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/12 20:14:57 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char			*ft_strstr(const char *haystack, const char *needle)
{
	int			a;
	int			b;

	a = 0;
	if (!needle[a])
		return ((char *)haystack);
	while (haystack[a])
	{
		b = 0;
		while (needle[b] == haystack[a + b] && haystack[a + b] && needle[b])
			b++;
		if (!(needle[b]))
			return ((char *)&haystack[a]);
		a++;
	}
	return (NULL);
}
