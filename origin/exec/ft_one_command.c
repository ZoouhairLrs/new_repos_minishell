#include "../inc/zoro.h"

int ft_new_duplicate(int fd, int new)
{
    dup2(fd, new);
    close(fd);
    return (TRUE);
}

int     ft_dup_type(int file_desc[2], int type)
{
    if (file_desc[INPUT] == OFF && !type)
        file_desc[INPUT] = dup(STDIN_FILENO);
    else if (file_desc[OUTPUT] == OFF && type)
        file_desc[OUTPUT] = dup(STDOUT_FILENO);
    return (TRUE);
}

int     ft_open_in(char *in_file, int file_desc[2], int *exit_t)
{
    int fd;

    ft_dup_type(file_desc, 0);
    fd = open(in_file, O_RDONLY, 0400);
    if (!fd)
    {
        *exit_t = 1;
        ft_message(5);
        return (ft_new_duplicate(file_desc[INPUT], INPUT));
    }
    ft_new_duplicate(fd, 0);
    ft_free_count(in_file, NULL);
    return (0);
}

void    ft_one_command(char *input, int *exit_t, t_env *env)
{
    int file_desc[2];
    char *in_file;

    (void)env;
    (void)exit_t;
    file_desc[INPUT] = OFF;
    file_desc[OUTPUT] = OFF;
    in_file = ft_last_file(input);
    if (in_file)
        ft_open_in(in_file, file_desc, exit_t);
    
}

/*
void   ft_implement_redirec(char *input)
{

}

*/


