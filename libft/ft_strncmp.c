/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:30:36 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/13 19:11:00 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			pos;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	pos = 0;
	if (n == 0)
		return (0);
	while (str1[pos] == str2[pos] && pos < n - 1 && str1[pos] && str2[pos])
		pos++;
	return (pos = (str1[pos] - str2[pos]));
}
