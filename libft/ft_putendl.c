/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:27:25 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/14 04:04:34 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putendl(char const *s)
{
	int pos;

	pos = 0;
	if (s == NULL)
		return ;
	while (s[pos])
	{
		write(1, &s[pos], 1);
		pos++;
	}
	write(1, "\n", 1);
}
