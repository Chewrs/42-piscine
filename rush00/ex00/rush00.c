/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 11:25:54 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/10 10:15:53 by ksaivich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_wline(char l, char m, char r, int len)
{
	int	i;

	if (len > 0)
	{
		ft_putchar(l);
	}
	i = 0;
	while (i < len - 2)
	{
		ft_putchar(m);
		i++;
	}
	if (len > 1)
	{
		ft_putchar(r);
	}
	if (len > 0)
	{
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (y > 0)
	{
		ft_wline('o', '-', 'o', x);
	}
	while (i < y - 2)
	{
		ft_wline('|', ' ', '|', x);
		i++;
	}
	if (y > 1)
	{
		ft_wline('o', '-', 'o', x);
	}
}
