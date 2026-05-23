/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   che.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:43:21 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/23 16:57:08 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	split_number(char *nbr, char **parts, int *i);
char *number_to_text(char *str,t_dict *dict);
t_dict	*parser_dict(char *path_file);

void	split_2(char *nbr, char **part, int *i)
{
	char	tens[3];
	char	one[2];

	if (nbr[0] != '0')
	{
		if (nbr[0] == '1')
		{
			tens[0] = nbr[0];
			tens[1] = nbr[1];
			tens[2] = '\0';
			add_part(part, i, tens);
			return ;
		}
		tens[0] = nbr[0];
		tens[1] = '0';
		tens[2] = '\0';
		add_part(part, i, tens);
	}
	if (nbr[1] != '0')
	{
		one[0] = nbr[1];
		one[1] = '\0';
		add_part(part, i, one);
	}
}

void	split_3(char *nbr, char **part, int *i)
{
	char	*hund;
	char	digit[2];

	if (nbr[0] != '0')
	{
		hund = "100";
		digit[0] = nbr[0];
		digit[1] = '\0';
		add_part(part, i, digit);
		add_part(part, i, hund);
	}
	if (nbr[1] != '0' || nbr[2] != '0')
		split_number(nbr + 1, part, i);
}

void	split_big(char *nbr, char **parts, int *i)
{
	int		len;
	int		right_len;
	char	*left;
	char	*right;
	char	*power;

	len = ft_strlen(nbr);
	right_len = ((len - 1) / 3) * 3;
	left = ft_substr(nbr, 0, len - right_len);
	right = ft_substr(nbr, len - right_len, right_len);
	power = make_power(right_len);
	if (!left || !right || !power)
		return ;
	if (!is_all_zero(left))
	{
		split_number(left, parts, i);
		add_part(parts, i, power);
	}
	if (!is_all_zero(right))
		split_number(right, parts, i);
	free(left);
	free(right);
	free(power);
}

void	split_number(char *nbr, char **parts, int *i)
{
	int		len;
	char	digit[2];

	len = ft_strlen(nbr);
	if (len == 1)
	{
		digit[0] = nbr[0];
		digit[1] = '\0';
		add_part(parts, i, digit);
	}
	else if (len == 2)
		split_2(nbr, parts, i);
	else if (len == 3)
		split_3(nbr, parts, i);
	else
	{
		split_big(nbr, parts, i);
	}
}

char	**number_to_parts(char *nbr)
{
	char	**parts;
	int		i;
	int		len;

	len = ft_strlen(nbr);
	parts = malloc(sizeof(char *) * (len * 2 + 1));
	if (!parts)
		return (NULL);
	i = 0;
	split_number(nbr, parts, &i);
	parts[i] = NULL;
	return (parts);
}

int	main(int argc, char *argv[])
{
	char	*nbr;
	int		i;
	char	**parts;
	char	*opt;
	t_dict	*dict;

	(void)argc;
	nbr = argv[1];

	parts = number_to_parts(nbr);
	dict =  parser_dict("numbers.dict");
	i = 0;
	while (parts[i])
	{
		
		opt = number_to_text(parts[i], dict);
		if(!opt)
		{
			printf("can't find anything");
			return 0;
		}
		ft_putstr(opt);
		if(parts[i+1] != NULL)
			ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
	return (0);
}
