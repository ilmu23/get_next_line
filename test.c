/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:08:29 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/06 22:35:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
		return (1);
	if (*argv[1] == '0')
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
//		if (BUFFER_SIZE == 42)
//		{
//			char c = 0; 
//			read(fd, &c, 1);
//		}
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (fd > 2)
		close(fd);
	return (0);
}
