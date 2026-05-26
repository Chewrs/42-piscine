/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:13:54 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/06 16:15:10 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	put_char(char c);

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		put_char('-');
		if (nb == -2147483648)
		{
			put_char('2');
			nb = -147483648;
		}
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
	{
		put_char(nb + '0');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
/*
int	main(void)
{
	ft_putnbr(-2147483648);
	ft_putnbr(4);
	ft_putnbr(-3);
}
*/
