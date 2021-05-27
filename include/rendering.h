/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:08:27 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/27 12:07:06 by jeonhyun         ###   ########.fr       */
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

t_vec   vec(double x, double y, double z);
t_point point(double x, double y, double z);
t_color color(double r, double g, double b);
t_ray   ray(t_point orig, t_vec dir);
t_canvas    canvas(int width, int height);
t_camera    camera(t_canvas *canvas, t_point orig, t_vec normal_vector);
t_sphere    sphere(t_point center, double radius);
t_plane		plane(t_point center, t_vec normal_vector);

#endif
