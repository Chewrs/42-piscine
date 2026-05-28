/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynouveau <ynouveau@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:23:49 by ynouveau          #+#    #+#             */
/*   Updated: 2026/05/27 15:45:44 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_bool	increase_buffer_capacity(int *buffer_capacity, t_state *state)
{
	int		i;
	char	*tmp_row;

	*buffer_capacity *= 2;
	tmp_row = malloc(*buffer_capacity * sizeof(char));
	if (!tmp_row)
		return (FALSE);
	i = 0;
	while (i < state->col)
	{
		tmp_row[i] = state->map[0][i];
		i++;
	}
	free(state->map[0]);
	state->map[0] = tmp_row;
	return (TRUE);
}

t_bool	copy_row_buffer_to_map(char *row_buffer, t_state *state, int row_i)
{
	int	col_i;

	col_i = 0;
	while (col_i < state->col)
	{
		if (row_buffer[col_i] != state->free_c
			&& row_buffer[col_i] != state->obstacle_c)
			return (FALSE);
		state->map[row_i][col_i] = row_buffer[col_i];
		col_i++;
	}
	return (TRUE);
}

t_bool	fix_first_row(t_state *state)
{
	char	*exact_row;
	int		col_i;

	exact_row = malloc(state->col * sizeof(char));
	if (!exact_row)
		return (FALSE);
	col_i = 0;
	while (col_i < state->col)
	{
		exact_row[col_i] = state->map[0][col_i];
		col_i++;
	}
	free(state->map[0]);
	state->map[0] = exact_row;
	return (TRUE);
}

t_bool	init_map_second_line(t_state *state, int *buffer_capacity)
{
	int	i;

	state->map = malloc((state->row + 1) * sizeof(char *));
	if (!state->map)
		return (FALSE);
	i = 0;
	while (i <= state->row)
	{
		state->map[i] = NULL;
		i++;
	}
	*buffer_capacity = 8;
	state->map[0] = malloc(*buffer_capacity * sizeof(char));
	if (!state->map[0])
		return (FALSE);
	state->col = 0;
	return (TRUE);
}

t_bool	alloc_row_buffers(t_state *state, int row_i, char **row_buffer)
{
	state->map[row_i] = malloc(state->col * sizeof(char));
	*row_buffer = malloc((state->col + 1) * sizeof(char));
	if (!state->map[row_i] || !*row_buffer)
	{
		free(*row_buffer);
		return (FALSE);
	}
	return (TRUE);
}
