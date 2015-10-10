/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 14:54:29 by vroche            #+#    #+#             */
/*   Updated: 2015/09/17 19:14:01 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <sys/ioctl.h>
# include <fcntl.h>

typedef struct		s_select
{
	char			*str;
	int				select;
	struct s_select	*prev;
	struct s_select	*next;
}					t_select;

typedef struct		s_env
{
	struct termios	term;
	struct termios	def;
	t_select		*list;
	t_select		*curs;
	int				maxsize;
	char			*area;
	size_t			maxlen;
	size_t			li;
	size_t			co;
	char			*name_term;
	int				print;
	int				ttyfd;
	int				sig;
}					t_env;

void				ft_curs_next(t_select **curs);
void				ft_curs_prev(t_select **curs);
void				ft_curs_right(t_select **curs, t_env *env);
void				ft_curs_left(t_select **curs, t_env *env);

void				ft_display(t_env *env);
void				ft_perror_exit(const char *str);

void				ft_init_signal();
void				ft_init(int ac, char **av, t_env *env);

t_select			*ft_lstnew_slc(char	*content);
void				ft_lstadd_back_slc(t_select **alst, t_select *new);
void				ft_lstdelone_slc(t_select **alst, t_select *del);
int					ft_list_size_slc(t_select *begin_list);

t_env				*ft_env_slc(void);
int					ft_putchar_tputs(int c);
void				ft_handler(int sig);
void				ft_print(t_env *env);

void				ft_init_term(t_env *env);
void				ft_restore_term(t_env *env);

#endif
