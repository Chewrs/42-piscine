/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:45:23 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/08 08:10:39 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != 0)
	{
		i++;
		c++;
	}
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s;
	int		result;

	s = "hello, world!";
	result = ft_strlen(s);
	printf("%d", result);
	return (0);
}
*/
