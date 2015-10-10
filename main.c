/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 14:54:19 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 16:52:12 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_curs_udlr(t_env *env, char *buffer)
{
	if (buffer[1] == '[')
	{
		if (buffer[2] == 'A')
			ft_curs_prev(&(env->curs));
		else if (buffer[2] == 'B')
			ft_curs_next(&(env->curs));
		else if (buffer[2] == 'C')
			ft_curs_right(&(env->curs), env);
		else if (buffer[2] == 'D')
			ft_curs_left(&(env->curs), env);
	}
	else if (buffer[1] == 0)
		return (0);
	return (1);
}

static void	ft_select(t_env *env)
{
	char		buffer[3];
	t_select	*tmp;

	while (!env->print && env->list)
	{
		ft_bzero(buffer, 3);
		ft_display(env);
		read(0, buffer, 3);
		if (buffer[0] == 27)
		{
			if (!ft_curs_udlr(env, buffer))
				return ;
		}
		else if (buffer[0] == ' ' && buffer[1] == 0)
			env->curs->select = (env->curs->select == 0) ? 1 : 0;
		else if (buffer[0] == 10 && buffer[1] == 0)
			env->print = 1;
		else if ((buffer[0] == 127 || buffer[0] == '~') && buffer[1] == 0)
		{
			tmp = env->curs;
			ft_curs_next(&(env->curs));
			ft_lstdelone_slc(&(env->list), tmp);
		}
	}
}

int			main(int ac, char **av)
{
	t_env	*env;

	if (!(env = ft_env_slc()))
		ft_perror_exit("Impossible to malloc struct env");
	ft_init(ac, av, env);
	ft_init_term(env);
	ft_init_signal();
	ft_select(env);
	ft_restore_term(env);
	if (env->print)
		ft_print(env);
	close(env->ttyfd);
	return (0);
}
