/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:21:26 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/25 09:58:12 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	read_line(char *buffer)
{
	int		i;
	char	c;
	int		r;

	i = 0;
	r = read(0, &c, 1);
	while (r > 0)
	{
		if (c == '\n')
			break ;
		buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\0';
	if (r <= 0 && i == 0)
	{
		return (0);
	}
	return (1);
}

void	read_from_stdin(t_dict *dict)
{
	char	buffer[1024];

	while (read_line(buffer))
	{
		if (!is_valid_number(buffer))
			ft_putstr("Error\n");
		else
			convert_and_print(buffer, dict);
	}
}
