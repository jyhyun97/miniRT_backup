/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhyun <jeonhyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:37:29 by jeonhyun          #+#    #+#             */
/*   Updated: 2021/05/20 20:09:55 by jeonhyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include "../../include/structure.h"
#include "../gnl/get_next_line.h"
#include <fcntl.h>

int	split_put_data(char **split, t_rt_info data, t_list *list)
{
	int cnt;

	cnt = count_split(split);
	if (ft_strcmp(*split, "R") == 0 && cnt == 3)
		return (add_r(split, data, list));
	else if (ft_strcmp(*split, "A") == 0 && cnt == 3)
		return (add_a(split, data, list));
	else if (ft_strcmp(*split, "c") == 0 && cnt == 4)
		return (add_c(split, data, list));
	else if (ft_strcmp(*split, "l") == 0 && cnt == 4)
		return (add_l(split, data, list));
	else if (ft_strcmp(*split, "sp") == 0 && cnt == 4)
		return (add_sp(split, data, list));
	else if (ft_strcmp(*split, "pl") == 0 && cnt == 4)
		return (add_pl(split, data, list));
	else if (ft_strcmp(*split, "sq") == 0 && cnt == 5)
		return (add_sq(split, data, list));
	else if (ft_strcmp(*split, "cy") == 0 && cnt == 6)
		return (add_cy(split, data, list));
	else if (ft_strcmp(*split, "tr") == 0 && cnt == 5)
		return (add_tr(split, data, list));
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
		put_err("\ncheck the file path\n", list);
	while (get_next_line(fd, &line) > 0)
	{
		if (*line != '\0')
		{
			split = ft_split(line, ' ');
			if (split_put_data(split, data, list) < 0)
				put_err("element error\n", list);
			printf("%s\n",list->tail->data.id);
			split = allo_free(split);
		}
		free(line);
	}
	if (check_id(list) == -1)
		put_err("R or A not only one\n", list);
	close(fd);
	return (0);
}
