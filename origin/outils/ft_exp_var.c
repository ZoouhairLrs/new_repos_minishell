#include "../inc/zoro.h"

bool ft_valid_var(char *var_str)
{
    int i;

    if (ft_isalpha(var_str[0]))
    {
        i = 0;
        while (var_str[++i])
        {
            if (ft_isalnum(var_str[i]))
                continue;
            else if (var_str[i] == '_')
                continue;
            else
                return(FALSE);
        }
        return (TRUE);
    }
    return (FALSE);
}

bool ft_valid_after(char c)
{
    return (ft_isalnum(c) || c == '_');
}

int	ft_find_var_env(char *str)
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
				if (str[i] == '$' && ft_valid_after(str[i + 1]))
					return (i);
			}
		}
		else if (str[i] == '$' && ft_valid_after(str[i + 1]))
			return (i);
	}
	return (i);
}

void ft_free_count(char *str1, char *str2)
{
    if (str1)
        free(str1);
    if (str2)
        free(str2);
}

void ft_search_replace(t_env *env, t_base *data, char **str, int i[3])
{
    char *value;
    char *output;
    char *last;

    if (!i[3])
        return (ft_free_count(data->first, NULL));
    value = ft_memset(ft_strdup(data->middel), 0, ft_strlen(data->middel));
    ft_strlcpy(value, data->middel, i[3] + 1);
    output = ft_get_env_value(env, value);
    if (!output)
        output = ft_strdup(" ");
    last = ft_strdup(data->middel + i[3]);
    ft_free_count(*str, value);
    *str = ft_strjoin(data->first, output);
    ft_free_count(data->first, output);
    data->first = ft_strjoin(*str, last);
    ft_free_count(*str, last);
    *str = ft_strdup(data->first);
    free(data->first);
}

void  ft_search_var(char **str, t_env *env, int *stop)
{
    int i[3];
    t_base data;

    i[0] = ft_find_var_env(*str);
    i[1] = ft_strlen(*str);
    if ((*str)[i[0]] == '$' && ft_valid_after((*str)[i[0] + 1]))
    {
        data.first = ft_memset(ft_strdup(*str), 0, i[1]);
        ft_strlcpy(data.first, *str, i[0] + 1);
        data.middel = &((*str)[i[0] + 1]);
        i[3] = -1;
        while (data.middel[++i[3]] && ft_valid_after(data.middel[i[3]]))
        {
            if (!ft_valid_after(data.middel[i[3]]))
                break;
        }
        ft_search_replace(env, &data, str, i);
    }
    *stop = i[0];
}

void ft_check_line(char **str, t_env *env)
{
    int i;

    i = -1;
    while ((*str)[++i])
    {
        ft_search_var(str, env, &i);
        if (!(*str)[i])
            break;
    }
}
