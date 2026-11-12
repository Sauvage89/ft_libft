/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 01:00:55 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/12 13:16:31 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_try_cpy;
	size_t	i;

	if (dst == 0 || src == 0)
		return (0);
	len_try_cpy = 0;
	while (src[len_try_cpy])
		len_try_cpy++;
	if (size == 0)
		return (len_try_cpy);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len_try_cpy);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

void	verif_original(char *src_content,
	int len_src, char *dest_content, int len_dest, int len)
{
	char	protect1[1024];
	char	*src;
	char	protect2[1024];
	char	*dest;
	char	protect3[1024];

	src = (char *)malloc(sizeof(char) * (len_src + 1));
	dest = (char *)malloc(sizeof(char) * (len_dest + 1));
	strcpy(src, src_content);
	strcpy(dest, dest_content);
	printf("preview\tsrc='%s' dest='%s' len=%i\n", src, dest, len);
	len = strlcpy(dest, src, len);
	printf("after\tsrc='%s' dest='%s' len=%i\n", src, dest, len);
}

void	verif_my(char *src_content,
	int len_src, char *dest_content, int len_dest, int len)
{
	char	protect1[1024];
	char	*src;
	char	protect2[1024];
	char	*dest;
	char	protect3[1024];

	src = (char *)malloc(sizeof(char) * (len_src + 1));
	dest = (char *)malloc(sizeof(char) * (len_dest + 1));
	strcpy(src, src_content);
	strcpy(dest, dest_content);
	printf("preview\tsrc='%s' dest='%s' len=%i\n", src, dest, len);
	len = ft_strlcpy(dest, src, len);
	printf("after\tsrc='%s' dest='%s' len=%i\n", src, dest, len);
}

void	reset_str(char *str)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		str[i] = 0;
		i++;
	}
}

int	main()
{
	char	src[1024];
	char	dest[1024];
	int		len_src;
	int		len_dest;
	int		len;
	int		i_src;
	int		i_dest;

	len = 3;

	reset_str(src);
	reset_str(dest);
	strcpy(src, strcat(src, "aa"));
	strcpy(dest, strcat(dest, "bbb"));
	verif_original(src, len_src, dest, len_dest, len);


	reset_str(src);
	reset_str(dest);
	strcpy(src, strcat(src, "aa"));
	strcpy(dest, strcat(dest, "bbb"));
	verif_my(src, len_src, dest, len_dest, len);
}

int	main()
{
	char	src[1024];
	char	dest[1024];
	int		len_src;
	int		len_dest;
	int		len;
	int		i_src;
	int		i_dest;

	len = 0;
	while (len < 12)
	{
		len_src = 0;
		while (len_src < 13)
		{
			len_dest = 0;
			while (len_dest < 13)
			{
				i_src = 0;
				reset_str(src);
				while (i_src < 11)
				{
					strcpy(src, strcat(src, "a"));
					i_dest = 0;
					reset_str(dest);
					while (i_dest < 11)
					{
						strcpy(dest, strcat(dest, "b"));
						verif_my(src, len_src, dest, len_dest, len);
						i_dest++;
					}
					i_src++;
				}
				len_dest++;
			}
			len_src++;
		}
		len++;
	}
}*/
