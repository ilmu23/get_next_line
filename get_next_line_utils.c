/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:24:44 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/06 19:42:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
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

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	asize;
	char	*out;

	if (!s)
		return (NULL);
	if (*s)
		asize = ft_strlen(s) + 1;
	else
		asize = 1;
	out = ft_calloc(asize, sizeof(char));
	if (!out)
		return (NULL);
	if (asize == 1)
		return (out);
	i = 0;
	while (i < asize - 1)
		out[i++] = *s++;
	return (out);
}

char	*ft_strnjoin(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*out;

	if (s1)
		out = ft_calloc(ft_strlen(s1) + n + 1, sizeof(char));
	else
		out = ft_calloc(n + 1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			out[i++] = s1[j++];
	while (n > 0)
	{
		out[i++] = *s2++;
		n--;
	}
	out[i] = *s2;
	if (s1)
		free(s1);
	return (out);
}

size_t	checknewline(char *buf, char **out)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	if (i < BUFFER_SIZE)
		*out = ft_strnjoin(*out, buf, i);
	else
		*out = ft_strnjoin(*out, buf, BUFFER_SIZE);
	return (i);
}