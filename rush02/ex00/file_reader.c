/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhunhan <tkhunhan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:23:20 by tkhunhan          #+#    #+#             */
/*   Updated: 2026/05/23 14:53:22 by tkhunhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	get_file_size(char *file_path)
{
	int		fd;
	int		size;
	char	c;

	size = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		size++;
	}
	close(fd);
	return (size);
}

char	*read_dict(char *file_path)
{
	int		fd;
	int		size;
	char	*buffer;

	size = get_file_size(file_path);
	if (size == -1 || size == 0)
		return (NULL);
	buffer = (char *)malloc((size + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (NULL);
	}
	read(fd, buffer, size);
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}
