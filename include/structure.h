/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:08:09 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/06/03 12:05:05 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*
typedef struct	s_resolution
{
	int	width;
	int	height;
}				t_resolution;
*/

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct s_vec	t_color;
typedef struct s_vec	t_point;

typedef struct	s_rt_info
{
	char			*id;
	//t_resolution	resolution;
	t_vec			coor1;
	//t_vec			coor2;
	//t_vec			coor3;
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

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_ray
{
	t_point	orig;
	t_vec	dir;
}				t_ray;

typedef struct	s_camera
{
	t_point	orig;
	double	viewport_h;
	double	viewport_w;
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	focal;
	t_point	left_bottom;
	t_vec	normal_vector;
}				t_camera;

typedef struct	s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}				t_canvas;

typedef	struct	s_sphere
{
	t_point	center;
	double	radius;
	double	radius2;
	t_color	color;
}				t_sphere;

typedef struct	s_plane
{
	t_point	center;
	t_vec	normal_vector;
	t_color	color;
}				t_plane;

typedef struct	s_cylinder
{
	t_point	center;
	t_vec	normal_vector;
	double	diameter;
	double	height;
	t_color	color;
}				t_cylinder;

typedef struct	s_hit_record
{
	t_point	p;
	t_vec	normal;
	double	tmin;
	double	tmax;
	double	t;
	int		front_face;
}				t_hit_record;

typedef struct	s_object
{
	char	*id;
	void	*element;
	void	*next;
}				t_object;

#endif
