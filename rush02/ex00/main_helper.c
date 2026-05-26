/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:05:41 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/24 16:06:06 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	set_args(int argc, char **argv, char **dict_file, char **nbr)
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (argc == 2)
	{
		*dict_file = "numbers.dict";
		*nbr = argv[1];
	}
	else
	{
		*dict_file = argv[1];
		*nbr = argv[2];
	}
	return (1);
}
