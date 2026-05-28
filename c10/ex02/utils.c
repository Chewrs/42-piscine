/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:08:05 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:08:05 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str, int out, int len)
{
	int	i;

	if (len == 0)
		len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		ft_putchar(str[i], out);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	digit;
	int	max;

	max = 2147483647;
	i = 0;
	nb = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		digit = str[i] - '0';
		if (nb > (max - digit) / 10)
			return (-1);
		nb = (nb * 10) + digit;
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	else
		return (nb);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
