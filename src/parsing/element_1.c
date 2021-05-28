/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:28:55 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/28 20:01:41 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structure.h"
#include "../../include/parsing.h"
#include "../../include/rendering.h"

int add_color(char **split, t_color *color)
{
    char	**tmp_color;
    int		checker;

    tmp_color = ft_split(*split, ',');
    if (count_split(tmp_color) != 3)
    {
        allo_free(tmp_color);
        return (-1);
    }
    checker = 0;
    checker += check_int(*tmp_color);
    color->x = ft_atod(*tmp_color);
    tmp_color++;
    checker += check_int(*tmp_color);
    color->y = ft_atod(*tmp_color);
    tmp_color++;
    checker += check_int(*tmp_color);
    color->z = ft_atod(*tmp_color);
    tmp_color -= 2;
    allo_free(tmp_color);
    if (color->x > 255 || color->y > 255 || color->z > 255 || checker != 0)
        return (-1);
    return (0);
}

int add_coordinate(char **split, t_vec *coor)
{
    char	**coordinate;
    int		checker;

    coordinate = ft_split(*split, ',');
    checker = 0;
    if (count_split(coordinate) != 3)
    {
        allo_free(coordinate);
        return (-1);
    }
    checker += check_double(*coordinate);
    coor->x = ft_atod(*coordinate);
    coordinate++;
    checker += check_double(*coordinate);
    coor->y = ft_atod(*coordinate);
    coordinate++;
    checker += check_double(*coordinate);
    coor->z = ft_atod(*coordinate);
    coordinate -= 2;
    allo_free(coordinate);
    if (checker != 0)
        return (-1);
    return (0);
}

int	add_normalized_vector(char **split, t_vec *normal_vector)
{
    char	**split_normal_vector;
    int		checker;

    split_normal_vector = ft_split(*split, ',');
    checker = 0;
    checker += check_double(*split_normal_vector);
    normal_vector->x = ft_atod(*split_normal_vector);
    split_normal_vector++;
    checker += check_double(*split_normal_vector);
    normal_vector->y = ft_atod(*split_normal_vector);
    checker += check_double(*split_normal_vector);
    split_normal_vector++;
    normal_vector->z = ft_atod(*split_normal_vector);

    split_normal_vector -= 2;
    allo_free(split_normal_vector);
    if (normal_vector->x < -1 || normal_vector->x > 1 || normal_vector->y < -1 ||
        normal_vector->y > 1 || normal_vector->z < -1 || normal_vector->z > 1 || checker != 0)
        return (-1);
    return (0);
}

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
