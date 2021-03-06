/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:30:36 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/28 17:33:35 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structure.h"
#include "../../include/parsing.h"

int add_a(char **split, t_rt_info data, t_list *list)
{
    int checker;

    data.id = "A";
    checker = 0;
    split++;
    checker = check_double(*split);
    data.brightness = ft_atod(*split); //0.0 ~ 1.0
    split++;
    if (add_color(split, &data.color) == -1 || data.brightness < 0 || data.brightness > 1 || checker != 0)
        return (-1);
    add_node(list, data);
    return (0);
}

int add_c(char **split, t_rt_info data, t_list *list)
{
    int checker;

    data.id = "C";
    checker = 0;
    split++;
    if (add_coordinate(split, &data.coor1) == -1)
        return (-1);
    split++;
    if (add_normalized_vector(split, &data.normal_vector) == -1)
        return (-1);
    split++;
    checker += check_int(*split);
    data.view_degree = ft_atoi(*split); //0~180
    if (data.view_degree < 0 || data.view_degree > 180 || checker != 0)
        return (-1);
    add_node(list, data);
    return (0);
}

int add_l(char **split, t_rt_info data, t_list *list)
{
    int checker;

    data.id = "L";
    checker = 0;
    split++;
    if (add_coordinate(split, &data.coor1) == -1)
        return (-1);
    split++;
    checker += check_double(*split);
    data.brightness = ft_atod(*split);
    split++;
    if (add_color(split, &data.color) == -1 || data.brightness < 0 || data.brightness > 1 || checker != 0)
        return (-1);

    add_node(list, data);
    return (0);
}

int add_sp(char **split, t_rt_info data, t_list *list)
{
    int checker;

    data.id = "sp";
    checker = 0;
    split++;
    if (add_coordinate(split, &data.coor1) == -1)
        return (-1);
    split++;
    checker += check_double(*split);
    data.diameter = ft_atod(*split);
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
