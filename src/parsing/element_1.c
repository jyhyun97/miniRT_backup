/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:28:55 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/20 19:03:12 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structure.h"
#include "../../include/parsing.h"

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
    color->x = atoi(*tmp_color);
    tmp_color++;
    checker += check_int(*tmp_color);
    color->y = atoi(*tmp_color);
    tmp_color++;
    checker += check_int(*tmp_color);
    color->z = atoi(*tmp_color);
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

int	add_normalized_vector(char **split, t_vec *normalized_vector)
{
    char	**split_normal_vector;
    int		checker;

    split_normal_vector = ft_split(*split, ',');
    checker = 0;
    checker += check_double(*split_normal_vector);
    normalized_vector->x = ft_atod(*split_normal_vector);
    split_normal_vector++;
    checker += check_double(*split_normal_vector);
    normalized_vector->y = ft_atod(*split_normal_vector);
    checker += check_double(*split_normal_vector);
    split_normal_vector++;
    normalized_vector->z = ft_atod(*split_normal_vector);

    split_normal_vector -= 2;
    allo_free(split_normal_vector);
    if (normalized_vector->x < -1 || normalized_vector->x > 1 || normalized_vector->y < -1 ||
        normalized_vector->y > 1 || normalized_vector->z < -1 || normalized_vector->z > 1 || checker != 0)
        return (-1);
    return (0);
}
