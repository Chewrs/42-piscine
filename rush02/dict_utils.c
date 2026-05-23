/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhunhan <tkhunhan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:03:55 by tkhunhan          #+#    #+#             */
/*   Updated: 2026/05/23 18:14:26 by tkhunhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
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
	char	*value;

	i = get_val_start(str);
	len = 0;
	while (str[i + len] != '\0' && str[i + len] != '\n')
		len++;
	value = (char *)malloc(sizeof(char) * (len + 1));
	if (!value)
		return (NULL);
	len = 0;
	while (str[i] != '\0' && str[i] != '\n')
		value[len++] = str[i++];
	value[len] = '\0';
	return (value);
}

void	fill_dict_array(char *str, t_dict *dict)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
		{
			dict[row].key = get_key(&str[i]);
			dict[row].value = get_value(&str[i]);
			row++;
		}
		while (str[i] != '\0' && str[i] != '\n')
		{
			i++;
		}
		if (str[i] == '\n')
			i++;
	}
	dict[row].key = NULL;
	dict[row].value = NULL;
}
