/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:40:11 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/21 19:36:52 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void put_err(char *err_msg, t_list *list)
{
	del_node(&list);
	printf("Error\n%s\n", err_msg);
	system("leaks miniRT > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	exit(-1);
}

