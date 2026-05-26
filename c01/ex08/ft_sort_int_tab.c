/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 08:13:54 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/08 13:58:41 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	change;
	int	i;
	int	tem;

	change = 1;
	i = 0;
	tem = 0;
	while (change > 0)
	{
		change = 0;
		i = 0;
		while (i < (size - 1))
		{
			if (*(tab + i) > *(tab + i + 1))
			{
				change = 1;
				tem = *(tab + i);
				*(tab + i) = *(tab + i + 1);
				*(tab + i + 1) = tem;
			}
			i++;
		}
	}
}
