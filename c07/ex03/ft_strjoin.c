/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:52:01 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/18 13:35:19 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char			*ft_strjoin(int size, char **strs, char *sep);

unsigned int	len_str(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	len_strs(char **strs, int size)
{
	int				i;
	unsigned int	c;

	i = 0;
	c = 0;
	while (i < size)
		c += len_str(strs[i++]);
	return (c);
}

void	add(char *result, char *s, int *c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		result[*c] = s[i++];
		*c = *c + 1;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		c;

	c = 0;
	i = 0;
	if (size == 0)
	{
		result = malloc(1);
		result[0] = '\0';
		return (result);
	}
	result = malloc(len_strs(strs, size) + ((size - 1) * len_str(sep)) + 1);
	if (!result)
		return (NULL);
	while (i < size)
	{
		add(result, strs[i], &c);
		if (i != (size - 1))
			add(result, sep, &c);
		i++;
	}
	result[c] = '\0';
	return (result);
}
/*
int	main(void)
{
	char	*strs[] = {"Hello", "hello"};
	char	*r;

	r = ft_strjoin(2, strs, "1");
	printf("%s", r);
	free(r)
	r = NULL;
	return (0);
}
*/
