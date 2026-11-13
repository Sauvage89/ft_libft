/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:16:44 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/13 12:51:52 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
