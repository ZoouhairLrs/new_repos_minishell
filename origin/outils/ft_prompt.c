#include "../inc/zoro.h"

char	*ft_set_prompt(char *user, char *cwd)
{
	char	*tmp;
	char	*full_prompt;

	full_prompt = NULL;
	if (user && cwd)
	{
		tmp = ft_strjoin(user, "\001\033[1;91m\002@minishell ~ \033[0m");
		full_prompt = ft_strjoin(tmp, cwd);
		free(tmp);
		tmp = ft_strjoin(full_prompt, " $> ");
		free(full_prompt);
		free(cwd);
		return (tmp);
	}
	else
		full_prompt = ft_strjoin("guest", "@minishell ~ $>");
	if (cwd)
		free(cwd);
	return (full_prompt);
}
