/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:08:38 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 12:08:43 by wjunpuan         ###   ########.fr       */
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

typedef struct s_dump
{
	unsigned int	offset;
	unsigned char	prev[16];
	unsigned char	curr[16];
	int				curr_size;
	int				has_prev;
	int				in_duplicate;
	char			*program_name;
	int				has_output;
}					t_dump;

int					ft_strlen(char *str);
void				ft_putstr_fd(char *str, int fd);
int					ft_strcmp(char *s1, char *s2);
void				*ft_memcpy(void *dest, void *src, unsigned int n);
int					ft_memcmp(void *s1, void *s2, unsigned int n);

int					process_fd(int fd, t_dump *dump);
int					process_file(char *filename, t_dump *dump);
int					ft_dump_stdin(t_dump *dump);
int					ft_dump_files(int argc, char **argv, t_dump *dump);

int					not_match(t_dump *dump, unsigned char *buf, int size);
void				update_prev_block(t_dump *dump, unsigned char *buf,
						int size);
void				flush_pending(t_dump *dump);
void				push_byte(t_dump *dump, unsigned char c);

void				print_error(char *program_name, char *filename);

void				print_offset(unsigned int offset);
void				print_hex_byte(unsigned char c);
void				print_hex_section(unsigned char *buf, int size);

void				print_line(t_dump *dump, unsigned char *buf, int size);
void				print_ascii_section(unsigned char *buf, int size);
void				print_final_offset(t_dump *dump);

#endif
