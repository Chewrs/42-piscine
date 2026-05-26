/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:22:52 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/24 18:34:15 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	char	*nbr;
	char	*dict_file;
	t_dict	*dict;

	if (!set_args(argc, argv, &dict_file, &nbr))
		return (1);
	if (ft_strcmp(nbr, "-") != 0 && !is_valid_number(nbr))
	{
		ft_putstr("Error\n");
		return (1);
	}
	dict = parser_dict(dict_file);
	if (!dict)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	if (ft_strcmp(nbr, "-") == 0)
		read_from_stdin(dict);
	else
		convert_and_print(nbr, dict);
	free_dict_final(dict);
	return (0);
}
