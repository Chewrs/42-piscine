/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhunhan <tkhunhan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:22:17 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/23 18:39:03 by tkhunhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}			t_dict;

int			ft_strlen(char *str);
void		ft_strcpy(char *dest, char *src);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *src);
void		ft_putstr(char *str);

char		**number_to_parts(char *nbr);

void		add_part(char **parts, int *i, char *str);
char		*ft_substr(char *str, int start, int len);
char		*make_power(int zeros);
int			is_all_zero(char *str);
#endif
