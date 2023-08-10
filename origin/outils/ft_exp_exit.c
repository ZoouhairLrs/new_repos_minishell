#include "../inc/zoro.h"

static int	ft_find_exit_var(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == SQ)
		{
			++i;
			while (str[i] && str[i] != SQ)
				++i;
		}
		else if (str[i] == DQ)
		{
			while (str[++i] && str[i] != DQ)
			{
				if (str[i] == '$' && str[i + 1] == '?')
					return (i);
			}
		}
		else if (str[i] == '$' && str[i + 1] == '?')
			return (i);
	}
	return (i);
}

void ft_search_replace2(int *exit_t, t_base *data, char **str, int i[3])
{
    char *output;
    char *last;

    i[3] = 0;
    output = ft_itoa(*exit_t);
    last = ft_strdup(data->middel + (i[3] + 1));
    ft_free_count(*str, NULL);
    *str = ft_strjoin(data->first, output);
    ft_free_count(data->first, output);
    data->first = ft_strjoin(*str, last);
    ft_free_count(*str, last);
    *str = ft_strdup(data->first);
    free(data->first);
}

void  ft_search_var2(char **str, int *exit_t, int *stop)
{
    int i[3];
    t_base data;

    i[0] = ft_find_exit_var(*str);
    i[1] = ft_strlen(*str);
    if ((*str)[i[0]] == '$' && (*str)[i[0] + 1] == '?')
    {
        data.first = ft_memset(ft_strdup(*str), 0, i[1]);
        ft_strlcpy(data.first, *str, i[0] + 1);
        data.middel = &((*str)[i[0] + 1]);
        ft_search_replace2(exit_t, &data, str, i);
    }
    *stop = i[0];
}

void ft_check_line2(char **str, int *exit_t)
{
    int i;

    i = -1;
    while ((*str)[++i])
    {
        ft_search_var2(str, exit_t, &i);
        if (!(*str)[i])
            break;
    }
}

void  ft_type_expand(char **str, int *exit_t, t_env *env)
{
    ft_check_line(str, env);
    ft_check_line2(str, exit_t);
}