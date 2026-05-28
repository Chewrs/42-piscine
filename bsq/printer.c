/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:03:10 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/26 12:32:24 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	is_sq(t_state s, int row, int col)
{
	if (row >= s.start_point[0] && row < s.start_point[0] + s.max_sq_size
		&& col >= s.start_point[1] && col < s.start_point[1] + s.max_sq_size)
	{
		return (1);
	}
	return (0);
}

void	print_map(t_state s)
{
	int	row;
	int	col;

	row = 0;
	while (row < s.row)
	{
		col = 0;
		while (col < s.col)
		{
			if (is_sq(s, row, col))
			{
				write(1, &s.fill_c, 1);
			}
			else
			{
				write(1, &s.map[row][col], 1);
			}
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
