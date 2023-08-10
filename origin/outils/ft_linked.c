#include "../inc/zoro.h"

t_env	*ft_addnew_env(char *str)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (0);
	new->env = ft_strdup(str);
	new->next = 0;
	return (new);
}

void	ft_addback_env(t_env *new, t_env **head)
{
	t_env	*current;

	current = *head;
	if (*head == 0)
	{
		*head = new;
		return ;
	}
	while (current->next != 0)
		current = current->next;
	current->next = new;
}