/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:16:10 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/10 03:39:43 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

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
