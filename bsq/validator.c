/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynouveau <ynouveau@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:31:28 by ynouveau          #+#    #+#             */
/*   Updated: 2026/05/27 15:18:14 by ynouveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_bool	is_printable(char c)
{
	return (32 <= c && c <= 126);
}

// Checks if free_c, fill_c and obstacle_c are:
// 1. printable characters
// 2. not duplicates
t_bool	has_valid_state_characters(t_state *state)
{
	t_bool	is_valid;

	is_valid = (is_printable(state->free_c) && is_printable(state->obstacle_c)
			&& is_printable(state->fill_c) && state->free_c != state->obstacle_c
			&& state->obstacle_c != state->fill_c
			&& state->free_c != state->fill_c);
	return (is_valid);
}

t_bool	parse_state_row(t_state *state, char *first_line, int len_i)
{
	int	i;
	int	int_max_stop;

	i = 0;
	int_max_stop = INT_MAX_LIMIT / 10;
	while (i < len_i - 3)
	{
		if ('0' > first_line[i] || first_line[i] > '9')
			return (FALSE);
		if (state->row > int_max_stop || (state->row == int_max_stop
				&& (first_line[i] - '0') > 7))
			return (FALSE);
		state->row = state->row * 10 + (first_line[i] - '0');
		i++;
	}
	return (state->row > 0);
}

t_bool	has_trailing_characters(int file_descriptor)
{
	char	trail;

	return (read(file_descriptor, &trail, 1) > 0);
}
