/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:07:10 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:07:11 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>
# include <unistd.h>

void	ft_putchar(char c, int out);
void	ft_putstr(char *str, int out, int len);
int		ft_strlen(char *str);
int		ft_file_read(char *filepath);

#endif
