/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:07:52 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:07:53 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char *argv[])
{
	int	bytes;

	if (argc < 2)
		return (1);
	if (ft_strcmp(argv[1], "-c") != 0)
		return (1);
	if (argc < 3)
		return (err_option(argv));
	bytes = ft_atoi(argv[2]);
	if (bytes == -1)
		return (err_illegal(argv));
	if (bytes == 0)
		return (0);
	if (argc == 3)
		return (ft_tail_stdin(bytes));
	else
		return (ft_tail_files(argc, argv, bytes));
	return (0);
}
