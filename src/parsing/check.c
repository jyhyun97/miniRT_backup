/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:24:02 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/28 17:21:18 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

int check_int(char *s)
{
    if (*s == '-')
        s++;
    while (*s != '\0')
    {
        if (*s < '0' || *s > '9')
            return (-1);
        s++;
    }
    return (0);
}

int check_double(char *s)
{
    if (*s == '-')
        s++;
    while (*s != '\0' && *s != '.')
    {
        if (*s < '0' || *s > '9')
            return (-1);
        s++;
    }
    if (*s == '.')
    {
        s++;
        while (*s != '\0')
        {
        if (*s < '0' || *s > '9')
            return (-1);
        s++;
        }
    }
    return (0);
}

int check_id(t_list *list)
{
    if (count_node(list, "A") != 1 || count_node(list, "C") != 1 || count_node(list, "L") != 1)
        return (-1);
    return (0);
}
