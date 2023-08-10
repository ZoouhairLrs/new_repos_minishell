#include "../inc/zoro.h"

void ft_message(int type)
{
    if (type == 1)
        printf("%sunclosed quotes !\n%s", BLUE, WA);
    else if (type == 2)
        printf("%ssyntax error !\n%s", BLUE, WA);
    else if (type == 3)
        printf("%sunexpected token !\n%s", BLUE, WA);
    else if (type == 4)
        printf("%sError Fork() !\n%s", BLUE, WA);
    else if (type == 5)
        printf("%sError File Descriptor !\n%s", BLUE, WA);
    else if (type == 6)
        printf("%sError waitpid !\n%s", BLUE, WA);
    
    
}

int	ft_unclosed_quotes(char *string, char quote)
{
	int	i[2];

	i[1] = 0;
	i[0] = -1;
	while (string[++i[0]])
	{
		if (string[i[0]] == SQ || string[i[0]] == DQ)
		{
			i[1] += 1;
			quote = string[i[0]];
			while (string[++i[0]])
			{
				if (string[i[0]] == quote)
				{
					quote = 0;
					i[1] += 1;
					break ;
				}
			}
		}
	}
	if (!(i[1] % 2))
		return (0);
	return (1);
}

int ft_read_input(char *input, int *exit)
{
    int i;

    i = 0;
    if (ft_unclosed_quotes(input, 0))
    {
        i++;
        ft_message(1);
    }
    else if (ft_syntaxt_redirect(input, 0, exit))
    {
        i++;
        ft_message(3);
    }
    if (i != 0 || !input[0])
        free(input);
    return (i);
}

int ft_check_pipe(char *input, int *exit)
{
    int i;

    i = -1;
    while (input[++i])
    {
        while (ft_delimeters(input[i]))
            i++;
        if (input[i] == '|')
        {
            *exit = 2;
            return (1);
        }
        return (0);
    }
    return (0);
}

bool    ft_delimeters(char c)
{
	return (c == ' ' || c == '\t');
}

bool    ft_is_quote(char c)
{
	return (c == SQ || c == DQ);
}