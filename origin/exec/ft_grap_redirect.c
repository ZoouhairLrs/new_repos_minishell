#include "../inc/zoro.h"

char *ft_input_file(char *locate)
{
    int i[3];
    char *file;

    i[0] = -1;
    while (locate[++i[0]])
    {
        while (ft_delimeters(locate[i[0]]))
            i[0]++;
        i[1] = i[0];
        while (locate[++i[0]])
        {
            if (ft_delimeters(locate[i[0]]))
                break;
            if (ft_redirect_type(locate[i[0]]))
                break;
        }
        i[2] = i[0];
        i[0] = i[2] - i[1];
        file = ft_memset(ft_strdup(locate), 0, ft_strlen(locate));
        ft_strlcat(file, locate + (i[1] + 1), i[0]);
        return (file);
    }
    return (0);
}

int ft_locate_infile(char *input, char **file, int i[2])
{
    char *location;

    i[0] = ft_next_redir(input, 0);
    i[1] += i[0]; 
    location = &input[i[0]];
    if (!location[0])
        return (FALSE);
    if (!(location[0] == 60 && location[1] != 60))
    {
        i[1] += 1;
        return (ft_locate_infile(&location[1], file, i));
    }
    if (location[0] == 60 && location[1] != 60)
        *file = ft_input_file(location);
    else
        return (FALSE);
    return (TRUE);
}

char *ft_last_file(char *input)
{
    int i[2];
    char *file;
    char *last;

    i[1] = 0;
    last = 0;
    while (ft_locate_infile(input + i[1], &file, i))
    {
        i[1] += 1; 
        last = ft_strdup(file);
        ft_free_count(file, NULL);
    }
    if (!last)
        return (0);
    return(last);
}
