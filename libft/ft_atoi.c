/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:58:43 by hluthor           #+#    #+#             */
/*   Updated: 2020/10/26 20:50:29 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(const char *str)
{
	long long	chislo;
	int			znak;

	znak = 1;
	chislo = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f' ||
			*str == '\v' || *str == '\t' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			znak = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57 && *str != '\0')
	{
		if (chislo < 0 && znak < 0)
			return (0);
		else if (chislo < 0 && znak > 0)
			return (-1);
		chislo *= 10;
		chislo += *str - '0';
		str++;
	}
	return (chislo * znak);
}
