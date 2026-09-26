void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	curr = *lst;
	if (lst == NULL || *lst == NULL)
		return ;
	while (curr != NULL)
	{
		next = curr;
		del(curr->content);
		curr = curr->next;
		free(next);
	}
	(*lst) = NULL;
}
