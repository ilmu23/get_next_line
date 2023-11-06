/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:18:13 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/06 22:25:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	static size_t	i = 0;
	static int		rv = 1;
	char			*out;

	out = NULL;
	if (i < BUFFER_SIZE && i > 0)
		out = bufreset(buf, i + 1);
	if (!out && i > 0)
		return (NULL);
	while (rv > 0)
	{
		rv = read(fd, buf, BUFFER_SIZE);
		if (rv > 0)
			i = checknewline(buf, &out);
		if (buf[i] == '\n')
			return (out);
	}
	if (i == (size_t)rv)
		return (out);
	if (out)
		free(out);
	return (NULL);
}
