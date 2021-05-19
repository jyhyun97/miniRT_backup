/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:44:49 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/19 21:18:16 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include <stdio.h> //must be delete

int main(int argc, char *argv[])
{
	if (argc == 2 && ft_strcmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt") == 0)
	{
		//parsing
		printf("test");
		//rendering
	}
	else
	{
		printf("aaa");
		//err
	}
	//system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leak    ed | rm -rf leaks_result_temp");
	return (0);
}
