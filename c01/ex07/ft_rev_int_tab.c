/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:54:45 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/08 08:11:22 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	tem;
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		tem = *(tab + i);
		*(tab + i) = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = tem;
		i++;
	}
}

/*
#include <stdio.h>

int	main(void) {
	int arr[] = {10, 20, 30, 40, 50};
	int length = sizeof(arr) / sizeof(arr[0]); // Get array length

	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}

	ft_rev_int_tab(arr, 5);
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	return (0);
}
*/
