/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:08:21 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:08:21 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	not_match(t_dump *dump, unsigned char *buf, int size)
{
	if (size != 16)
		return (1);
	if (!dump->has_prev)
		return (1);
	if (ft_memcmp(dump->prev, buf, 16) != 0)
		return (1);
	if (!dump->in_duplicate)
	{
		write(1, "*\n", 2);
		dump->in_duplicate = 1;
	}
	return (0);
}

void	update_prev_block(t_dump *dump, unsigned char *buf, int size)
{
	if (size == 16)
	{
		ft_memcpy(dump->prev, buf, 16);
		dump->has_prev = 1;
	}
	else
		dump->has_prev = 0;
}

void	flush_pending(t_dump *dump)
{
	if (dump->curr_size > 0)
	{
		print_line(dump, dump->curr, dump->curr_size);
		dump->offset += dump->curr_size;
		dump->curr_size = 0;
	}
}

void	push_byte(t_dump *dump, unsigned char c)
{
	dump->curr[dump->curr_size] = c;
	dump->curr_size++;
	if (dump->curr_size == 16)
	{
		if (not_match(dump, dump->curr, 16))
		{
			dump->has_output = 1;
			print_line(dump, dump->curr, 16);
			dump->in_duplicate = 0;
		}
		update_prev_block(dump, dump->curr, 16);
		dump->offset += 16;
		dump->curr_size = 0;
	}
}
