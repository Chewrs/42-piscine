/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:39:43 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/16 17:04:42 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	can_place(int board[4][4], int row, int col, int value);
int	check_all_clues(int board[4][4], int clues[16]);

int	solve(int board[4][4], int clues[16], int pos)
{
	int	i;
	int	row;
	int	col;

	if (pos == 16)
	{
		return (check_all_clues(board, clues));
	}
	row = pos / 4;
	col = pos % 4;
	i = 1;
	while (i <= 4)
	{
		if (can_place(board, row, col, i))
		{
			board[row][col] = i;
			if (solve(board, clues, pos + 1))
				return (1);
			else
				board[row][col] = 0;
		}
		i++;
	}
	return (0);
}
