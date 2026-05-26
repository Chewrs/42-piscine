/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:32:42 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/17 14:39:59 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	display(char *str)
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

void	helper(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		display(argv[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		ns;
	char	*tem;

	ns = 1;
	while (ns)
	{
		ns = 0;
		i = 1;
		while (i < argc - 1 && argc > 2)
		{
			if (compare(argv[i], argv[i + 1]) > 0)
			{
				ns = 1;
				tem = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tem;
			}
			i++;
		}
	}
	helper(argc, argv);
	return (0);
}
