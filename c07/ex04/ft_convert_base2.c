/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:40:32 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/19 10:40:34 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	base_conv(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

long long	atoi_base(char *nbr, char *base)
{
	int			i;
	long long	t;
	int			s;

	i = 0;
	t = 0;
	s = 1;
	while (nbr[i] != '\0' && ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' '))
	{
		i++;
	}
	while (nbr[i] != '\0' && (nbr[i] == '+' || nbr[i] == '-'))
	{
		if (nbr[i] == '-')
			s = -s;
		i++;
	}
	while (base_conv(nbr[i], base) != -1)
	{
		t = (t * str_len(base)) + base_conv(nbr[i], base);
		i++;
	}
	return (t * s);
}
