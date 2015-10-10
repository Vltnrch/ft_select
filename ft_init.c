/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 19:24:25 by vroche            #+#    #+#             */
/*   Updated: 2015/10/02 14:42:55 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_init_signal(void)
{
	signal(SIGWINCH, &ft_handler);
	signal(SIGINT, &ft_handler);
	signal(SIGQUIT, &ft_handler);
	signal(SIGCONT, &ft_handler);
	signal(SIGTSTP, &ft_handler);
	signal(SIGTERM, &ft_handler);
}

static void	ft_getparams(int ac, char **av, t_env *env)
{
	t_select	*new;

	av++;
	env->maxlen = 0;
	while (ac-- > 1)
	{
		if (ft_strlen(*av) > env->maxlen)
			env->maxlen = ft_strlen(*av);
		new = ft_lstnew_slc(*av++);
		ft_lstadd_back_slc(&(env->list), new);
	}
	env->curs = env->list;
}

static void	ft_check_term(t_env *env)
{
	if (!(tgetstr("us", &(env->area))))
		ft_perror_exit("your term can't \"us\", use Xterm :-)");
	if (!(tgetstr("mr", &(env->area))))
		ft_perror_exit("your term can't \"mr\", use Xterm :-)");
	if (!(tgetstr("cm", &(env->area))))
		ft_perror_exit("your term can't \"cm\", use Xterm :-)");
	if (!(tgetstr("me", &(env->area))))
		ft_perror_exit("your term can't \"me\", use Xterm :-)");
	if (!(tgetstr("cl", &(env->area))))
		ft_perror_exit("your term can't \"cl\", use Xterm :-)");
	if (!(tgetstr("vi", &(env->area))))
		ft_perror_exit("your term can't \"vi\", use Xterm :-)");
	if (!(tgetstr("ti", &(env->area))))
		ft_perror_exit("your term can't \"ti\", use Xterm :-)");
	if (!(tgetstr("ve", &(env->area))))
		ft_perror_exit("your term can't \"ve\", use Xterm :-)");
	if (!(tgetstr("te", &(env->area))))
		ft_perror_exit("your term can't \"te\", use Xterm :-)");
}

void		ft_init(int ac, char **av, t_env *env)
{
	if ((env->name_term = getenv("TERM")) == NULL)
		ft_perror_exit("TERM variable not found");
	env->list = NULL;
	env->curs = NULL;
	env->print = 0;
	env->sig = 0;
	if (tgetent(NULL, env->name_term) == -1)
		ft_perror_exit("Impossible to call tgetent");
	if (tcgetattr(0, &(env->term)) == -1 || tcgetattr(0, &(env->def)) == -1)
		ft_perror_exit("Impossible to call tcgetattr");
	env->term.c_lflag &= ~(ICANON);
	env->term.c_lflag &= ~(ECHO);
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	if ((env->ttyfd = open("/dev/tty", O_RDWR)) <= 0)
		ft_perror_exit("Impossible to open /dev/tty");
	if (!isatty(env->ttyfd))
	{
		close(env->ttyfd);
		ft_perror_exit("fd is not atty");
	}
	ft_getparams(ac, av, env);
	ft_check_term(env);
}
