/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:25:41 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/12 10:14:00 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		del((void *)(*lst)->content);
		*lst = ptr;
	}
}
