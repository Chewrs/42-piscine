/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:38:28 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/09 17:54:18 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (str[i] != 0)
	{
		if (!(str[i] >= 97 && str[i] <= 122))
		{
			r = 0;
		}
		i++;
	}
	return (r);
}
