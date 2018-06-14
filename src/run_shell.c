#include "../include/42sh.h"

int		run_shell(t_terminal	*t)
{
	char	*input;
	char	**splt;
	//char	c[4];

	t->cmds = create_stack();
	while (1)
	{
		input = 0;
		ft_putstr_fd(COOL_RED, 1);
		input = prompt_command(t, "42sh > ");
		push(t->cmds, 0, input);
		if (!input)
			break ;
		ft_printf("\noutput: %s\n", input);
		input = replace_wc(input);
	//	handle multiple line
		//remove '\'
		splt = split_and_rejoin(input);
		//split_str
		//replace_stuff
		//order commands
		//run commands
	}
	return (0);
}
