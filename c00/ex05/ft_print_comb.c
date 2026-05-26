/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:47:31 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/07 08:31:09 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	my_write(char f, char s, char t)
{
	write(1, &f, 1);
	write(1, &s, 1);
	write(1, &t, 1);
	if (!(f == '7' && s == '8' && t == '9'))
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	int	f;
	int	s;
	int	t;

	f = 0;
	while (f < 10)
	{
		s = f + 1;
		while (s < 10)
		{
			t = s + 1;
			while (t < 10)
			{
				my_write(f + '0', s + '0', t + '0');
				t++;
			}
			s++;
		}
		f++;
	}
}

/*
int	main(void)
{
	ft_print_comb();
}
*/
