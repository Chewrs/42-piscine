/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhunhan <tkhunhan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:55:59 by tkhunhan          #+#    #+#             */
/*   Updated: 2026/05/24 14:25:48 by tkhunhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	format_check(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (is_space(str[i]))
		i++;
	if (str[i] != ':')
		return (0);
	i++;
	while (is_space(str[i]))
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (0);
	return (1);
}

int	double_check(char *str, t_dict *dict, int row)
{
	dict[row].key = NULL;
	if (!format_check(str))
		return (0);
	dict[row].key = get_key(str);
	if (!dict[row].key)
		return (0);
	dict[row].value = get_value(str);
	if (!dict[row].value)
	{
		free(dict[row].key);
		dict[row].key = NULL;
		return (0);
	}
	return (1);
}

int	free_dict(t_dict *dict)
{
	int	i;

	if (!dict)
		return (0);
	i = 0;
	while (dict[i].key != NULL)
	{
		free(dict[i].key);
		if (dict[i].value != NULL)
			free(dict[i].value);
		i++;
	}
	free(dict);
	return (1);
}
