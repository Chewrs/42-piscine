/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:25:04 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/25 11:25:07 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	words;
	int	counting;
	int	i;

	words = 0;
	counting = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_charset(str[i], charset))
		{
			counting = 1;
		}
		if (counting == 1 && !is_charset(str[i], charset))
		{
			counting = 0;
			words++;
		}
		i++;
	}
	return (words);
}

char	*copy_word(char *src, int len, int i)
{
	int		k;
	char	*dest;

	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	k = 0;
	while (k < len)
	{
		dest[k] = src[i + k];
		k++;
	}
	dest[k] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		len = 0;
		while (str[i + len] && !is_charset(str[i + len], charset))
			len++;
		if (len > 0)
		{
			result[j++] = copy_word(str, len, i);
			i = i + len;
		}
	}
	result[j] = NULL;
	return (result);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	**r;
	int		i;
	int		j;

	(void)argc;
	i = 0;
	r = ft_split(argv[1], argv[2]);
	while (r[i] != NULL)
	{
		j = 0;
		while (r[i][j] != '\0')
		{
			printf("%c", r[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
*/
