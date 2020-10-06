/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:31:30 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/12 21:15:09 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static char		*zap(char *str, int n, int sch, int des)
{
	int			copy;
	long long	n1;

	n1 = (long long)n;
	copy = 0;
	if (n1 < 0)
	{
		n1 *= -1;
		sch++;
		str[copy] = '-';
		copy++;
	}
	while (copy < sch)
	{
		str[copy] = n1 / des + '0';
		n1 %= des;
		des /= 10;
		copy++;
	}
	str[copy] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int			sch;
	int			copy;
	char		*str;
	int			des;

	des = 1;
	sch = 1;
	copy = n;
	while (copy / 10 != 0)
	{
		sch++;
		copy /= 10;
	}
	str = (char *)malloc(sizeof(char) * (sch + 1));
	if (!str)
		return (NULL);
	copy = 0;
	while (copy < sch - 1)
	{
		copy++;
		des *= 10;
	}
	return (zap(str, n, sch, des));
}
