/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:18:13 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/06 19:43:02 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	static size_t	i = 0;
	char			*out;
	int				rv;

	out = NULL;
	if (i < BUFFER_SIZE && i > 0)
		out = ft_strdup(buf + i + 1);
	if (!out && i > 0)
		return (NULL);
	rv = BUFFER_SIZE;
	while (rv > 0)
	{
		rv = read(fd, buf, BUFFER_SIZE);
		i = checknewline(buf, &out);
		if (i < BUFFER_SIZE)
			return (out);
		if (!out)
			return (NULL);
	}
	return (out);
}
