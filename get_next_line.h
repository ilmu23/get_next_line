/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:20:05 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/06 22:27:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
size_t	ft_strlen(char *s);
size_t	checknewline(char *buf, char **out);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strnjoin(char *s1, char *s2, size_t n);
char	*bufreset(char *buf, size_t start);

#endif
