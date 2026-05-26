/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:37:15 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/13 17:10:26 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);

int	not_valid_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int	str_len(char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	helper(char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	i;
	int				sign;
	long long		total;

	i = 0;
	sign = 1;
	total = 0;
	if (not_valid_base(base) || str_len(base) < 2)
		return (0);
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
	{
		i++;
	}
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] != '\0' && helper(str[i], base) != -1)
	{
		total = (total * str_len(base)) + helper(str[i], base);
		i++;
	}
	return (total * sign);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	r;

	(void)argc;
	r = ft_atoi_base(argv[1], argv[2]);
	printf("%d", r);
	return (0);
}
*/
