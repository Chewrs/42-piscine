/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 08:26:57 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/21 14:22:02 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char		*ft_convert_base(char *nbr, char *base_from, char *base_to);
int			str_len(char *str);

long long	atoi_base(char *nbr, char *base);

int	valid_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || (base[i] >= 9
				&& base[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

int	size(long long dcm, int len_base)
{
	int			size;
	long long	tem;

	tem = dcm;
	size = 0;
	if (tem <= 0)
	{
		tem = -tem;
		size++;
	}
	while (tem > 0)
	{
		tem = tem / len_base;
		size++;
	}
	return (size + 1);
}

void	dcm_base(char *result, long long dcm, int len_base, char *base_to)
{
	long long	tem;
	int			i;

	tem = dcm;
	i = 0;
	if (dcm < 0)
	{
		tem = -tem;
		i++;
	}
	while (tem > 0)
	{
		result[i] = base_to[tem % len_base];
		tem = tem / len_base;
		i++;
	}
}

void	rev(char *result, long long dcm, int size)
{
	int		left;
	int		right;
	char	tem;

	left = 0;
	right = size - 2;
	if (dcm < 0)
		left++;
	while (left < right)
	{
		tem = result[left];
		result[left] = result[right];
		result[right] = tem;
		left++;
		right--;
	}
	if (dcm < 0)
		result[0] = '-';
	result[size - 1] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*result;
	int			len_base;
	long long	dcm;
	int			sz;

	len_base = str_len(base_to);
	if (str_len(base_from) < 2 || !(valid_base(base_from))
		|| str_len(base_to) < 2 || !(valid_base(base_to)))
		return (NULL);
	dcm = atoi_base(nbr, base_from);
	if (dcm == 0)
	{
		result = malloc(2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	sz = size(dcm, len_base);
	result = malloc(sizeof(char) * sz);
	if (!result)
		return (NULL);
	dcm_base(result, dcm, len_base, base_to);
	rev(result, dcm, sz);
	return (result);
}

/*
int	main(int argc, char *argv[])
{
	char	*r;

	(void)argc;
	r = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("%s", r);
	return (0);
}
*/
