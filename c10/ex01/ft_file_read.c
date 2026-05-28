/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:06:55 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 13:02:22 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_file_read(char *filepath)
{
	int		file;
	int		size;
	char	buf[29696];

	file = open(filepath, O_RDONLY);
	if (file == -1)
		return (0);
	size = read(file, buf, 29696);
	while (size > 0)
	{
		ft_putstr(buf, 1, size);
		size = read(file, buf, 29696);
	}
	if (size == -1)
	{
		close(file);
		return (0);
	}
	close(file);
	return (1);
}
