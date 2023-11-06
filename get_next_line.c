/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:18:13 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/07 00:25:04 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	size_t			reads;
	int				rv;
	char			*out;

	out = NULL;
	reads = 0;
	rv = BUFFER_SIZE;
	while (rv > 0 && (*buf || reads == 0))
	{
		if (*buf && reads > 0)
			bufcopy(buf, &out);
		if (out)
			if (out[ft_strclen(out, '\0') - 1] == '\n')
				return (out);
		rv = read(fd, buf, BUFFER_SIZE);
		if (rv > 0)
			reads++;
	}
	if (out)
		if (ft_strclen(out, '\0') == reads)
			return (out);
	return (NULL);
}
