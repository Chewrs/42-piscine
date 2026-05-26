/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 08:55:50 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/18 10:38:20 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		l;
	char	*dest;

	l = 0;
	if (!src)
		return (NULL);
	while (src[l] != '\0')
		l++;
	dest = malloc(sizeof(char) * (l + 1));
	if (!dest)
		return (NULL);
	l = 0;
	while (src[l] != '\0')
	{
		dest[l] = src[l];
		l++;
	}
	dest[l] = '\0';
	return (dest);
}
/*
int	main(int argc, char *argv[])
{
	char	*dest;

	if(argc < 2)
	{
		printf("ERROR: No input \n");
		return (1);
	}
	dest = ft_strdup(argv[1]);
	printf("%p: %s\n" ,dest, dest);
	free(dest);
	dest = NULL;
	return (0);
}
*/
