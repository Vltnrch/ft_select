/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 15:03:53 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 16:51:41 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_display_2(t_env *env)
{
	t_select	*list;
	size_t		x;
	size_t		y;

	list = env->list;
	x = 0;
	y = 0;
	while (list)
	{
		if (y > env->li)
		{
			x += env->maxlen + 2;
			y = 0;
		}
		if (list == env->curs)
			ft_putstr_fd(tgetstr("us", &(env->area)), env->ttyfd);
		if (list->select)
			ft_putstr_fd(tgetstr("mr", &(env->area)), env->ttyfd);
		tputs(tgoto(tgetstr("cm", &(env->area)), x, y), 1, ft_putchar_tputs);
		ft_putstr_fd(list->str, env->ttyfd);
		if (list->select || list == env->curs)
			ft_putstr_fd(tgetstr("me", &(env->area)), env->ttyfd);
		list = list->next;
		y++;
	}
}

void		ft_display(t_env *env)
{
	size_t		height;
	size_t		width;

	if (tgetent(NULL, env->name_term) == -1)
		return ;
	height = tgetnum("li");
	width = tgetnum("co");
	ft_putstr_fd(tgetstr("cl", &(env->area)), env->ttyfd);
	env->co = width / (env->maxlen + 2);
	if (env->co)
		env->li = ft_list_size_slc(env->list) / env->co;
	if (env->co == 0 || env->li >= height)
	{
		ft_putstr_fd("Too Small !\n", env->ttyfd);
		return ;
	}
	ft_display_2(env);
}

void		ft_perror_exit(const char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
