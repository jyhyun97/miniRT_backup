/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:21:44 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/20 17:50:30 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int				ft_strlcpy(char *dst, const char *src, int dstsize)
{
    int  i;
    int  j;

    i = 0;
    j = 0;
    if (dst == 0 || src == 0)
        return (0);
    while (src[i] != '\0')
        i++;
    while (src[j] != '\0' && j < dstsize - 1 && dstsize != 0)
    {
        dst[j] = src[j];
        j++;
    }
    if (dstsize > 0)
        dst[j] = '\0';
    return (i);
}

int				count_split(char **split)
{
    int i;
   
	i = 0;
    while (*split++ != 0)
        i++;
    return (i);
}
