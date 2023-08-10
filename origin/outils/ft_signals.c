#include "../inc/zoro.h"

void handler_int(int sig)
{
    (void)sig;
    printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void ft_set_signals(void)
{
    struct sigaction sa_int;
    struct sigaction sa_quit;

    sa_int.sa_handler = &handler_int;
    sa_int.sa_flags = 0;
    sigemptyset(&sa_int.sa_mask);
    sigaction(SIGINT, &sa_int, NULL);
    sa_quit.sa_handler = SIG_IGN;
    sa_quit.sa_flags = 0;
    sigemptyset(&sa_quit.sa_mask);
    sigaction(SIGQUIT, &sa_quit, NULL);
}

void ft_herdoc_interrupt(pid_t pid)
{
    struct sigaction sa_int;

    if (!pid)
        sa_int.sa_handler = SIG_DFL;
    if (pid)
        sa_int.sa_handler = SIG_IGN;
    sa_int.sa_flags = 0;
    sigemptyset(&sa_int.sa_mask);
    sigaction(SIGINT, &sa_int, NULL);
}

void ft_herdoc_quit(void)
{
    struct sigaction sa_int;

    sa_int.sa_handler = SIG_IGN;
    sa_int.sa_flags = 0;
    sigemptyset(&sa_int.sa_mask);
    sigaction(SIGQUIT, &sa_int, NULL);
}