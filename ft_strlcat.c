/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:38:17 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/05 14:47:01 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	len_src;
	unsigned int	len_dst;
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	len_src = 0;
	while (src[len_src])
		len_src++;
	len_dst = 0;
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	if (len_dst >= size)
		return (len_src + len_dst);
	i = 0;
	while (src[i] && i < size - len_dst - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_src + len_dst);
}
/*
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>

void	verif_original(const char *src_content, int len_src, const char *dest_content, int len_dest, int len)
{
	char	protect1[10];
	char	src[100];
	char	protect2[10];
	char	dest[100];
	char	protect3[10];

	strcpy(src, src_content);
	strcpy(dest, dest_content);
	len = strlcat(dest, src, len);
	printf("after\tsrc='%s' dest='%s' len=%i\n", src, dest, len);
}

void	verif_my(char *src_content, int len_src, char *dest_content, int len_dest, int len)
{
	char	protect1[1024];
	char	src[100];
	char	protect2[1024];
	char	dest[100];
	char	protect3[1024];

	strcpy(src, src_content);
	strcpy(dest, dest_content);
	len = ft_strlcat(dest, src, len);
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
	char	src_c[1024];
	char	dest_c[1024];
	int		len_src;
	int		len_dest;
	int		len;
	int		i_src;
	int		i_dest;
	

	len = 0;
	while (len < 15)
	{
		strcpy(src_c, "aaaaaaaa");
		strcpy(dest_c, "bbbb");

		printf("len is %i\n", len);
		reset_str(src);
		reset_str(dest);
		printf("or ");
		strcpy(src, src_c);
		strcpy(dest, dest_c);
		verif_original(src, len_src, dest, len_dest, len);


		reset_str(src);
		reset_str(dest);
		printf("my ");
		strcpy(src, src_c);
		strcpy(dest, dest_c);
		verif_my(src, len_src, dest, len_dest, len);
		len++;
	}
	return (0);
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
						//verif_original(src, len_src, dest, len_dest, len);
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
}
*/
