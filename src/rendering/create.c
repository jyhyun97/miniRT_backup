/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:21:57 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/06/04 15:52:50 by jeonhyun         ###   ########.fr       */
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

double get_radian(double degree)
{
	return (degree * M_PI / 180);
}

t_camera	camera(t_canvas *canvas, t_rt_info data)
{
	t_camera	cam;
	t_point	lookfrom = data.coor1;
	t_point	lookat = data.normal_vector;
	t_vec		vup = vec(0, 1, 0);
	//t_vec		vup = vmult_(vec(0, 1, 0), vunit(data.normal_vector));

	//cam.orig = data.coor1;
	cam.viewport_h = 2 * tan(get_radian(data.view_degree) / 2);
	cam.viewport_w = cam.viewport_h * canvas->aspect_ratio;
	cam.focal = vec(0, 0, 1);

	t_vec w = vunit(vminus(lookfrom,  lookat));
	t_vec u = vunit(vcross(vup, w));
	t_vec v = vcross(w, u);
	
	cam.orig = lookfrom;
	cam.horizontal = vmult_(vec(cam.viewport_w, 0, 0), u);//*u
	cam.vertical = vmult_(vec(0, cam.viewport_h, 0), v);//*v
	cam.left_bottom = vminus(vminus(vminus(cam.orig, vdivide(cam.horizontal, 2)), vdivide(cam.vertical, 2)), w);
	cam.normal_vector = data.normal_vector;
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

t_cylinder cylinder(t_point center, t_vec normal_vector, double diameter, double height)
{
	t_cylinder cy;

	cy.center = center;
	cy.normal_vector = normal_vector;
	cy.diameter = diameter;
	cy.height = height;

	return (cy);
}

t_light light(t_point center, double brightness, t_color color)
{
	t_light	li;

	li.center = center;
	li.brightness = brightness;
	li.color = color;
	return (li);
}

t_ambient ambient(double brightness, t_color color)
{
	t_ambient	am;
	
	am.brightness = brightness;
	am.color = color;
	return (am);
}
