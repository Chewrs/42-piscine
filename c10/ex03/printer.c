/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:08:47 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:08:47 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_line(t_dump *dump, unsigned char *buf, int size)
{
	dump->has_output = 1;
	print_offset(dump->offset);
	write(1, "  ", 2);
	print_hex_section(buf, size);
	write(1, " |", 2);
	print_ascii_section(buf, size);
	write(1, "|\n", 2);
}

void	print_ascii_section(unsigned char *buf, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buf[i] >= 32 && buf[i] <= 126)
			write(1, &buf[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_final_offset(t_dump *dump)
{
	if (dump->has_output)
	{
		print_offset(dump->offset);
		write(1, "\n", 1);
	}
}
