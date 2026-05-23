/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:57:57 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/23 18:08:57 by wjunpuan         ###   ########.fr       */
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

void	add_part(char **parts, int *i, char *str)
{
	parts[*i] = ft_strdup(str);
	(*i)++;
	parts[*i] = NULL;
}

char	*make_power(int zeros)
{
	char	*power;
	int		i;

	power = malloc(zeros + 2);
	if (!power)
		return (NULL);
	power[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		power[i] = '0';
		i++;
	}
	power[i] = '\0';
	return (power);
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
