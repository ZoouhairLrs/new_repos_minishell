#include "../inc/zoro.h"

/*

*/
int ft_count_command(char *input, char quote)
{
    int i;
    int words;

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
        if (!ft_delimeters(input[i]) || !ft_redirect_type(input[i]))
            continue;
        if (ft_redirect_type(input[i]) != 3 && !ft_redirect_type(input[i]))
        {
            while (input[i])
            {
                if (ft_redirect_type(input[i]))
                    continue;
                while (ft_delimeters(input[i]))
                    i++;
                while (!ft_delimeters(input[i]) && !ft_redirect_type(input[i]))
                    i++;
            }
        }
        if (ft_redirect_type(input[i]) == 3)
            break;
        words++;
    }
}

char  **ft_collect_command(char *input)
{
    int i[2];
    char **commands;

    i[0] = ft_count_command(input)
    
}