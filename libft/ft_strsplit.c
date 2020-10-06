/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 03:04:50 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/23 20:10:31 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static char		**ft_free(char **str, int pos)
{
	while (pos > 0)
	{
		free(str[pos - 1]);
		pos--;
	}
	return (NULL);
}

static int		ft_len(char *s, char c)
{
	int			pos;
	int			len;

	len = 0;
	pos = 0;
	while (s[pos] && s[pos] == c)
		pos++;
	while (s[pos] && s[pos] != c)
	{
		pos++;
		len++;
	}
	return (len);
}

static char		**ft_zap(char *s, char c, char **str, int size)
{
	int			pos1;
	int			pos2;

	pos1 = 0;
	str[size] = NULL;
	while (pos1 < size)
	{
		pos2 = 0;
		if (!(str[pos1] = (char *)malloc(sizeof(char) * (ft_len(s, c) + 1))))
			return (ft_free(str, pos1));
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			str[pos1][pos2] = *s;
			pos2++;
			s++;
		}
		str[pos1][pos2] = '\0';
		pos1++;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char		*s1;
	char		**str;
	int			pos;
	int			size;

	s1 = (char *)s;
	size = 0;
	pos = 0;
	if (s == NULL)
		return (NULL);
	while (s1[pos])
	{
		if (s1[pos] == c)
		{
			while (s1[pos] && s1[pos] == c)
				pos++;
		}
		if (s1[pos])
			size++;
		while (s1[pos] && s1[pos] != c)
			pos++;
	}
	if (!(str = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	return (ft_zap(s1, c, str, size));
}
