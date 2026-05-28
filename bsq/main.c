/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynouveau <ynouveau@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:31:49 by ynouveau          #+#    #+#             */
/*   Updated: 2026/05/27 15:38:15 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	init_state(t_state *state)
{
	state->map = NULL;
	state->free_c = '\0';
	state->obstacle_c = '\0';
	state->fill_c = '\0';
	state->row = 0;
	state->col = 0;
	state->start_point[0] = 0;
	state->start_point[1] = 0;
	state->max_sq_size = 0;
	state->tmp_row = NULL;
	state->top_left = 0;
	state->old_top = 0;
}

void	free_state(t_state *state)
{
	int	i;

	if (!state || !state->map)
		return ;
	i = 0;
	while (state->map[i] != NULL)
	{
		if (state->map[i])
			free(state->map[i]);
		i++;
	}
	if (state->tmp_row)
		free(state->tmp_row);
	free(state->map);
	state->map = NULL;
}

t_bool	process_map(int file_descriptor, t_state *state)
{
	t_bool	has_error;

	init_state(state);
	has_error = FALSE;
	if (!read_map(file_descriptor, state))
	{
		has_error = TRUE;
	}
	if (!has_error && !solve(state))
	{
		has_error = TRUE;
	}
	if (!has_error)
	{
		print_map(*state);
	}
	if (file_descriptor != 0 && close(file_descriptor) == -1)
		has_error = TRUE;
	free_state(state);
	return (!has_error);
}

int	process_files(int argc, char **argv, t_state *state)
{
	int	file_descriptor;
	int	map_i;

	map_i = 1;
	while (map_i < argc)
	{
		file_descriptor = open(argv[map_i], O_RDONLY);
		if (file_descriptor == -1 || !process_map(file_descriptor, state))
			write(1, "map error\n", 10);
		if (map_i + 1 != argc)
			write(1, "\n", 1);
		map_i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_state	s;
	t_state	*state;

	state = &s;
	if (argc == 1)
	{
		if (!process_map(0, state))
			write(1, "map error\n", 10);
	}
	else
		process_files(argc, argv, state);
	return (0);
}
