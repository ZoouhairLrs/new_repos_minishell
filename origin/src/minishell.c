#include "../inc/zoro.h"

char *ft_get_env_value(t_env *env, char *src)
{
    int n;
    t_env *current;

    n = ft_strlen(src);
    current = env;
    while (current)
    {
        if (!ft_strncmp(current->env, src, n) && current->env[n] == '=')
            return (ft_strdup(current->env + (n + 1)));
        current = current->next;
    }
    return (0);
}

int ft_start_shell(t_env **head)
{
    int exit;
    char *prompt;
    char *input;
    char *home;

    exit = 0;
    while (1)
    {
        ft_set_signals();
        home = ft_get_env_value(*head, "USER");
        prompt = ft_set_prompt(home, getcwd(NULL, 0));
        ft_free_count(home, NULL);
        input = readline(prompt);
        if (ft_read_input(input, &exit) || ft_herdoc(input, &exit, *head))
        {
            free(prompt);
            continue ;
        }
        ft_session(input, &exit, *head);
        ft_free_count(prompt, input);
    }
    return (exit);
}

static int ft_minishell(char *env[])
{
    int count;
    t_env *head;

    count = -1;
    if (env[0])
    {
        head = NULL;
        while (env[++count])
            ft_addback_env(ft_addnew_env(env[count]), &head);
    }
    else
        return (EXIT_FAILURE);
    ft_start_shell(&head);
    return (0);
}

int main(int ac, char **av, char **env)
{   
    (void)av;
    if (ac == 1)
        return (ft_minishell(env));
    return (0);
}