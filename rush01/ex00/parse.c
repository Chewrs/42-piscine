/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 12:52:52 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/17 13:08:53 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_input(char *str, int clues[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (count >= 16 || str[i] < '1' || str[i] > '4')
			return (0);
		clues[count] = str[i] - '0';
		count++;
		i++;
		if (count == 16 && str[i] == '\0')
			return (1);
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (0);
}

void	init_board(int board[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
}
