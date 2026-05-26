/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:16:05 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/17 13:11:24 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	get_row(int board[4][4], int row, int line[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = board[row][i];
		i++;
	}
}

void	get_col(int board[4][4], int col, int line[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = board[i][col];
		i++;
	}
}

void	rev_line(int line[4], int rev[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		rev[i] = line[3 - i];
		i++;
	}
}
