/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:59:33 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/17 14:09:57 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		ft_ten_queens_puzzle(void);

int	is_safe(int board[10], int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (board[i] - row == i - col)
			return (0);
		if (board[i] - row == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	print_solution(int board[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	solve(int board[10], int col)
{
	int	row;
	int	count;

	if (col == 10)
	{
		print_solution(board);
		return (1);
	}
	count = 0;
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			count += solve(board, col + 1);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	result;

	result = solve(board, 0);
	return (result);
}

/*
int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
*/
