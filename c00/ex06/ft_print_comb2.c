/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:34:51 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/07 08:33:16 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	put_num(int n);

void	put_num(int n)
{
	char	c;

	c = 48 + n;
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	f;
	int	s;

	f = 0;
	s = 0;
	while (f <= 99)
	{
		s = f + 1;
		while (s <= 99)
		{
			put_num(f / 10);
			put_num(f % 10);
			write(1, " ", 1);
			put_num(s / 10);
			put_num(s % 10);
			if (!(f == 98 && s == 99))
			{
				write(1, ",", 1);
				write(1, " ", 1);
			}
			s++;
		}
		f++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
