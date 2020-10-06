/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:38:13 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/07 14:23:49 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	pos;
	size_t	pos2;

	pos2 = 0;
	pos = 0;
	while (s1[pos])
		pos++;
	while (s2[pos2] && (n - pos2) != 0)
	{
		s1[pos] = s2[pos2];
		pos++;
		pos2++;
	}
	s1[pos] = '\0';
	return (s1);
}
