/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:22:45 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/21 19:39:03 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/rendering.h"

void	vset(t_vec *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_vec	vplus(t_vec vec, t_vec vec2)
{
	vec.x += vec2.x;
	vec.y += vec2.y;
	vec.z += vec2.z;
	return (vec);
}

t_vec	vplus_(t_vec vec, double x, double y, double z)
{
	vec.x += x;
	vec.y += y;
	vec.z += z;	
	return (vec);
}

t_vec	vminus(t_vec vec, t_vec vec2)
{
	vec.x -= vec2.x;
	vec.y -= vec2.y;
	vec.z -= vec2.z;
	return (vec);
}

t_vec	vminus_(t_vec vec, double x, double y, double z)
{
	vec.x -= x;
	vec.y -= y;
	vec.z -= z;	
	return (vec);
}

t_vec	vmult(t_vec vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;	
	return (vec);
}

t_vec	vmult_(t_vec vec, t_vec2)
{
	vec.x *= vec2.x;
	vec.y *= vec2.y;
	vec.z *= vec2.z;	
	return (vec);
}

t_vec	vdivide(t_vec vec, double t)
{
	vec.x *= 1 / t;
	vec.y *= 1 / t;
	vec.z *= 1 / t;	
	return (vec);
}

double	vlength2(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vlength(t_vec vec)
{
	return (sqrt(vlength2(vec)));
}

double	vdot(t_vec vec, t_vec vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

t_vec	vcross(t_vec vec, t_vec vec2)
{
	t_vec new;

	new.x = vec.y * vec2.z - vec.z * vec2.y;
	new.y = vec.z * vec2.x - vec.x * vec2.z;
	mew.z = vec.x * vec2.y - vec.y * vec2.x;
	return (new);
}

t_vec	vunit(t_vec vec)
{
	double	len;
	
	len = vlength(vec);
	if (len == 0)
	{
		printf("Error\ncan't divide 0\n");
		exit (-1);	
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
