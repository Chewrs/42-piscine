/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:01:16 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/09 17:27:20 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "1234";
	char	dest[100];

	printf("src; %s\n", src);
	printf("size of src = %lu\n", sizeof(src));
	printf("dest; %s\n", dest);
	printf("size of dest = %lu\n", sizeof(dest));
	ft_strcpy(dest, src);
	printf("After run ft_strcpy \n");
	printf("src; %s\n", src);
	printf("size of src = %lu\n", sizeof(src));
	printf("dest; %s\n", dest);
	printf("size of dest = %lu\n", sizeof(dest));
	return (0);
}
*/
