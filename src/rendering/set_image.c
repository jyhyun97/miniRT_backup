/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:00:39 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/21 20:15:10 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structure.h"
#include "../../include/parsing.h"
#include "../../include/rendering.h"

/*
t_ray	set_ray(t_list *list, double u, double v)
{
	t_canvas can;
	t_camera cam;

	//search R
	//can = canvas();
	//
	//search c
	//cam = camera();

	t_ray	ray;
	ray.orig = cam.orig;
	ray.dir = vuint(vminus(vplus(vplus(dam->left_bottom, vmult(com->horizontal, u)), vmult(cam->vertical, v)), cam->orig));
	return (ray);
}
*/

void	mlx_pixel_put_img(t_image *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_image	set_image(t_image img, t_list *list)
{
	int color;

	list->cur = list->head;
	search_node(&list, "R");
	for(int i = 0; i < list->cur->data.resolution.width; i++)
	{
		for (int j = 0; j < list->cur->data.resolution.height; j++)
		{
			color = 0x00ffffff;//기본 배경색
			//set_ray();//
			//set_object();
			//color = set_color();//
			mlx_pixel_put_img(&img, i, j, color);
		}
	}
	return (img);
}
