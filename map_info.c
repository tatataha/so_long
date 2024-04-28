/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:39:14 by muhcelik          #+#    #+#             */
/*   Updated: 2023/05/06 16:51:16 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_lines(char **argv, t_map *tc_map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_putstr("error: there is no map\n");
		exit(1);
	}
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	tc_map->l_cnt = i;
	close(fd);
}

void	exit_finder(char **map, t_map *tc_map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				tc_map->exit_col = j;
				tc_map->exit_row = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	readmap(char **argv, t_map *tc_map)
{
	char	*str;
	int		i;
	int		fd;

	map_lines(argv, tc_map);
	tc_map->map = malloc((tc_map->l_cnt + 1) * sizeof(char *));
	if (!tc_map->map)
		return ;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (tc_map->l_cnt-- > 0)
	{
		str = get_next_line(fd);
		tc_map->map[i++] = str;
	}
	tc_map->map[i] = NULL;
	exit_finder(tc_map->map, tc_map);
	close(fd);
	tc_map->w_cnt = ft_strlen(tc_map->map[0]) - 1;
}

void	map_info(char **argv, t_map *tc_map)
{
	int	i;
	int	j;

	i = -1;
	readmap(argv, tc_map);
	while (tc_map->map[++i])
	{
		j = -1;
		while (tc_map->map[i][++j])
		{
			if (tc_map->map[i][j] == 'E')
				tc_map->exit_count++;
			else if (tc_map->map[i][j] == 'P')
			{
				tc_map->chk_player++;
				tc_map->p_col = j;
				tc_map->p_row = i;
			}
			else if (tc_map->map[i][j] == 'C')
				tc_map->coin_count++;
			else
				check_map_chars(tc_map->map[i][j]);
		}
	}
	wall_check(argv, tc_map);
}
