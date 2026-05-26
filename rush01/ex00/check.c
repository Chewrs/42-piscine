/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:59:33 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/17 13:10:08 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	get_row(int board[4][4], int row, int line[4]);
void	get_col(int board[4][4], int col, int line[4]);
void	rev_line(int line[4], int rev[4]);
int		count_visible(int line[4]);

int	can_place(int board[4][4], int row, int col, int value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (board[row][i] == value)
			return (0);
		if (board[i][col] == value)
			return (0);
		i++;
	}
	return (1);
}

int	check_colums(int board[4][4], int clues[16])
{
	int	col;
	int	line[4];
	int	rev[4];

	col = 0;
	while (col < 4)
	{
		get_col(board, col, line);
		if (count_visible(line) != clues[col])
			return (0);
		rev_line(line, rev);
		if (count_visible(rev) != clues[col + 4])
			return (0);
		col++;
	}
	return (1);
}

int	check_rows(int board[4][4], int clues[16])
{
	int	row;
	int	line[4];
	int	rev[4];

	row = 0;
	while (row < 4)
	{
		get_row(board, row, line);
		if (count_visible(line) != clues[row + 8])
			return (0);
		rev_line(line, rev);
		if (count_visible(rev) != clues[row + 12])
			return (0);
		row++;
	}
	return (1);
}

int	check_all_clues(int board[4][4], int clues[16])
{
	if (check_colums(board, clues) && check_rows(board, clues))
		return (1);
	return (0);
}
