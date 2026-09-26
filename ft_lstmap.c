t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	void	*new_cont;
	t_list	*newlist;

	newlist = NULL;
	while (lst != NULL)
	{
		new_cont = f(lst->content);
		newnode = ft_lstnew(new_cont);
		if (newnode == NULL)
		{
			ft_lstclear (&newlist, del);
			return (NULL);
		}
		ft_lstadd_back (&newlist, newnode);
		lst = lst -> next;
	}
	return (newlist);
}
