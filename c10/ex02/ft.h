/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:07:48 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:38:03 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_newline
{
	int	multi;
	int	second;
}		t_newline;

void	ft_putchar(char c, int out);
void	ft_putstr(char *str, int out, int len);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);

int		ft_tail_stdin(int bytes);
int		ft_tail_files(int argc, char *argv[], int bytes);

int		err_illegal(char *argv[]);
int		err_option(char *argv[]);
int		err_read(char *program, char *filename);
int		err_open(char *program, char *filename);

void	print_header(char *filename);
void	print_bytes(char *buf, int total, int bytes);

#endif
