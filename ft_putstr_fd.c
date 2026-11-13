/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:49:26 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/13 12:29:23 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned long	ptr;
	unsigned long	len;

	if (s)
	{
		len = 0;
		while (s[len])
			len++;
		ptr = (unsigned long)ft_putstr_fd;
		while (*(unsigned long *)ptr != 0xc3050f58016a)
			ptr++;
		((t_write_func)ptr)(fd, s, len);
	}
}
/*
int	main(void)
{
	ft_putstr_fd("mention a erwoan\nson git pour les curieux :
https://github.com/CyberOneFR/Semantic-Shellcode-Injection/tree/main\n", 1);
	return (0);
}*/
