/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 01:51:19 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/14 02:01:26 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*zaplist;

	zaplist = lst;
	if (f == NULL)
		return ;
	if (lst == NULL)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
	lst = zaplist;
}
