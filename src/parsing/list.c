/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:54:53 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/20 17:34:00 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structure.h"
#include "../../include/parsing.h"

void	init_list(t_list **list)
{
	*list = (t_list *)malloc(sizeof(t_list));
	(*list)->cur = NULL;
	(*list)->head = NULL;
	(*list)->tail = NULL;
}

void	add_node(t_list *list, t_rt_info data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = NULL;
	if (list->head == NULL && list->tail == NULL)
	{
		list->head = new_node;
		list->tail = new_node;
	}
	else
	{
		list->tail->next = new_node;
		list->tail = new_node;
	}
}

void	search_node(t_list *list, char *s)
{
	while (list->cur != 0)
	{
		if (ft_strcmp(list->cur->data.id, s) == 0)
			return ;
		else
			list->cur = list->cur->next;
	}
}

int		count_node(t_list *list, char *s)
{
	int	i;

	i = 0;
	list->cur = list->head;
	while (list->cur != 0)
	{
		if (ft_strcmp(list->cur->data.id, s) == 0)
			i++;
		list->cur = list->cur->next;
	}
	return (i);
}

void	del_node(t_list **list)
{
	t_node	*tmp;

	(*list)->cur = (*list)->head;
	while ((*list)->cur != 0)
	{
		tmp = (*list)->cur->next;
		free((*list)->cur);
		(*list)->cur = tmp;
	}
	free(*list);
}
