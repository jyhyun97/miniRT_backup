/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:23:08 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/20 20:10:19 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/structure.h"

void	parsing(t_list *list, char *argv)
{
	printf("%s\n", argv);
	set_list(list, argv);
	//printf("parsing success");
}

/*
void rendering(t_list *list)
{
	mlx, win, img, loop, hook 등 총체적으로 처리하기. (렌더링 과정에서 에러 발생할 구간이 있을까?)
	종료신호 받으면 list와 안의 요소 다 free하고 끝내기
}
*/

int		main(int argc, char *argv[])
{
	t_list	*list;

	if (argc == 2 && ft_strcmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt") == 0)
	{
		printf("parsing and rendering\n");
		init_list(&list);
		parsing(list, argv[1]);
		//rendering function(&list);
	}
	else
	{
		printf("invalid path\n");
	}
	//system("leaks a.out > leaks_result_temp; cat leaks_result_temp |
	//grep leak    ed | rm -rf leaks_result_temp");
	return (0);
}
