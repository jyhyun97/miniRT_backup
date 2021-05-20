/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:31:11 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/20 19:05:45 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structure.h"
#include "../../include/parsing.h"


int add_pl(char **split, t_rt_info data, t_list *list)
{
    data.id = "pl";
    split++;
    if (add_coordinate(split, &data.coor1) == -1)
        return (-1);
    split++;
    if (add_normalized_vector(split, &data.normal_vector) == -1)
        return (-1);
    split++;
    if (add_color(split, &data.color) == -1)
        return (-1);

    add_node(list, data);
    return (0);
}

int add_sq(char **split, t_rt_info data, t_list *list)
{
    int checker;

    data.id = "sq";
    checker = 0;
    split++;
    if (add_coordinate(split, &data.coor1) == -1)
        return (-1);
    split++;
    if (add_normalized_vector(split, &data.normal_vector) == -1)
        return (-1);
    split++;
    checker += check_double(*split);
    data.side_size = ft_atod(*split);
    split++;
    if (add_color(split, &data.color) == -1 || checker != 0)
        return (-1);
    add_node(list, data);
    return (0);
}

int add_cy(char **split, t_rt_info data, t_list *list)
{
    int checker;

    data.id = "cy";
    checker = 0;
    split++;
    if (add_coordinate(split, &data.coor1) == -1)
        return (-1);
    split++;
    if (add_normalized_vector(split, &data.normal_vector) == -1)
        return (-1);
    split++;
    checker += check_double(*split);
    data.diameter = ft_atod(*split);
    split++;
    checker += check_double(*split);
    data.side_size = ft_atod(*split);
    split++;
    if (add_color(split, &data.color) == -1 || checker != 0)
        return (-1);
	add_node(list, data);
	return (0);
}

int add_tr(char **split, t_rt_info data, t_list *list)
{
    data.id = "tr";
    split++;
    if (add_coordinate(split, &data.coor1) == -1)
        return (-1);
    split++;
    if (add_coordinate(split, &data.coor2) == -1)
        return (-1);
    split++;
    if (add_coordinate(split, &data.coor3) == -1)
        return (-1);
    split++;
    if (add_color(split, &data.color) == -1)
        return (-1);

    add_node(list, data);
    return (0);
}
