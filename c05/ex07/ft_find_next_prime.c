/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:07:52 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/14 13:15:37 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb);

int	is_prime(int nb)
{
	int	i;

	i = 2;
	while (i <= nb && nb % i != 0)
	{
		i++;
	}
	if (i == nb)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!(is_prime(nb)) && nb < 2147483647)
	{
		nb++;
	}
	return (nb);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	r;

	(void)argc;
	r = ft_find_next_prime(atoi(argv[1]));
	printf("%d", r);
	return (0);
}
*/
