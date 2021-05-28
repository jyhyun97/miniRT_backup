/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:00:39 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/28 21:49:56 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structure.h"
#include "../../include/parsing.h"
#include "../../include/rendering.h"
#include "../../include/define.h"

void	mlx_pixel_put_img(t_image *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

t_ray	set_ray(t_camera cam, double u, double v)
{
	t_ray	ray;
	
	ray.orig = cam.orig;
	ray.dir = vplus(vmult(cam.horizontal, u), vmult(cam.vertical, v));
	ray.dir = vplus(ray.dir, cam.left_bottom);
	ray.dir = vnorm(vminus(ray.dir, ray.orig));

//	ray.dir = vunit(vminus(vplus(vplus(cam.left_bottom, vmult(cam.horizontal, u)), vmult(cam.vertical, v)), cam.orig));
	return (ray);
}

int	is_object(t_rt_info data)
{
	if (ft_strcmp(data.id, "pl") == 0 || ft_strcmp(data.id, "sp") == 0 || ft_strcmp(data.id,"cy") == 0)
		return (1);
	else
		return (0);
}

int	is_intersect_pl(t_rt_info data, t_ray ray)
{
	t_plane pl;
	pl = plane(data.coor1, data.normal_vector);

	t_vec p_vec = vplus(pl.center, pl.normal_vector);
	t_vec r_vec = vplus(ray.orig, ray.dir);
	double discriminant = vdot(p_vec, r_vec);

	return (discriminant > 0);
}

double	is_intersect_sp(t_rt_info data, t_ray ray)
{
	t_sphere sp;
	double a;
	double b;
	double c;
	double d;
	t_vec oc;

	sp = sphere(data.coor1, data.diameter);
	
	oc = vminus(ray.orig, sp.center);
	a = vdot(ray.dir, ray.dir);
	b = 2.0 * vdot(oc, ray.dir);
	c = vdot(oc, oc) - sp.radius2;
	d = b * b - 4 * a * c;
	return ((-b - sqrt(d)) / (2.0 * a));
}


int	find_intersect_len(t_rt_info data, t_ray ray)
{
	double rst = INFINITY;

	if (ft_strcmp(data.id, "pl") == 0)
		rst = is_intersect_pl(data, ray);
	else if (ft_strcmp(data.id, "sp") == 0)
		rst = is_intersect_sp(data, ray);
	//else if (ft_strcmp(data.id, "cy") == 0)
	//	rst = is_intersect_cy(data, ray);
	return (rst);
}

t_node *set_object(t_ray ray, t_list *list)
{
	t_node *rtn = 0;
	double min_inter = INFINITY;
	double len_inter = INFINITY;

	list->cur = list->head;
	while (list->cur != 0)
	{
		if (is_object(list->cur->data) == 1)
		{
			len_inter =	find_intersect_len(list->cur->data, ray);
			if(len_inter > 0 && len_inter < min_inter)
			{
				rtn = list->cur;
				min_inter = len_inter;
			}
		}
		list->cur = list->cur->next;
	}
	return (rtn);
}

int	set_color(t_color col)
{
	return (create_rgb((int)col.x, (int)col.y, (int)col.z));
}


t_image	set_image(t_image img, t_list *list)
{
	int			color;
	t_ray		ray;
	t_canvas	canv;
	t_camera	cam;

	//canv
	canv = canvas(RESOL_W, RESOL_H);
	//cam
	list->cur = list->head;
	search_node(&list, "C");
	cam = camera(&canv, list->cur->data);

	for(int i = 0; i < RESOL_W; i++)
	{
		for (int j = 0; j < RESOL_H; j++)
		{
			ray = set_ray(cam, (double)i / (RESOL_W - 1), (double)j / (RESOL_H - 1));
			list->cur = set_object(ray, list);
			if (list->cur == 0)
				color = create_rgb(255, 255, 255);//기본 컬러
			else
				color = set_color(list->cur->data.color);//오브젝트에 스팟광, 그림자 등 적용하기
			mlx_pixel_put_img(&img, i, j, color);
		}
	}
	return (img);
}
