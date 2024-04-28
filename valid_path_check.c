/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:40:43 by muhcelik          #+#    #+#             */
/*   Updated: 2023/05/06 16:40:51 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_duplicator(t_map *tc_map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (tc_map->l_cnt + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (tc_map->map[i])
	{
		copy[i] = ft_strdup(tc_map->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	path_recursive(char **map, int c, int r)
{
	map[r][c] = '*';
	if (map[r + 1][c] != '1' && map[r + 1][c] != '*')
		path_recursive(map, c, r + 1);
	if (map[r - 1][c] != '1' && map[r - 1][c] != '*')
		path_recursive(map, c, r - 1);
	if (map[r][c + 1] != '1' && map[r][c + 1] != '*')
		path_recursive(map, c + 1, r);
	if (map[r][c - 1] != '1' && map[r][c - 1] != '*')
		path_recursive(map, c - 1, r);
}

int	path_checker(t_map *tc_map)
{
	char	**map;
	int		j;
	int		i;

	map = map_duplicator(tc_map);
	path_recursive(map, tc_map->p_col, tc_map->p_row);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '*' && map[i][j] != '\n' &&
			map[i][j] != '1' && map[i][j] != '0')
			{
				ft_putstr("error: wrong  map\n");
				map_free(map);
				exit(1);
			}
		}
	}
	map_free(map);
	return (0);
}
