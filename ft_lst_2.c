/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:33:39 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/24 15:33:49 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr && ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_begin;
	t_list	*lst_new;
	void	*content_new;

	if (f == 0 || del == 0)
		return (0);
	lst_begin = 0;
	while (lst)
	{
		content_new = f(lst->content);
		lst_new = ft_lstnew(content_new);
		if (content_new == 0 || lst_new == 0)
		{
			ft_lstclear(&lst_begin, del);
			return (0);
		}
		ft_lstadd_back(&lst_begin, lst_new);
		lst = lst->next;
	}
	return (lst_begin);
}
