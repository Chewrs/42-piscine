/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pustr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:38:41 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/07 16:09:31 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != 0)
	{
		write(1, str + i, 1);
		i++;
	}
}

/*
int	main(void)
{
	char	*s;

	s = "Hello";
	ft_putstr(s);
	return (0);
}
*/
