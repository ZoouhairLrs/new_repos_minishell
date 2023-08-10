#include "../inc/zoro.h"

void ft_session(char *input, int *exit_t, t_env *env)
{
    //int checker;

    (void)env;
    (void)exit_t;
    if (!input[0])
        add_history(input);
    ft_type_expand(&input, exit_t, env);
    /*
    checker = ft_find_pipe(input, 0);
    if (input[checker] == '|')
        ft_one_command(input, exit_t, env);
    */
}