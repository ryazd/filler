/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:22:05 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/14 04:02:29 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putstr(char const *s)
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
}
