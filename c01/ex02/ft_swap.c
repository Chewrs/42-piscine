/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:10:08 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/07 15:22:22 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tem;

	tem = *a;
	*a = *b;
	*b = tem;
}

/*
int	main(void)
{
	int	x;
	int	y;

	x = 3;
	y = 2;
	ft_swap(&x, &y);
	printf("%d", x);
	printf("%d", y);
	return (0);
}
*/
