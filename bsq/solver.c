/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:57:26 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/26 15:48:54 by ynouveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

int	init_tmp_row(t_state *s)
{
	int	i;

	i = 0;
	s->tmp_row = malloc(sizeof(int) * s->col);
	if (!s->tmp_row)
		return (0);
	i = 0;
	while (i < s->col)
		s->tmp_row[i++] = 0;
	s->max_sq_size = 0;
	s->start_point[0] = 0;
	s->start_point[1] = 0;
	return (1);
}

void	solve_cell(t_state *s, int row, int col)
{
	s->old_top = s->tmp_row[col];
	if (s->map[row][col] != s->free_c)
		s->tmp_row[col] = 0;
	else if (row == 0 || col == 0)
		s->tmp_row[col] = 1;
	else
	{
		s->tmp_row[col] = 1 + min3(s->tmp_row[col], s->tmp_row[col - 1],
				s->top_left);
	}
	if (s->tmp_row[col] > s->max_sq_size)
	{
		s->max_sq_size = s->tmp_row[col];
		s->start_point[0] = row - (s->tmp_row[col] - 1);
		s->start_point[1] = col - (s->tmp_row[col] - 1);
	}
	s->top_left = s->old_top;
}

int	solve(t_state *s)
{
	int	row;
	int	col;

	if (!init_tmp_row(s))
		return (0);
	row = 0;
	while (row < s->row)
	{
		col = 0;
		s->top_left = 0;
		while (col < s->col)
		{
			solve_cell(s, row, col);
			col++;
		}
		row++;
	}
	free(s->tmp_row);
	s->tmp_row = NULL;
	return (1);
}
