/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:07:49 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/21 15:42:32 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <stdio.h>
# include "structure.h"

/*
** string.c
*/
unsigned int	ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strlcpy(char *dst, const char *src, int dstsize);
int				count_split(char **split);
int				count_comma(char **split);

/*
** atoi.c
*/
int				ft_atoi(const char *str);
double			ft_atod(char *s);

/*
** list.c
*/
void			init_list(t_list **list);
void			add_node(t_list *list, t_rt_info data);
void			search_node(t_list **list, char *s);
int				count_node(t_list *list, char *s);
void			del_node(t_list **list);

/*
** set_list.c
*/
int				set_list(t_list *list, char *argv);

/*
** error.c
*/
void			put_err(char *err_msg, t_list *list);

/*
** split.c
*/
char			**allo_free(char **rst);
char			**ft_split(char const *s, char c);

/*
** check.c
*/
int				check_int(char *s);
int				check_double(char *s);
int				check_id(t_list *list);

/*
** element.c
*/
int				add_color(char **split, t_color *color);
int				add_coordinate(char **split, t_vec *coor);
int				add_normalized_vector(char **split, t_vec *normalized_vector);
int				add_r(char **split, t_rt_info data, t_list *list);
int				add_a(char **split, t_rt_info data, t_list *list);
int				add_c(char **split, t_rt_info data, t_list *list);
int				add_l(char **split, t_rt_info data, t_list *list);
int				add_sp(char **split, t_rt_info data, t_list *list);
int				add_pl(char **split, t_rt_info data, t_list *list);
int				add_sq(char **split, t_rt_info data, t_list *list);
int				add_cy(char **split, t_rt_info data, t_list *list);
int				add_tr(char **split, t_rt_info data, t_list *list);

#endif
