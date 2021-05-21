/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:10:23 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/21 13:10:46 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
    int i;
    int rst;
    int pmsign;

    i = 0;
    rst = 0;
    pmsign = 1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            pmsign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        rst = (rst * 10) + (str[i] - '0');
        i++;
    }
    return (rst * pmsign);
}

static double ft_pow(double a, double b)
{
    double rst;
    int i;

    rst = 1;
    i = 0;
    while (i < (int)b)
    {
        rst *= a;
        i++;
    }
    return (rst);
}

double ft_atod(char *s)
{
    double rst = 0;
    int i = 0;
    while(s[i] != '\0' && s[i] != '.')
    {
        rst = rst * 10 + (s[i] - '0');
        i++;
    }
    if (s[i] == '.')
    {
        i++;
        int j = 1;
        while (s[i] != '\0')
        {
            rst = rst + ((double)(s[i] - '0') / ft_pow(10, j));
            i++;
            j++;
        }
    }
    return (rst);
}
