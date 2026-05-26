/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:02:03 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/17 13:08:07 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		parse_input(char *str, int clues[16]);
void	init_board(int board[4][4]);
void	print_board(int board[4][4]);
void	print_error(void);
int		solve(int board[4][4], int clues[16], int pos);

int	main(int argc, char *argv[])
{
	int	board[4][4];
	int	clues[16];

	if (argc != 2)
	{
		print_error();
		return (0);
	}
	if (!parse_input(argv[1], clues))
	{
		print_error();
		return (0);
	}
	init_board(board);
	if (solve(board, clues, 0))
		print_board(board);
	else
		print_error();
	return (0);
}
