/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <adubugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 11:56:30 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/14 17:56:48 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/42sh.h"

int		main(void)
{
	t_terminal		t;

	if (set_terminal(&t))
		return (1);
	init_signal_handlers();
	clear_scrn(t);
	if (run_shell(&t))
		return (1);
	retrieve_terminal(prev_term);
	return (0);
}
