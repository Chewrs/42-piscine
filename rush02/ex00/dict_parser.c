/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhunhan <tkhunhan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:56:11 by tkhunhan          #+#    #+#             */
/*   Updated: 2026/05/24 12:34:31 by tkhunhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_line(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

t_dict	*parser_dict(char *path_file)
{
	char	*file_conten;
	int		line_count;
	t_dict	*dict_array;

	file_conten = read_dict(path_file);
	if (!file_conten)
		return (NULL);
	line_count = count_line(file_conten);
	dict_array = (t_dict *)malloc(sizeof(t_dict) * (line_count + 2));
	if (!dict_array)
	{
		free(file_conten);
		return (NULL);
	}
	if (fill_dict_array(file_conten, dict_array) == 0)
	{
		free(file_conten);
		free_dict(dict_array);
		return (NULL);
	}
	free(file_conten);
	return (dict_array);
}

char	*number_to_text(char *str, t_dict *dic)
{
	int	i;

	i = 0;
	while (dic[i].key != NULL)
	{
		if (ft_strcmp(dic[i].key, str) == 0)
			return (dic[i].value);
		i++;
	}
	return (NULL);
}
