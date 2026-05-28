/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:09:02 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:09:02 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	process_fd(int fd, t_dump *dump)
{
	unsigned char	buf[4096];
	int				bytes_read;
	int				i;

	bytes_read = read(fd, buf, 4096);
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			push_byte(dump, buf[i]);
			i++;
		}
		bytes_read = read(fd, buf, 4096);
	}
	if (bytes_read == -1)
		return (1);
	return (0);
}

int	process_file(char *filename, t_dump *dump)
{
	int	fd;
	int	ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(dump->program_name, filename);
		return (1);
	}
	ret = process_fd(fd, dump);
	if (ret != 0)
		print_error(dump->program_name, filename);
	close(fd);
	return (ret);
}

int	ft_dump_stdin(t_dump *dump)
{
	int	ret;

	ret = process_fd(0, dump);
	flush_pending(dump);
	print_final_offset(dump);
	return (ret);
}

int	ft_dump_files(int argc, char **argv, t_dump *dump)
{
	int	i;
	int	ret;

	i = 2;
	ret = 0;
	while (i < argc)
	{
		if (process_file(argv[i], dump) != 0)
			ret = 1;
		i++;
	}
	flush_pending(dump);
	print_final_offset(dump);
	return (ret);
}
