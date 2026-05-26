/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:07:11 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/12 12:53:10 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	str_n_len(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;

	i = 0;
	len_src = str_len(src);
	len_dest = str_n_len(dest, size);
	if (size == 0 || len_dest == size)
		return (size + len_src);
	while (len_dest + i < size - 1 && src[i] != '\0')
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}

/*
#include <stdio.h>

int	main(void)
{
	char			dest[15] = "Hello,";
	char			src[8] = " World!";
	unsigned int	size;
	int				r;

	size = (sizeof(dest)/ sizeof(dest[0]));
	printf("dest: value %s \n",dest);
	r = ft_strlcat(dest,src,size);
	printf("dest: value %s \n",dest);
	printf("r = %d", r);
	return (0);
}
*/
