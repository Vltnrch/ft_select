/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 15:01:30 by vroche            #+#    #+#             */
/*   Updated: 2015/10/09 16:47:27 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env		*ft_env_slc(void)
{
	static t_env	*env = NULL;

	if (!env)
		if (!(env = (t_env *)malloc(sizeof(t_env))))
			return (NULL);
	return (env);
}

int			ft_putchar_tputs(int c)
{
	t_env	*env;

	env = ft_env_slc();
	ft_putchar_fd(c, env->ttyfd);
	return (42);
}

static void	ft_resignal(int sig, t_env *env, char *buff)
{
	if (sig == SIGINT)
		buff[0] = env->term.c_cc[VINTR];
	else if (sig == SIGQUIT)
		buff[0] = env->term.c_cc[VQUIT];
	else if (sig == SIGTSTP)
		buff[0] = env->term.c_cc[VSUSP];
	else if (sig == SIGCONT)
	{
		ft_init_term(env);
		signal(env->sig, &ft_handler);
		ft_display(env);
	}
	else if (sig == SIGWINCH)
		ft_display(env);
}

void		ft_handler(int sig)
{
	t_env	*env;
	char	buff[2];

	buff[1] = 0;
	env = ft_env_slc();
	if (sig == SIGINT || sig == SIGQUIT || sig == SIGTSTP || sig == SIGTERM)
	{
		env->sig = sig;
		ft_restore_term(env);
		signal(sig, SIG_DFL);
	}
	ft_resignal(sig, env, buff);
	if (sig == SIGINT || sig == SIGQUIT || sig == SIGTSTP || sig == SIGTERM)
	{
		if (sig != SIGTSTP)
			close(env->ttyfd);
		if (sig != SIGTERM)
			ioctl(0, TIOCSTI, buff);
		else
			exit(0);
	}
}

void		ft_print(t_env *env)
{
	t_select	*list;
	int			n;

	list = env->list;
	n = 0;
	while (list)
	{
		if (list->select)
		{
			if (n)
				ft_putstr(" ");
			n = 1;
			ft_putstr(list->str);
		}
		list = list->next;
	}
	if (n)
		ft_putstr("\n");
}
