/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:07:40 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:45:58 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	err_illegal(char *argv[])
{
	ft_putstr(basename(argv[0]), 2, 0);
	ft_putstr(": invalid number of bytes: '", 2, 0);
	ft_putstr(argv[2], 2, 0);
	ft_putstr("'\n", 2, 0);
	return (1);
}

int	err_option(char *argv[])
{
	ft_putstr(basename(argv[0]), 2, 0);
	ft_putstr(": option requires an argument -- c\n", 2, 0);
	ft_putstr("usage: ", 2, 0);
	ft_putstr(basename(argv[0]), 2, 0);
	ft_putstr(" [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n", 2, 0);
	return (1);
}

int	err_open(char *program, char *filename)
{
	ft_putstr(basename(program), 2, 0);
	ft_putstr(": cannot open '", 2, 0);
	ft_putstr(filename, 2, 0);
	ft_putstr("' for reading: ", 2, 0);
	ft_putstr(strerror(errno), 2, 0);
	ft_putchar('\n', 2);
	return (1);
}

int	err_read(char *program, char *filename)
{
	ft_putstr(basename(program), 2, 0);
	ft_putstr(": error reading '", 2, 0);
	ft_putstr(filename, 2, 0);
	ft_putstr("': ", 2, 0);
	ft_putstr(strerror(errno), 2, 0);
	ft_putchar('\n', 2);
	return (1);
}
