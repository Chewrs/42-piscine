/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynouveau <ynouveau@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:53:49 by ynouveau          #+#    #+#             */
/*   Updated: 2026/05/27 15:47:12 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define INT_MAX_LIMIT 2147483647
# define P printf

typedef int	t_bool;

typedef struct s_state
{
	char	**map;
	char	free_c;
	char	obstacle_c;
	char	fill_c;
	int		row;
	int		col;
	int		start_point[2];
	int		max_sq_size;
	int		*tmp_row;
	int		top_left;
	int		old_top;
}			t_state;

void		print_map(t_state s);
int			solve(t_state *s);
int			read_map(int file_descriptor, t_state *state);
void		free_state(t_state *state);
t_bool		has_valid_state_characters(t_state *state);
t_bool		parse_state_row(t_state *state, char *first_line, int len_i);
t_bool		increase_buffer_capacity(int *buffer_capacity, t_state *state);
t_bool		copy_row_buffer_to_map(char *row_buffer, t_state *state, int row_i);
t_bool		has_trailing_characters(int file_descriptor);
t_bool		fix_first_row(t_state *state);
t_bool		alloc_row_buffers(t_state *state, int row_i, char **row_buffer);
t_bool		init_map_second_line(t_state *state, int *buffer_capacity);

#endif
