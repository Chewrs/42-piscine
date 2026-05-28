/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:36:36 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 16:42:03 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	up;
	int	down;

	i = 0;
	up = 0;
	down = 0;
	while (i < (length - 1))
	{
		if (f(tab[i], tab[i + 1]) > 0)
			down = 1;
		if (f(tab[i], tab[i + 1]) < 0)
			up = 1;
		i++;
	}
	if (up && down)
		return (0);
	return (1);
}
