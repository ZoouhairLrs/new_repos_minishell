#include "../inc/zoro.h"

int ft_typeof_error(int type, int *exit, int value, int ret)
{
    *exit = value;
    ft_message(type);
    return (ret);
}

void ft_free(char *str1, char *str2)
{
    if (str1)
        free(str1);
    if (str2)
        free(str2);
}

void ft_start_herdoc(int file, char *delimiter, int *exit_t, t_env *env)
{
    int len;
    char *input;

    while (1)
    {
        input = readline("> ");
        len = ft_strlen(delimiter);
        if (!ft_strncmp(input, delimiter, len))
            break ;
        ft_type_expand(&input, exit_t, env);
        ft_putstr_fd(input, file);
        ft_free(input, NULL);
		ft_putchar_fd('\n', file);
    }
    close(file);
    ft_free(input, delimiter);
    exit(EXIT_SUCCESS);
}

int ft_handler(pid_t child, int *exit_t)
{
    if (waitpid(child, exit_t, 0) == -1)
        return (ft_typeof_error(6, exit_t, 0, 0));
    if (!(*exit_t))
        return (TRUE);
    if (WIFSIGNALED(*exit_t))
    {
        if (WTERMSIG(*exit_t) == SIGINT)
            ft_putchar_fd('\n', STDOUT_FILENO);
        else if (WTERMSIG(*exit_t) == SIGQUIT)
            ft_putstr_fd("Quit\n", STDOUT_FILENO);
        *exit_t = WTERMSIG(*exit_t) + INTERRUPT;
        return (TRUE);
    }
    if (WEXITSTATUS(*exit_t))
        return (FALSE);
    return (FALSE);
}

static void ft_execute_herd(char *delimiter, int *exit_t, t_env *env)
{
    int file;
    char *n_f;
    char *tmp_file;
    static int n_file;

    n_f = ft_itoa(++n_file);
    tmp_file = ft_strdup(ft_strjoin("/tmp/", n_f));
    file = open(tmp_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (file == -1)
    {
        ft_typeof_error(5, 0, 0, 0);
        exit(EXIT_FAILURE);
    }
    ft_start_herdoc(file, delimiter, exit_t, env);
    ft_free_count(n_f, tmp_file);
}


int ft_fork_herdoc(char *delimiter, int *exit_t, t_env *env)
{
    pid_t child;

    child = fork();
    if (child == -1)
        return (ft_typeof_error(4, exit_t, 1, 0));
    ft_herdoc_quit();
    ft_herdoc_interrupt(child);
    if (!child)
        ft_execute_herd(delimiter, exit_t, env);
    else
        return (ft_handler(child, exit_t));
    return (FALSE);
}