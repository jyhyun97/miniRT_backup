/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:00:39 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/06/04 17:14:46 by jeonhyun         ###   ########.fr       */
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

void set_light(t_light *li, t_ambient *am, t_list *list)
{
	list->cur = list->head;
	search_node(&list, "L");
	*li = light(list->cur->data.coor1, list->cur->data.brightness, list->cur->data.color);
	list->cur = list->head;
	search_node(&list, "A");
	*am = ambient(list->cur->data.brightness, list->cur->data.color);
}

void	set_ambient(t_color *color, t_ambient ambient)
{
	*color = vmult_(*color, vnorm(vmult(ambient.color, ambient.brightness)));
	//*color = vplus(*color, vnorm(vmult(ambient.color, ambient.brightness)));
}

//void	set_difffuse() //레이, 교점, 반사각, 옵젝, 광원 등
//레이 반사각과 교점에서 광원까지 들고 가서 뭔가를 하기...

int	set_color(t_rt_info data, t_list *list)
{
	t_color color;
	t_light light;
	t_ambient ambient;

	set_light(&light, &ambient, list);//list 돌면서 search해서 두 개 저장하기~~!
	color = data.color;
	set_ambient(&color, ambient);
	printf("%.s", data.id);
	//set_diffuse();
	//set_specular();
	//set_shadow();
	
	return (create_rgb((int)color.x, (int)color.y, (int)color.z));
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
				color = set_color(list->cur->data, list);//오브젝트에 스팟광, 그림자 등 적용하기
			mlx_pixel_put_img(&img, i, j, color);
		}
	}
	return (img);
}
