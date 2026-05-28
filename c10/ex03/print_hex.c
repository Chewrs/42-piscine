/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:08:58 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:08:58 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_offset(unsigned int offset)
{
	char	*base;
	char	result[8];
	int		i;

	base = "0123456789abcdef";
	i = 7;
	while (i >= 0)
	{
		result[i] = base[offset % 16];
		offset = offset / 16;
		i--;
	}
	write(1, result, 8);
}

void	print_hex_byte(unsigned char c)
{
	char	*base;
	char	hex[2];

	base = "0123456789abcdef";
	hex[0] = base[c / 16];
	hex[1] = base[c % 16];
	write(1, hex, 2);
}

void	print_hex_section(unsigned char *buf, int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			print_hex_byte(buf[i]);
		else
			write(1, "  ", 2);
		if (i == 7)
			write(1, "  ", 2);
		else
			write(1, " ", 1);
		i++;
	}
}
