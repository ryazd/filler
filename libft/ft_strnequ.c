/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 02:52:33 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/13 20:06:55 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	pos;
	int		res;

	pos = 0;
	if (s1 && s2)
	{
		res = ft_strncmp(s1, s2, n);
		return (res == 0 ? 1 : 0);
	}
	return (0);
}
