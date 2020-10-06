/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 04:54:06 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/14 04:05:03 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int pos;

	pos = 0;
	if (s == NULL)
		return ;
	while (s[pos])
	{
		ft_putchar_fd(s[pos], fd);
		pos++;
	}
	write(fd, "\n", 1);
}
