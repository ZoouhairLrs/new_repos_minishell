#include "../inc/zoro.h"

char	*ft_extract_token(char *str, int n)
{
	int		i[2];
	char	quote;
	char	*buffer;

	i[0] = -1;
	i[1] = -1;
	buffer = ft_memset(ft_strdup(str), 0, ft_strlen(str));
	while (str[++i[0]] && i[0] < n)
	{
		quote = 0;
		if (str[i[0]] == SQ || str[i[0]] == DQ)
		{
			quote = str[i[0]];
			while (str[++i[0]] && str[i[0]] != quote)
				buffer[++i[1]] = str[i[0]];
			quote = 0;
		}
		else
			buffer[++i[1]] = str[i[0]];
	}
	return (buffer);
}

static int  ft_find_herdoc(char *str, char quote)
{
    int i;

    i = -1;
    while (str[++i])
	{
		quote = 0;
		if (ft_is_quote(str[i]))
		{
			quote = str[i];
			while (str[++i] && str[i] != quote)
				continue;
			quote = 0;
		}
        if (!ft_strncmp(str + i, "<<", 2))
            return (i);
    }
    return (0);
}

int     ft_find_f_or_l(char *input, char quote, int f_or_l)
{
    int i;

    i = -1;
    while (input[++i])
	{
        if (f_or_l)
        {
            while (ft_delimeters(input[i]))
                i++;
            return (i);
        }
        else
        {
		    if (ft_is_quote(input[i]))
		    {
			    quote = input[i];
			    while (!ft_is_quote(input[++i]) && input[i] != quote)
                    continue;
			    quote = 0;
            }
            if (!ft_delimeters(input[i]) && !ft_redirect_type(input[i]))
                continue;
            return (i);
		}
    }
    return (i);
}


int ft_herdoc(char *input, int *exit, t_env *env)
{
    int i[2];
    char *complete;
    char *delimiter;

    i[0] = ft_find_herdoc(input, 0);
    if (input[i[0]] == 60 && input[i[0] + 1] == 60)
    {
        delimiter = &input[i[0] + 2];
        i[1] = ft_find_f_or_l(delimiter, 0, 1);
        delimiter = &delimiter[i[1]];
        i[0] = ft_find_f_or_l(delimiter, 0, 0);
        complete = delimiter + i[0];
        delimiter = ft_extract_token(delimiter, i[0]);
        if (!ft_fork_herdoc(delimiter, exit, env))
            return (TRUE);
        return (ft_herdoc(complete, exit, env));
    }
    return (FALSE);
}