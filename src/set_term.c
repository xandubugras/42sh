/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_term.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <adubugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:59:30 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/10 20:11:53 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/42sh.h"

int		set_terminal(t_terminal *t)
{
	if (!getenv("TERM") || tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
	if (tcgetattr(0, &(t->term)) == -1)
		return (-2);
	prev_term = t->term;
	ft_putstr_fd(tgetstr("ks", 0), 1);
	t->clear = tgetstr("cl", NULL);
	t->up = tgetstr("ku", NULL);
	t->down = tgetstr("kd", NULL);
	t->left = tgetstr("kl", NULL);
	t->right = tgetstr("kr", NULL);
	ft_putstr_fd(tgetstr("ti", 0), 1);

	bg_term = t->term;
	return (0);
}

int		set_can_terminal(t_terminal *t)
{
	if (!getenv("TERM") || tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
	t->term.c_lflag &= ~(ICANON);
	t->term.c_lflag &= ~(ECHO);
	t->term.c_cc[VMIN] = 1;
	t->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(t->term)) == -1)
		return (-4);
	return (1);
}

void	clear_scrn(t_terminal t)
{
	ft_putstr_fd(t.clear, 1);
}

void	retrieve_terminal(struct termios prev_term)
{
	if (!getenv("TERM") || tgetent(NULL, getenv("TERM")) == -1)
		return ;
	ft_putstr_fd(tgetstr("te", 0), 1);
	ft_putstr_fd(tgetstr("ke", 0), 1);
	tcsetattr(0, TCSADRAIN, &(prev_term));
}

void	go_terminal(struct termios prev_term)
{
	if (!getenv("TERM") || tgetent(NULL, getenv("TERM")) == -1)
		return ;
	tcsetattr(0, TCSADRAIN, &(prev_term));
}
