/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 12:53:24 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/17 13:09:17 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	print_board(int board[4][4])
{
	int	j;
	int	k;
	int	v;

	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			v = board[j][k];
			putchar(v + '0');
			if (k < 3)
			{
				putchar(' ');
			}
			k++;
		}
		putchar('\n');
		j++;
	}
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}
