#include "../include/42sh.h"

int			set_todo(char *to_do)
{
	if (!to_do)
		return (1);
	if (!ft_strcmp(to_do, "&&"))
		return (2);
	if (!ft_strcmp(to_do, ";"))
		return (3);
	if (!ft_strcmp(to_do, "||"))
		return (4);
	if (!ft_strcmp(to_do, "|"))
		return (5);
	if (!ft_strcmp(to_do, ">>"))
		return (6);
	if (!ft_strcmp(to_do, "<"))
		return (7);
	if (!ft_strcmp(to_do, "<<"))
		return (8);
	if (!ft_strcmp(to_do, ">"))
		return (9);
	return (0);
}

t_command	*create_cmd(char **input, int i)
{
	t_command	*new;

	if (!input[i])
		return ((t_command *)ft_printf_err_zero("err: no command\n"));
	new = new_command();
	if ((new->command = ft_strdup(input[i])) == 0)
		return ((t_command *)ft_printf_err_zero("err: no commands\n"));
	new->arguments = set_arguments(input, &i);
	//print_str_arr(new->arguments);
	if (input[i] == 0)
	{
		new->todo = 1;
		return (new);
	}
	new->todo = set_todo(input[i]);
	new->next = create_cmd(input, i + 1);
	if (new->next)
	{
		new->next->is_file = new->todo > 5 ? 1 : 0;
		new->next->prev = new;
	}
	return (new);
}

char	**set_arguments(char **input, int *i)
{
	int		j;
	int		tmp;
	char	**args;

	if (!input || !*input)
		return (0);
	j = 0;
	while (!set_todo(input[j + *i]))
		j++;
	tmp = j + *i;
	args = malloc(sizeof(char *) * (j + 1));
	args[j] = 0;
	while (--j >= 0)
		args[j] = ft_strdup(input[*i + j]);
	*i = tmp;
	return (args);
}
