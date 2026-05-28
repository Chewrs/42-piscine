/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynouveau <ynouveau@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:04:37 by ynouveau          #+#    #+#             */
/*   Updated: 2026/05/27 15:48:33 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_bool	read_first_line(int file_descriptor, t_state *state);
t_bool	read_second_line(int file_descriptor, t_state *state);
t_bool	read_remaining_lines(int file_descriptor, t_state *state);

t_bool	read_map(int file_descriptor, t_state *state)
{
	state->map = NULL;
	state->row = 0;
	state->col = 0;
	if (!read_first_line(file_descriptor, state))
		return (FALSE);
	if (!read_second_line(file_descriptor, state))
		return (FALSE);
	if (!read_remaining_lines(file_descriptor, state))
		return (FALSE);
	return (TRUE);
}

// Reads the first line to get:
// 1. free_c, obstacle_c, fill_c
// 2. row (height)
// And it also validates these values.
// Using a buffer of size 14 because the first line can only be
// 10 digits max (INT_MAX) + 3 characters (free, obstacle, fill)
// and a newline, so 14 characters
t_bool	read_first_line(int file_descriptor, t_state *state)
{
	char	first_line[14];
	int		len_i;

	len_i = 0;
	while (len_i < 14 && read(file_descriptor, &first_line[len_i], 1) > 0)
	{
		if (first_line[len_i] == '\n')
			break ;
		len_i++;
		if (len_i > 14)
			return (FALSE);
	}
	if (len_i < 4)
	{
		return (FALSE);
	}
	state->free_c = first_line[len_i - 3];
	state->obstacle_c = first_line[len_i - 2];
	state->fill_c = first_line[len_i - 1];
	if (!has_valid_state_characters(state))
		return (FALSE);
	if (!parse_state_row(state, first_line, len_i))
		return (FALSE);
	return (TRUE);
}

// Parses the first row of the map and get the col (width)
t_bool	read_second_line(int file_descriptor, t_state *state)
{
	int		buffer_capacity;
	char	current_c;

	if (!init_map_second_line(state, &buffer_capacity))
		return (FALSE);
	while (read(file_descriptor, &current_c, 1) > 0)
	{
		if (current_c == '\n')
			break ;
		if (current_c != state->free_c && current_c != state->obstacle_c)
			return (FALSE);
		if (state->col >= buffer_capacity)
			if (!increase_buffer_capacity(&buffer_capacity, state))
				return (FALSE);
		state->map[0][state->col] = current_c;
		state->col++;
	}
	if (state->col == 0)
		return (FALSE);
	return (fix_first_row(state));
}

t_bool	read_one_remaining_line(int fd, t_state *state, int row_i)
{
	int		read_bytes;
	char	*row_buffer;

	row_buffer = NULL;
	if (!alloc_row_buffers(state, row_i, &row_buffer))
		return (FALSE);
	read_bytes = read(fd, row_buffer, state->col + 1);
	if (read_bytes != state->col + 1 || row_buffer[state->col] != '\n')
	{
		free(row_buffer);
		return (FALSE);
	}
	if (!copy_row_buffer_to_map(row_buffer, state, row_i))
	{
		free(row_buffer);
		return (FALSE);
	}
	free(row_buffer);
	return (TRUE);
}

t_bool	read_remaining_lines(int file_descriptor, t_state *state)
{
	int	row_i;

	row_i = 1;
	while (row_i < state->row)
	{
		state->map[row_i] = NULL;
		if (!read_one_remaining_line(file_descriptor, state, row_i))
			return (FALSE);
		row_i++;
	}
	state->map[row_i] = NULL;
	return (!has_trailing_characters(file_descriptor));
}
