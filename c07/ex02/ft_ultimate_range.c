/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:08:42 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/18 11:44:48 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	size = (max - min);
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	while (min < max)
	{
		*(*range + i) = min;
		i++;
		min++;
	}
	return (size);
}

/*
int	main(void)
{
	int	max;
	int	min;
	int	i;
	int	*range;

	max = -5;
	min = -10;
	i = 0;
	ft_ultimate_range(&range, min, max);
	while (i < (max - min))
	{
		printf("%d \n", range[i]);
		i++;
	}
	free(range);
	range = NULL;
}
*/
