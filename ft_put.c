/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:46:59 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/27 21:03:51 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdint.h>

ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	ret;
	size_t	len;

	len = ft_strlen(s);
	ret = ft_putstr_fd(s, fd);
	if (ret < (ssize_t)len)
		return (ERROR_WRITE);
	if (write(fd, "\n", 1) != 1)
		return (ERROR_WRITE);
	return (ret + 1);
}

ssize_t	ft_putnbr_fd(long n, int fd)
{
	char	buffer[12];
	long	n_save;
	uint8_t	len;

	len = 0;
	n_save = n;
	while (!n_save)
	{
		n_save /= 10;
		len++;
	}
	if (n < 0)
	{
		buffer[0] = '-';
		len++;
	}
	buffer[len] = 0;
	while (!n)
	{
		len--;
		buffer[len] = n % 10 + '0';
		n /= 10;
	}
	return (ft_putstr_fd(buffer, fd));
}

ssize_t	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	ret;
	size_t	len;

	if (!s)
		return (ERROR_PARAMPTR_NULL);
	len = ft_strlen(s);
	ret = write(fd, s, len);
	if (ret < (ssize_t)len)
		return (ERROR_WRITE);
	return (ret);
}
