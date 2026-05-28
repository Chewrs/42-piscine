/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:06:40 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:06:40 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	no_args(char **argv)
{
	char	buf;
	int		size;

	size = read(0, &buf, 1);
	while (size > 0)
	{
		ft_putchar(buf, 1);
		size = read(0, &buf, 1);
	}
	if (size == -1)
	{
		ft_putstr(basename(argv[0]), 2, 0);
		ft_putstr(": stdin: ", 2, 0);
		ft_putstr(strerror(errno), 2, 0);
		ft_putchar('\n', 2);
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 1)
		no_args(argv);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_file_read(argv[i]) == 0)
			{
				ft_putstr(basename(argv[0]), 2, 0);
				ft_putstr(": ", 2, 0);
				ft_putstr(argv[i], 2, 0);
				ft_putstr(": ", 2, 0);
				ft_putstr(strerror(errno), 2, 0);
				ft_putchar('\n', 2);
			}
			i++;
		}
	}
	return (0);
}
