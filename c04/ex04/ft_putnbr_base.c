/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:45:47 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/13 12:24:39 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void			ft_putnbr_base(int nbr, char *base);

int	is_dp(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sg(char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

unsigned long	str_len(char *base)
{
	unsigned long	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	put_base(long long n, char *base, long len_base)
{
	if (n < len_base)
	{
		write(1, &(base[n]), 1);
		return ;
	}
	if (n >= len_base)
	{
		put_base(n / len_base, base, len_base);
	}
	write(1, &(base[n % len_base]), 1);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned long	len_base;
	long long		n;

	n = nbr;
	len_base = str_len(base);
	if (len_base < 2 || is_dp(base) || is_sg(base))
	{
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	put_base(n, base, len_base);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		nbr;
	char	base[] = "0123456789abcdef";

	(void) argc;
	(void) argv;
	nbr = 150;
	ft_putnbr_base(nbr,base);
	return (0);
}
*/
