/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:08:02 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:37:35 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	read_ring(int fd, char *buff, int bytes)
{
	char	c;
	int		total;
	int		read_size;

	total = 0;
	read_size = read(fd, &c, 1);
	while (read_size > 0)
	{
		buff[total % bytes] = c;
		total++;
		read_size = read(fd, &c, 1);
	}
	if (read_size == -1)
	{
		return (-1);
	}
	return (total);
}

int	ft_tail_fd(int fd, int bytes)
{
	char	*buff;
	int		total;

	buff = malloc(bytes);
	if (!buff)
		return (0);
	total = read_ring(fd, buff, bytes);
	if (total == -1)
	{
		free(buff);
		buff = NULL;
		return (0);
	}
	print_bytes(buff, total, bytes);
	free(buff);
	buff = NULL;
	return (1);
}

int	ft_tail_stdin(int bytes)
{
	if (ft_tail_fd(0, bytes) == 0)
		return (1);
	return (0);
}

int	ft_tail_file(char *program, char *filename, int bytes, t_newline newline)
{
	int	fd;
	int	result;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		err_open(program, filename);
		return (0);
	}
	if (newline.multi == 1)
	{
		if (newline.second == 1)
			write(1, "\n", 1);
		print_header(filename);
		write(1, "\n", 1);
	}
	result = ft_tail_fd(fd, bytes);
	if (close(fd) == -1)
		result = 0;
	if (result == 0)
	{
		err_read(program, filename);
		return (0);
	}
	return (1);
}

int	ft_tail_files(int argc, char *argv[], int bytes)
{
	int			i;
	int			error;
	t_newline	newline;

	newline.second = 0;
	newline.multi = 0;
	error = 0;
	if (argc > 4)
		newline.multi = 1;
	i = 3;
	while (i < argc)
	{
		if (ft_tail_file(argv[0], argv[i], bytes, newline) == 0)
			error = 1;
		else
			newline.second = 1;
		i++;
	}
	return (error);
}
