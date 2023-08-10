#include "../inc/zoro.h"

int ft_redirect_type(char c)
{
    if (c == '<')
        return (1);
    if (c == '>')
        return (2);
    if (c == '|')
        return (3);
    return (0);
}

int ft_not_valid(char *input, int *i)
{
    int j[3];

    j[0] = *i;
    j[1] = ft_redirect_type(input[j[0]]);
    if (!input[j[0] + 1])
        return (1);
    j[2] = ft_redirect_type(input[j[0] + 1]);
    if (j[1] == j[2] && j[1] != 3)
        j[0]++;
    else if (j[1] == j[2] && j[1] == 3)
        return (1);
    j[0]++;
    while (ft_delimeters(input[j[0]]) && input[j[0]])
        j[0]++;
    if (ft_redirect_type(input[j[0]]) || !input[j[0]])
        return (1);
    *i = j[0] - 1;
    return (0);
}

int ft_syntaxt_redirect(char *input, char quote, int *exit)
{
    int i;

    i = -1;
    while (input[++i])
    {
        while (ft_delimeters(input[i]))
            i++;
        if (ft_is_quote(input[i]))
            quote = input[i];
        while (quote && input[++i])
        {
            if (ft_is_quote(input[i]) && input[i] == quote)
                quote = 0;
        }
        if (!ft_redirect_type(input[i]))
            continue;
        if (ft_not_valid(input, &i))
        {
            *exit = 1;
            return (1);
        }
    }
    return (0);
}

int ft_find_pipe(char *input, char quote)
{
    int i;

    i = -1;
    while (input[++i])
    {
        while (ft_delimeters(input[i]))
            i++;
        if (ft_is_quote(input[i]))
            quote = input[i];
        while (quote && input[++i])
        {
            if (ft_is_quote(input[i]) && input[i] == quote)
                quote = 0;
        }
        if (ft_redirect_type(input[i]) != 3)
            continue;
        return (i);
    }
    return (i);
}

int ft_next_redir(char *input, char quote)
{
    int i;

    i = -1;
    while (input[++i])
    {
        while (ft_delimeters(input[i]))
            i++;
        if (ft_is_quote(input[i]))
            quote = input[i];
        while (quote && input[++i])
        {
            if (ft_is_quote(input[i]) && input[i] == quote)
                quote = 0;
        }
        if (!ft_redirect_type(input[i]))
            continue;
        if (ft_redirect_type(input[i]) == 3)
            continue;
        if (input[i] == 60 && input[i + 1] == 60)
            continue;
        return (i);
    }
    return (0);
}