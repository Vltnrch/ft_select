/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 19:11:30 by vroche            #+#    #+#             */
/*   Updated: 2015/09/17 15:35:49 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*ft_lstnew_slc(char *content)
{
	t_select	*list;
	char		*dest;

	if (content == NULL)
		dest = NULL;
	else
	{
		if (!(dest = ft_strdup(content)))
			return (NULL);
	}
	if (!(list = (t_select *)ft_memalloc(sizeof(t_select))))
		return (NULL);
	list->prev = NULL;
	list->next = NULL;
	list->str = dest;
	list->select = 0;
	return (list);
}

void		ft_lstadd_back_slc(t_select **alst, t_select *new)
{
	t_select *tmp;

	if (new)
	{
		if (!(*alst))
			*alst = new;
		else
		{
			tmp = *alst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
			new->prev = tmp;
		}
	}
}

void		ft_lstdelone_slc(t_select **alst, t_select *del)
{
	if (alst && *alst && del)
	{
		if (*alst == del)
		{
			*alst = (*alst)->next;
			if (*alst)
				(*alst)->prev = NULL;
		}
		else
		{
			if (del->prev)
				del->prev->next = del->next;
			if (del->next)
				del->next->prev = del->prev;
		}
		free(del->str);
		free(del);
	}
}

int			ft_list_size_slc(t_select *begin_list)
{
	t_select	*tmp;
	int			i;

	i = 1;
	tmp = begin_list;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
