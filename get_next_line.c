/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncouton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:00:10 by ncouton           #+#    #+#             */
/*   Updated: 2024/03/19 19:47:45 by ncouton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *line)
{
	char	*buff;
	int		byte_readed;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	byte_readed = 1;
	while (!ft_strchr(line, '\n') && byte_readed != 0)
	{
		byte_readed = read(fd, buff, BUFFER_SIZE);
		if (byte_readed == -1)
			return (free(buff), NULL);
		buff[byte_readed] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_read_line(fd, line);
	if (!line)
		return (NULL);
	buff = ft_buffer(line);
	line = ft_read_new_line(line);
	return (buff);
}
