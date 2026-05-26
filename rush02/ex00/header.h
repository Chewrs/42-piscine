/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhunhan <tkhunhan@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:22:17 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/24 18:26:20 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}			t_dict;

// ######### STRING ##########
// str_utils.c
int			ft_strlen(char *str);
void		ft_strcpy(char *dest, char *src);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *src);
void		ft_putstr(char *str);

// ########## DICT ##########
// dict_parser.c
t_dict		*parser_dict(char *path_file);
char		*number_to_text(char *str, t_dict *dict);
// dict_utils_2.c
int			format_check(char *str);
int			double_check(char *str, t_dict *dict, int row);
int			free_dict(t_dict *dict);
// dict_utils.c
int			is_space(char c);
char		*get_key(char *str);
char		*get_value(char *str);
int			fill_dict_array(char *str, t_dict *dict);
// file_reader.c
char		*read_dict(char *file_path);

// ########## MAIN ##########
// main_helper.c
int			is_valid_number(char *str);
int			set_args(int argc, char **argv, char **dict_file, char **nbr);
// stdin_reader.c
int			read_line(char *buffer);
void		read_from_stdin(t_dict *dict);

// ########## PART ##########
// number_to_parts.c
char		**number_to_parts(char *nbr, t_dict *dict);
int			split_number(char *nbr, char **parts, int *i);
void		convert_and_print(char *nbr, t_dict *dict);
// part_big.c
int			split_big(char *nbr, char **parts, int *i);
// part_utils_2.c
void		make_1digit(char *dest, char c);
void		make_2digit(char *dest, char c1, char c2);
int			add_part(char **parts, int *i, char *str);
void		free_parts(char **parts);
void		free_dict_final(t_dict *dict);
// part_utils.c
char		*ft_substr(char *str, int start, int len);
int			is_all_zero(char *str);
int			is_power_of_thousand(char *nbr);
int			check_all_parts(char **spt_nbr, t_dict *dict);
void		print_all_parts(char **spt_nbr, t_dict *dict);

#endif
