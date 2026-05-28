/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:09:29 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:09:29 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_dump(t_dump *dump, char *program_name)
{
	dump->has_output = 0;
	dump->offset = 0;
	dump->curr_size = 0;
	dump->has_prev = 0;
	dump->in_duplicate = 0;
	dump->program_name = basename(program_name);
}

int	main(int argc, char *argv[])
{
	t_dump	dump;

	if (argc < 2)
		return (1);
	if (ft_strcmp(argv[1], "-C") != 0)
		return (1);
	init_dump(&dump, argv[0]);
	if (argc == 2)
		return (ft_dump_stdin(&dump));
	else
		return (ft_dump_files(argc, argv, &dump));
	return (0);
}
