/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:07:24 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/28 17:23:20 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/rendering.h"
#include "../include/structure.h"
#include "../include/define.h"

void	parsing(t_list *list, char *argv)
{
	printf("%s opening...\n", argv);
	set_list(list, argv);
	printf("parsing success\n");
}

void rendering(t_list *list)
{
	void	*mlx;
	void	*win;
	t_image	img;
	//t_resolution resol;

	mlx = mlx_init();
	//list->cur = list->head;
	//search_node(&list, "R");
	//resol.width = list->cur->data.resolution.width;
	//resol.height = list->cur->data.resolution.height;

	win = mlx_new_window(mlx, RESOL_W, RESOL_H, "miniRT");
	img.img = mlx_new_image(mlx, RESOL_W, RESOL_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		
	img = set_image(img, list);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	//mlx_hook... 종료신호는 list 다 free해주고 exit하는 걸 잊지 말 것.
}


int		main(int argc, char *argv[])
{
	t_list	*list;

	if (argc == 2 && ft_strcmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt") == 0)
	{
		init_list(&list);
		parsing(list, argv[1]);
		rendering(list);
		del_node(&list);
	}
	else
		printf("invalid path\n");
	system("leaks miniRT > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
