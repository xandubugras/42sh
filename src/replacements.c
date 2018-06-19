#include "../include/42sh.h"

char	*handle_tildo(char	*input)
{
	char	*path;
	int		i;

	path = getenv("HOME");
	i = 0;
	while (input[i])
	{
		if (input[i] == '~')	
			if (i == 0 || (i > 0 && input[i - 1] != 92))
				ft_strinsert_sub(&input, path, i);
		i++;
	}
	//ft_printf("%s\n", input);
	return (input);
}

char	*handle_env_vars(char *input)
{
	char	*path;
	char	*tmp;
	int		i;
	int		j;
	int		copied;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$')	
			if (i == 0 || (i > 0 && input[i - 1] != 92))
			{
				j = i + 1;
				while (input[j] && input[j] != ' ')
					j++;
				copied = input[j] == ' ' ? j - i - 1: j - i;
				tmp = ft_strsub(input, i + 1, copied);
				path = getenv(tmp);
				copied = ft_strncpy_safe(&input[i], path, j - i);
	//			ft_printf("tmp: %s.\n", tmp);
	//			ft_printf("path: %s.\n", path);
	//			ft_printf("input after cpy1: %s.\n", input);
				if (copied < (int)ft_strlen(path))
					ft_strinsert(&input, &path[copied], i + copied);
			}
		i++;
	}
	return (input);
	
}

char	*replace_wc(char *input)
{
	input = handle_tildo(input);
	input = handle_env_vars(input);
	//ft_printf("~$: %s.\n", input);
	return (input);
}
