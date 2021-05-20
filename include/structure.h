/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:43:10 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/20 17:28:09 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct	s_resolution
{
	int	width;
	int	height;
}				t_resolution;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct s_vec	t_color;

typedef struct	s_rt_info
{
	char			*id;
	t_resolution	resolution;
	t_vec			coor1;
	t_vec			coor2;
	t_vec			coor3;
	t_vec			normal_vector;
	t_color			color;
	unsigned int	view_degree;
	double			brightness;
	double			diameter;
	double			side_size;
}				t_rt_info;

typedef struct	s_node
{
	t_rt_info		data;
	struct s_node	*next;
}				t_node;

typedef struct	s_list
{
	t_node	*cur;
	t_node	*head;
	t_node	*tail;
}				t_list;

#endif
