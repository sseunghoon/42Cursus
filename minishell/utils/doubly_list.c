#include "../minishell.h"

t_dlist	*get_first(t_dlist *curr)
{
	while (curr && curr->prev)
		curr = curr->prev;
	return (curr);
}

t_dlist	*create_list(void)
{
	t_dlist	*new;

	new = ft_calloc(1, sizeof (t_dlist));
	if (!new)
		exit(1);
	return (new);
}

void	add_list(t_dlist **list, char *str)
{
	t_dlist	*new;
	t_dlist	*curr;

	curr = *list;
	if (*list == NULL)
	{
		*list = create_list();
		(*list)->token = ft_strdup(str);
		return ;
	}
	while (curr->next)
		curr = curr->next;
	new = create_list();
	new->token = ft_strdup(str);
	curr->next = new;
	new->next = NULL;
	new->prev = curr;
}

void	delete_dlist(t_dlist *list)
{
	t_dlist	*curr;
	t_dlist	*tmp;

	curr = list;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp->token);
		free(tmp);
	}
}

int	delete_node(t_dlist **list, t_dlist *node)
{
	t_dlist	*tmp;

	tmp = *list;
	while (tmp && tmp != node)
		tmp = tmp->next;
	if (tmp == 0)
		return (0);
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	else
		*list = (*list)->next;
	tmp->next = 0;
	tmp->prev = 0;
	free(tmp->token);
	tmp->token = 0;
	free(tmp);
	return (1);
}
