void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	curr = *lst;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		while (curr != NULL)
		{
			if (curr->next == NULL)
			{
				curr->next = new;
				return ;
			}
			curr = curr->next;
		}
	}
}
