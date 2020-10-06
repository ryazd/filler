/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 04:48:06 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/14 04:04:19 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
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
}
