/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:08:56 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/07 16:00:59 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*cop;
	int		pos;

	pos = 0;
	while (s1[pos] != '\0')
		pos++;
	cop = (char*)malloc(pos + 1);
	if (!cop)
		return (NULL);
	pos = 0;
	while (s1[pos] != '\0')
	{
		cop[pos] = s1[pos];
		pos++;
	}
	cop[pos] = '\0';
	return (cop);
}
