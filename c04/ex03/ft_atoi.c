/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:44:17 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/12 16:25:42 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				s;
	int				t;

	i = 0;
	s = 1;
	t = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32 && str[i] != '\0'))
	{
		i++;
	}
	while ((str[i] == 45 || str[i] == 43) && str[i] != '\0')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
	{
		t = t * 10 + (str[i] - '0');
		i++;
	}
	return (t * s);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	r;

	(void) argc;
	r = ft_atoi(argv[1]);
	printf("%d", r);
}
*/
