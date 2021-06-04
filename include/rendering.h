/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:08:27 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/06/04 15:43:16 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

#include "../mlx/mlx.h"
#include "structure.h"
#include <math.h>

t_image	set_image(t_image img, t_list *list);

void	vset(t_vec *vec, double x, double y, double z);
t_vec	vplus(t_vec vec, t_vec vec2);
t_vec	vplus_(t_vec vec, double x, double y, double z);
t_vec	vminus(t_vec vec, t_vec vec2);
t_vec	vminus_(t_vec vec, double x, double y, double z);
t_vec	vmult(t_vec vec, double t);
t_vec	vmult_(t_vec vec, t_vec vec2);
t_vec	vdivide(t_vec vec, double t);
double	vlength2(t_vec vec);
double	vlength(t_vec vec);
double	vdot(t_vec vec, t_vec vec2);
t_vec	vcross(t_vec vec, t_vec vec2);
t_vec	vunit(t_vec vec);
t_vec		vnorm(t_vec vec);

t_vec   vec(double x, double y, double z);
t_point point(double x, double y, double z);
t_color color(double r, double g, double b);
t_ray   ray(t_point orig, t_vec dir);
t_canvas    canvas(int width, int height);
t_camera    camera(t_canvas *canvas, t_rt_info data);
t_sphere    sphere(t_point center, double radius);
t_plane		plane(t_point center, t_vec normal_vector);
t_cylinder cylinder(t_point center, t_vec normal_vector, double diameter, double height);
t_light light(t_point center, double brightness, t_color color);
t_ambient ambient(double brightness, t_color color);

t_ray   set_ray(t_camera cam, double u, double v);
int is_object(t_rt_info data);
double  intersect_pl(t_rt_info data, t_ray ray);
double  intersect_sp(t_rt_info data, t_ray ray);
double intersect_cy(t_rt_info data, t_ray ray);
double  find_intersect_len(t_rt_info data, t_ray ray);
t_node *set_object(t_ray ray, t_list *list);


#endif
