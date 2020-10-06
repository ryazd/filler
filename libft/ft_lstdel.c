/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 03:10:56 by hluthor           #+#    #+#             */
/*   Updated: 2019/09/14 03:14:41 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*nextlist;

	list = *alst;
	if (alst && *alst && del)
	{
		while (list)
		{
			nextlist = list->next;
			del(list->content, list->content_size);
			free(list);
			list = nextlist;
		}
		*alst = NULL;
	}
}
