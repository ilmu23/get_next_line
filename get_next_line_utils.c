/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:24:44 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/07 00:26:54 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	asize;
	void	*out;

	asize = count * size;
	if (count < asize && size < asize)
		return (NULL);
	out = malloc(asize);
	if (!out)
		return (NULL);
	i = 0;
	while (i < asize)
		*(char *)(out + i++) = '\0';
	return (out);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*out;

	if (s1)
		len1 = ft_strclen(s1, '\0');
	else
		len1 = 0;
	len2 = ft_strclen(s2, '\0');
	out = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			out[i++] = *s1++;
	while (*s2)
		out[i++] = *s2++;
	return (out);
}

char	*bufshift(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	src = dst + n;
	while (*src)
		*src++ = '\0';
	return (dst);
}

void	bufcopy(char *buf, char **out)
{
	size_t	i;
	size_t	linelen;
	size_t	buflen;
	char	*cpy;
	char	*tmp;

	buflen = ft_strclen(buf, '\0');
	linelen = ft_strclen(buf, '\n');
	if (linelen < buflen)
		linelen++;
	cpy = ft_calloc(linelen + 1, sizeof(char));
	if (!cpy)
		return ;
	i = 0;
	while (i < linelen)
	{
		cpy[i] = buf[i];
		i++;
	}
	bufshift(buf, &buf[linelen], buflen - linelen);
	tmp = ft_strjoin(*out, cpy);
	free(*out);
	free(cpy);
	*out = tmp;
}
