/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:33:09 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/09 15:34:48 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (str[i] != 0)
	{
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			r = 0;
		}
		i++;
	}
	return (r);
}
