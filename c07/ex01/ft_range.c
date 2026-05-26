/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 10:22:57 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/18 10:48:39 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	arr = malloc(sizeof(int) * (max - min));
	if (!arr)
		return (NULL);
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
/*
int	main(void)
{
	int	min;
	int	max;
	int	*a;

	min = -4;
	max = 5;
	int i =0;
	a = ft_range(min, max);
	while(i < (max - min))
	{
		printf("%d\n",a[i]);
		i++;
	}
	free(a);
	a = NULL;
	return (0);
}
*/
