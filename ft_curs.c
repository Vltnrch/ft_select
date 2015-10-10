/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 18:08:25 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 19:24:52 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_curs_next(t_select **curs)
{
	if ((*curs)->next == NULL)
	{
		while ((*curs)->prev != NULL)
			*curs = (*curs)->prev;
	}
	else
		*curs = (*curs)->next;
}

void			ft_curs_prev(t_select **curs)
{
	if ((*curs)->prev == NULL)
	{
		while ((*curs)->next != NULL)
			*curs = (*curs)->next;
	}
	else
		*curs = (*curs)->prev;
}

void			ft_curs_right(t_select **curs, t_env *env)
{
	int		tmp;

	tmp = env->li + 1;
	while (tmp > 0)
	{
		if ((*curs)->next == NULL)
		{
			while ((*curs)->prev != NULL)
				*curs = (*curs)->prev;
			tmp = 0;
		}
		else
			*curs = (*curs)->next;
		tmp--;
	}
}

void			ft_curs_left(t_select **curs, t_env *env)
{
	int		tmp;

	tmp = env->li + 1;
	while (tmp > 0)
	{
		if ((*curs)->prev == NULL)
		{
			while ((*curs)->next != NULL)
				*curs = (*curs)->next;
			tmp = 0;
		}
		else
			*curs = (*curs)->prev;
		tmp--;
	}
}
