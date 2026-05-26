/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:52:43 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/21 14:04:22 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_show_tab(struct s_stock_str *par);

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	put_nbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		put_nbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		put_str(par[i].str);
		put_nbr(par[i].size);
		write(1, "\n", 1);
		put_str(par[i].copy);
		i++;
	}
}

/*
int	main(void)
{
	struct s_stock_str	s[3];

	s[0].size = 3;
	s[0].str = "hel";
	s[0].copy = "hel";
	s[1].size = 2;
	s[1].str = "ab";
	s[1].copy = "ab";
	s[2].size = 0;
	s[2].str = 0;
	s[2].copy = 0;
	ft_show_tab(s);
	return (0);
}
*/
