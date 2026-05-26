/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhunhan <tkhunhan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:03:55 by tkhunhan          #+#    #+#             */
/*   Updated: 2026/05/24 12:36:53 by tkhunhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13 && c != '\n'))
		return (1);
	return (0);
}

char	*get_key(char *str)
{
	int		i;
	int		len;
	char	*key;

	i = 0;
	len = 0;
	while (is_space(str[i]))
		i++;
	while (str[i + len] >= '0' && str[i + len] <= '9')
		len++;
	key = (char *)malloc(sizeof(char) * (len + 1));
	if (!key)
		return (NULL);
	len = 0;
	while (str[i] >= '0' && str[i] <= '9')
		key[len++] = str[i++];
	key[len] = '\0';
	return (key);
}

int	get_val_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ':')
		i++;
	if (str[i] == ':')
		i++;
	while (is_space(str[i]))
		i++;
	return (i);
}

char	*get_value(char *str)
{
	int		i;
	int		len;
	int		j;
	char	*value;

	i = get_val_start(str);
	len = 0;
	while (str[i + len] != '\0' && str[i + len] != '\n')
		len++;
	while (len > 0 && is_space(str[i + len - 1]))
		len--;
	value = (char *)malloc(sizeof(char) * (len + 1));
	if (!value)
		return (NULL);
	j = 0;
	while (j < len)
	{
		value[j] = str[i + j];
		j++;
	}
	value[len] = '\0';
	return (value);
}

int	fill_dict_array(char *str, t_dict *dict)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
		{
			if (!double_check(&str[i], dict, row))
				return (0);
			row++;
		}
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	dict[row].key = NULL;
	return (1);
}
