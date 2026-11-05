/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lensauva <lensauva@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:06:20 by lensauva          #+#    #+#             */
/*   Updated: 2026/11/05 15:27:32 by lensauva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

char	*ft_strnstr(const char *big, const char *little, unsigned int len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
unsigned int	ft_strlen(const char *str);
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size);
int	ft_memcmp(const void *s1, const void *s2, unsigned int n);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
void	*ft_memmove(void *dest, const void *src, unsigned int n);
void	*ft_memchr(const void *s, int c, unsigned int n);
void	*ft_memset(void *s, int c, unsigned int n);
int	ft_toupper(int c);
int	ft_tolower(int c);

#endif
