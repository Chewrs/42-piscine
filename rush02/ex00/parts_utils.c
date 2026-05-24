/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:57:57 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/24 15:59:43 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_substr(char *str, int start, int len)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len && str[start + i])
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	is_all_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	is_power_of_thousand(char *nbr)
{
	int	i;

	if (nbr[0] != '1')
		return (0);
	i = 1;
	while (nbr[i])
	{
		if (nbr[i] != '0')
			return (0);
		i++;
	}
	if ((i - 1) % 3 != 0)
		return (0);
	return (i > 1);
}

int	check_all_parts(char **spt_nbr, t_dict *dict)
{
	int	i;

	i = 0;
	while (spt_nbr[i])
	{
		if (!number_to_text(spt_nbr[i], dict))
			return (0);
		i++;
	}
	return (1);
}

void	print_all_parts(char **spt_nbr, t_dict *dict)
{
	int	i;

	i = 0;
	while (spt_nbr[i])
	{
		ft_putstr(number_to_text(spt_nbr[i], dict));
		if (spt_nbr[i + 1])
			ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
}
