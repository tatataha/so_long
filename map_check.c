/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:38:57 by muhcelik          #+#    #+#             */
/*   Updated: 2023/05/06 18:41:26 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_chars(char c)
{
	if (c != 'C' && c != 'P' && c != 'E' && c != '0' && c != '1' && c != '\n')
	{
		ft_putstr("error: Invalid character in map.\n");
		exit(1);
	}
}

void	check_arg(char **argv, t_map *tc_map)
{
	map_info(argv, tc_map);
	if (tc_map->chk_player != 1
		||tc_map->exit_count != 1 || tc_map->coin_count == 0)
	{
		free(tc_map->map);
		ft_putstr("error: number of arguments is not correct\n");
		exit(1);
	}
}

void	wall_row_check(t_map *tc_map)
{
	int	i;
	int	a;

	a = 0;
	while (a < tc_map->l_cnt - 1)
	{
		i = ft_strlen(tc_map->map[a]) - 1;
		if (i != tc_map->w_cnt)
		{
			ft_putstr("error: lines are not equal in length\n");
			exit(1);
		}
		a++;
	}
	i = ft_strlen(tc_map->map[a]);
	if (i != tc_map->w_cnt)
	{
		ft_putstr("error: lines are not equal in length\n");
		exit(1);
	}
}

void	wall_check(char **argv, t_map *tc_map)
{
	int	i;
	int	j;

	map_lines(argv, tc_map);
	wall_row_check(tc_map);
	i = -1;
	while (tc_map->map[++i])
	{
		j = -1;
		while (tc_map->map[i][++j] && j < tc_map->w_cnt)
		{
			if (tc_map->map[i][0] != '1' ||
				tc_map->map[i][tc_map->w_cnt - 1] != '1' \
				|| tc_map->map[0][j] != '1' ||
				tc_map->map[tc_map->l_cnt - 1][j] != '1')
			{
				ft_putstr("error: the walls are not complete\n");
				exit(1);
			}
		}
	}
}

int	ber_check(char **argv)
{
	char	*str;
	char	*str1;

	str = ft_strrchr(argv[1], '.');
	str1 = ft_strrchr(argv[1], '/');
	if (str == NULL)
	{
		ft_putstr("Error : file is not find. \n");
		exit(1);
	}
	if (str1[1] == '.' && str1[2] != '.' && ft_strlen(str1) > 5)
	{
		ft_putstr("Error : this is a hidden ber file. \n");
		exit(1);
	}
	else if ((ft_strcmp(str, ".ber") != 0) || (ft_strlen(str1) <= 5))
	{
		ft_putstr("Error : wrong filename. \n");
		exit(1);
	}
	return (0);
}
