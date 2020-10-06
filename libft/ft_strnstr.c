/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:42:16 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/12 20:33:45 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!needle[a])
		return ((char *)haystack);
	while (haystack[a] && len > a)
	{
		b = 0;
		while (needle[b] == haystack[a + b] && haystack[a + b]
				&& needle[b] && (a + b) < len)
			b++;
		if (!(needle[b]))
			return ((char *)&haystack[a]);
		a++;
	}
	return (NULL);
}
