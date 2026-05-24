/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_parts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:43:21 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/24 18:34:04 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	split_2(char *nbr, char **parts, int *i)
{
	char	tens[3];
	char	one[2];

	if (nbr[0] == '1')
	{
		make_2digit(tens, nbr[0], nbr[1]);
		return (add_part(parts, i, tens));
	}
	if (nbr[0] != '0')
	{
		make_2digit(tens, nbr[0], '0');
		if (!add_part(parts, i, tens))
			return (0);
	}
	if (nbr[1] != '0')
	{
		make_1digit(one, nbr[1]);
		if (!add_part(parts, i, one))
			return (0);
	}
	return (1);
}

int	split_3(char *nbr, char **parts, int *i)
{
	char	digit[2];

	if (nbr[0] != '0')
	{
		make_1digit(digit, nbr[0]);
		if (!add_part(parts, i, digit))
			return (0);
		if (!add_part(parts, i, "100"))
			return (0);
	}
	if (nbr[1] != '0' || nbr[2] != '0')
	{
		if (!split_number(nbr + 1, parts, i))
			return (0);
	}
	return (1);
}

int	split_number(char *nbr, char **parts, int *i)
{
	int		len;
	char	digit[2];

	if (is_all_zero(nbr) && *i == 0)
		return (add_part(parts, i, "0"));
	len = ft_strlen(nbr);
	if (len == 1)
	{
		if (nbr[0] == '0' && *i != 0)
			return (1);
		make_1digit(digit, nbr[0]);
		return (add_part(parts, i, digit));
	}
	if (len == 2)
		return (split_2(nbr, parts, i));
	if (len == 3)
		return (split_3(nbr, parts, i));
	return (split_big(nbr, parts, i));
}

char	**number_to_parts(char *nbr, t_dict *dict)
{
	char	**parts;
	int		i;
	int		len;

	len = ft_strlen(nbr);
	parts = malloc(sizeof(char *) * (len * 2 + 2));
	if (!parts)
		return (NULL);
	i = 0;
	parts[0] = NULL;
	if (!is_power_of_thousand(nbr) && number_to_text(nbr, dict))
	{
		if (!add_part(parts, &i, nbr))
		{
			free_parts(parts);
			return (NULL);
		}
	}
	else if (!split_number(nbr, parts, &i))
	{
		free_parts(parts);
		return (NULL);
	}
	parts[i] = NULL;
	return (parts);
}

void	convert_and_print(char *nbr, t_dict *dict)
{
	char	**spt_nbr;

	spt_nbr = number_to_parts(nbr, dict);
	if (!spt_nbr)
	{
		ft_putstr("Error\n");
		return ;
	}
	if (!check_all_parts(spt_nbr, dict))
	{
		ft_putstr("Dict Error\n");
		free_parts(spt_nbr);
		return ;
	}
	print_all_parts(spt_nbr, dict);
	free_parts(spt_nbr);
}
