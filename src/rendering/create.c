/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:21:57 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/28 21:55:51 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/rendering.h"

t_vec	vec(double x, double y, double z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point	point(double x, double y, double z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_color	color(double r, double g, double b)
{
	t_color color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

t_ray	ray(t_point	orig, t_vec	dir)
{
	t_ray ray;
	
	ray.orig = orig;
	ray.dir = dir;
	return (ray);
}

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

double get_radian(double fov)
{
	return (fov / M_PI);
}


t_camera	camera(t_canvas *canvas, t_rt_info data)
{
	t_camera	cam;
	t_vec	axis[3];

	cam.orig = data.coor1;
	cam.viewport_h = 2 * tan(data.view_degree / 2);
	cam.viewport_w = cam.viewport_h * (double)(canvas->height/canvas->width);
	axis[0] = vnorm(vmult(data.normal_vector, -1));
	axis[1] = vcross(vec(0, 1, 0), axis[0]);
	axis[2] = vcross(axis[0], axis[1]);

	cam.horizontal = vmult(axis[1], cam.viewport_h);
	cam.vertical = vmult(axis[2], cam.viewport_w);
	cam.left_bottom = vminus(vminus(vminus(cam.orig, vdivide(cam.horizontal, 2)), vdivide(cam.vertical, 2)), axis[0]);
	return (cam);
}

t_sphere	sphere(t_point center, double radius)
{
	t_sphere sp;
	sp.center = center;
	sp.radius = radius;
	sp.radius2 = radius * radius;
	return (sp);
}

t_plane		plane(t_point center, t_vec normal_vector)
{
	t_plane pl;
	pl.center = center;
	pl.normal_vector = normal_vector;
	return (pl);
}
