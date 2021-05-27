/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:00:39 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/27 17:52:17 by jeonhyun         ###   ########.fr       */
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

t_ray	set_ray(t_camera cam, double u, double v)//make one ray beam~~
{
	t_ray	ray;
	
	ray.orig = cam.orig;
	ray.dir = vunit(vminus(vplus(vplus(cam.left_bottom, vmult(cam.horizontal, u)), vmult(cam.vertical, v)), cam.orig));
	return (ray);
}

int	is_object(t_rt_info data)
{
	if (ft_strcmp(data.id, "pl") == 0 || ft_strcmp(data.id, "sp") == 0 || ft_strcmp(data.id, "sq") == 0 || ft_strcmp(data.id,"cy") == 0 || ft_strcmp(data.id, "tr"))
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

	return ((int)discriminant == 0);
}

int	find_intersect_len(t_rt_info data, t_ray ray)
{
	int rst = INFINITY;

	/*
	if (data.id == "pl")
		rst = intersect_len_pl(data, ray);
	else if (data.id == "sp")
		rst = intersect_len_sp(data, ray);
	else if (data.id == "sq")
		rst = intersect_len_sq(data, ray);
	else if (data.id == "cy")
		rst = intersect_len_cy(data, ray);
	else if (data.id == "tr")
		rst = intersect_len_tr(data, ray);
	*/
	if (ft_strcmp(data.id, "pl") == 0)
		rst = is_intersect_pl(data, ray);
	return (rst);
}

int set_object(t_ray ray, t_list *list)
{
//그냥 그 오브젝트의 색상값 반환하는 걸로 바꿨다... 그냥.... 임시로...
//아니... 일단 true false만.. 하자... 천천히.. 하자..
	t_color rtn = color(255, 255, 255);//디폴트 컬러. 이건 따로 define하는 게 나을 것 같네

	list->cur = list->head;
	while (list->cur != 0)
	{
		if (is_object(list->cur->data) == 1)
		{
			if(find_intersect_len(list->cur->data, ray) > 0)
			{
				rtn = list->cur->data.color;
			}
		}
		list->cur = list->cur->next;
	}
	return (create_rgb((int)rtn.x, (int)rtn.y, (int)rtn.z));
}


t_image	set_image(t_image img, t_list *list)
{
	int			color;
	t_ray		ray;
	t_canvas	canv;
	t_camera	cam;

	//canv
	list->cur = list->head;
	search_node(&list, "R");
	canv = canvas(list->cur->data.resolution.width, list->cur->data.resolution.height);
	//cam
	list->cur = list->head;
	search_node(&list, "c");
	cam = camera(&canv, list->cur->data.coor1, list->cur->data.normal_vector);

	for(int i = 0; i < canv.width; i++)
	{
		for (int j = 0; j < canv.height; j++)
		{
			color = 0x00ffffff;//기본 배경색
			ray = set_ray(cam, (double)i / (canv.width - 1), (double)j / (canv.height - 1));
			color = set_object(ray, list);
			//if (ft_strcmp(list->cur->data.id, "pl") == 0) //테스트용
			//	color = 0x00000000;
			//color = set_color();//오브젝트에 주변광, 스팟광, 그림자 등 적용하기
			mlx_pixel_put_img(&img, i, j, color);
		}
	}
	return (img);
}
