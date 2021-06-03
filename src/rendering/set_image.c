/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:00:39 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/06/03 22:05:39 by jeonhyun         ###   ########.fr       */
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

int	set_color(t_rt_info data)
{
	//t_color prosseced_color
	
	return (create_rgb((int)data.color.x, (int)data.color.y, (int)data.color.z));
}


t_image	set_image(t_image img, t_list *list)
{
	int			color;
	t_ray		ray;
	t_canvas	canv;
	t_camera	cam;

	canv = canvas(RESOL_W, RESOL_H);
	
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
				color = create_rgb(255, 255, 255);
			else
				color = set_color(list->cur->data);//오브젝트에 스팟광, 그림자 등 적용하기
			mlx_pixel_put_img(&img, i, j, color);
		}
	}
	return (img);
}
