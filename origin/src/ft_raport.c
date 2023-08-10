#include "../inc/zoro.h"

void ft_data(t_env **head)
{
    t_env *current;

    current = *head;
    while (current)
    {
        printf("[%s]\n", current->env);
        current = current->next;
    }
}