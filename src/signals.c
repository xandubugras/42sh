/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <adubugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:16:03 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/14 17:56:30 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/42sh.h"

static void		signal_handler(int sig)
{
	sig = 0;
	retrieve_terminal(prev_term);
	exit(0);
}

static void		signal_suspend(int sig)
{
	sig = 0;
	retrieve_terminal(prev_term);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}


static void		signal_continue(int sig)
{
	sig = 0;
	if (tcsetattr(0, TCSADRAIN, &(bg_term)) == -1)
		return ;
	ft_putstr_fd(tgetstr("vi", 0), 1);
	ft_putstr_fd(tgetstr("ti", 0), 1);
	ft_putstr_fd(tgetstr("cl", 0), 1);
	init_signal_handlers();
	print_list(root);
}


void			init_signal_handlers(void)
{
	signal(SIGABRT, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGTSTP, signal_suspend);
	signal(SIGCONT, signal_continue);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
}
