/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:37:11 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/24 15:37:24 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	free_big_parts(char *left, char *right, char *power)
{
	free(left);
	free(right);
	free(power);
}

int	create_big_parts(char *nbr, char **left, char **right, char **power)
{
	int	len;
	int	right_len;

	len = ft_strlen(nbr);
	right_len = ((len - 1) / 3) * 3;
	*left = ft_substr(nbr, 0, len - right_len);
	*right = ft_substr(nbr, len - right_len, right_len);
	*power = make_power(right_len);
	if (!*left || !*right || !*power)
	{
		free_big_parts(*left, *right, *power);
		return (0);
	}
	return (1);
}

int	add_left_power(char *left, char *power, char **parts, int *i)
{
	if (is_all_zero(left))
		return (1);
	if (!split_number(left, parts, i))
		return (0);
	if (!add_part(parts, i, power))
		return (0);
	return (1);
}

int	split_big(char *nbr, char **parts, int *i)
{
	char	*left;
	char	*right;
	char	*power;
	int		ok;

	left = NULL;
	right = NULL;
	power = NULL;
	if (!create_big_parts(nbr, &left, &right, &power))
		return (0);
	ok = add_left_power(left, power, parts, i);
	if (ok && !is_all_zero(right))
		ok = split_number(right, parts, i);
	free_big_parts(left, right, power);
	return (ok);
}
