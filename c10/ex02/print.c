/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:07:58 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:07:58 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_header(char *filename)
{
	ft_putstr("==> ", 1, 0);
	ft_putstr(filename, 1, 0);
	ft_putstr(" <==", 1, 0);
}

void	print_bytes(char *buf, int total, int bytes)
{
	int	i;

	if (total < bytes)
	{
		write(1, buf, total);
		return ;
	}
	i = total % bytes;
	write(1, buf + i, bytes - i);
	write(1, buf, i);
}
