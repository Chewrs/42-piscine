/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:36:32 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/12 13:17:50 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strstr(char *str, char *tofind);

unsigned int	ft_slen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *tofind)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_str;
	unsigned int	len_tf;

	len_str = ft_slen(str);
	len_tf = ft_slen(tofind);
	if (tofind[0] == '\0')
		return (&str[0]);
	i = 0;
	while (i <= (len_str - len_tf) && len_str >= len_tf)
	{
		j = 0;
		while (j < len_tf && str[i + j] == tofind[j])
		{
			j++;
		}
		if (j == len_tf)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*r;

	(void)argc;
	r = ft_strstr(argv[1], argv[2]);
	printf("%s", r);
	return (0);
}
*/
