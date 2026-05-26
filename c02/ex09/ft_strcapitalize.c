/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:14:47 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/09 16:42:14 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

int	ft_is_up(char c)
{
	int	r;

	r = 1;
	if (!(c >= 65 && c <= 90))
	{
		r = 0;
	}
	return (r);
}

int	ft_is_low(char c)
{
	int	r;

	r = 1;
	if (!(c >= 97 && c <= 122))
	{
		r = 0;
	}
	return (r);
}

int	ft_is_num(char c)
{
	int	r;

	r = 1;
	if (!(c >= 48 && c <= 57))
	{
		r = 0;
	}
	return (r);
}

void	ft_for_alpn(char *c, int *m)
{
	if (ft_is_up(*c) == 1)
	{
		if (*m == 0)
		{
			*c = *c + 32;
		}
		else
		{
			*m = 0;
		}
	}
	else if (ft_is_low(*c) == 1)
	{
		if (*m == 1)
		{
			*c = *c - 32;
			*m = 0;
		}
	}
	else
	{
		*m = 0;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	m;

	i = 0;
	m = 1;
	while (str[i] != 0)
	{
		if (ft_is_up(str[i]) == 1 || ft_is_low(str[i]) == 1
			|| ft_is_num(str[i]) == 1)
		{
			ft_for_alpn(&str[i], &m);
		}
		else
		{
			m = 1;
		}
		i++;
	}
	return (str);
}
