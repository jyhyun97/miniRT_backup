/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:40:11 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/20 18:59:26 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void put_err(char *err_msg, t_list *list)
{
	//free list info alllll
	//list->cur = NULL;
	del_node(&list);
	printf("%s\n", err_msg);
	exit(1);
}

