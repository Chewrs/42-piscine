/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parts_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:52:27 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/24 15:59:01 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_1digit(char *dest, char c)
{
	dest[0] = c;
	dest[1] = '\0';
}

void	make_2digit(char *dest, char c1, char c2)
{
	dest[0] = c1;
	dest[1] = c2;
	dest[2] = '\0';
}

int	add_part(char **parts, int *i, char *str)
{
	parts[*i] = ft_strdup(str);
	if (!parts[*i])
	{
		parts[*i] = NULL;
		return (0);
	}
	(*i)++;
	parts[*i] = NULL;
	return (1);
}

void	free_parts(char **parts)
{
	int	i;

	i = 0;
	if (!parts)
		return ;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}

void	free_dict_final(t_dict *dict)
{
	int	i;

	i = 0;
	if (!dict)
		return ;
	while (dict[i].key)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}
