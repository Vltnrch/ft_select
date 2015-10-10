/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 15:02:25 by vroche            #+#    #+#             */
/*   Updated: 2015/09/17 19:05:46 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_init_term(t_env *env)
{
	if (tcsetattr(0, TCSADRAIN, &(env->term)) == -1)
		ft_perror_exit("Impossible to init term with tcsetattr");
	ft_putstr_fd(tgetstr("vi", &(env->area)), env->ttyfd);
	ft_putstr_fd(tgetstr("ti", &(env->area)), env->ttyfd);
}

void	ft_restore_term(t_env *env)
{
	ft_putstr_fd(tgetstr("ve", &(env->area)), env->ttyfd);
	ft_putstr_fd(tgetstr("te", &(env->area)), env->ttyfd);
	if (tcsetattr(0, TCSADRAIN, &(env->def)) == -1)
		ft_perror_exit("Impossible to restore term with tcsetattr");
}
