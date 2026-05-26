/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:01:33 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/06 16:00:56 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	int	c;

	c = 97;
	while (c < 123)
	{
		write(1, &c, 1);
		c = c + 1;
	}
}

/*
int	main(void)
{
	ft_print_alphabet();
	return (0);
}
*/
