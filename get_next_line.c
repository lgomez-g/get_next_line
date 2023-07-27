/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-g <lgomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:17:07 by lgomez-g          #+#    #+#             */
/*   Updated: 2023/07/27 11:54:13 by lgomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			index;

	line = NULL;
	index = 0;
	if (fd < 0)
	{
		while (buffer[index])
			buffer[index++] = '\0';
		return (NULL);
	}
	while (buffer[0] || (read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_manage_buffer(buffer))
			break ;
	}
	return (line);
}
