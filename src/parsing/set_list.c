/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:37:29 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/28 17:30:48 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include "../../include/structure.h"
#include "../gnl/get_next_line.h"
#include <fcntl.h>

int	split_put_data(char **split, t_rt_info data, t_list *list)
{
	int cnt_s;
	int cnt_c;

	cnt_s = count_split(split);
	cnt_c = count_comma(split);
	if (ft_strcmp(*split, "A") == 0 && cnt_s == 3 && cnt_c == 2)
		return (add_a(split, data, list));
	else if (ft_strcmp(*split, "C") == 0 && cnt_s == 4 && cnt_c == 4)
		return (add_c(split, data, list));
	else if (ft_strcmp(*split, "L") == 0 && cnt_s == 4 && cnt_c == 4)
		return (add_l(split, data, list));
	else if (ft_strcmp(*split, "pl") == 0 && cnt_s == 4 && cnt_c == 6)
		return (add_pl(split, data, list));
	else if (ft_strcmp(*split, "sp") == 0 && cnt_s == 4 && cnt_c == 4)
		return (add_sp(split, data, list));
	else if (ft_strcmp(*split, "cy") == 0 && cnt_s == 6 && cnt_c == 6)
		return (add_cy(split, data, list));
	else if (ft_strcmp(*split, "") == 0)
		return (0);
	return (-1);
}


int	set_list(t_list *list, char *argv)
{
	int			fd;
	char		*line;
	char		**split;
	t_rt_info	data;

	fd = open(argv, O_RDWR);
	data.id = NULL;
	if (fd == -1)
		put_err("check the file path", list);
	while (get_next_line(fd, &line) > 0)
	{
		if (*line != '\0')
		{
			split = ft_split(line, ' ');
			if (split_put_data(split, data, list) < 0)
				put_err("element error", list);
			split = allo_free(split);
		}
		free(line);
	}
	free(line);
	if (check_id(list) == -1)
		put_err("check A or C or L", list);
	close(fd);
	return (0);
}
