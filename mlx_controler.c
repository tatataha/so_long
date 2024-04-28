/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:39:25 by muhcelik          #+#    #+#             */
/*   Updated: 2023/05/06 16:57:37 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_checker(t_mlx *mlx, t_map *tc_map)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->m, mlx->x1, mlx->y1);
	if (tc_map->current_coin == tc_map->coin_count)
	{
		ft_putstr("success\n");
		exit(0);
	}
}

void	xpm_to_img(t_mlx *map)
{
	map->p_p = "./xpms/player.xpm";
	map->w_p = "./xpms/wall.xpm";
	map->c_p = "./xpms/coin.xpm";
	map->g_p = "./xpms/door.xpm";
	map->f_p = "./xpms/background.xpm";
	map->m_p = "./xpms/playerg.xpm";
	map->w = mlx_xpm_file_to_image(map->init, map->w_p, &map->x, &map->y);
	map->p = mlx_xpm_file_to_image(map->init, map->p_p, &map->x, &map->y);
	map->c = mlx_xpm_file_to_image(map->init, map->c_p, &map->x, &map->y);
	map->g = mlx_xpm_file_to_image(map->init, map->g_p, &map->x, &map->y);
	map->f = mlx_xpm_file_to_image(map->init, map->f_p, &map->x, &map->y);
	map->m = mlx_xpm_file_to_image(map->init, map->m_p, &map->x, &map->y);
	if (!map->p || !map->w || !map->c || !map->g || !map->f || !map->m)
	{
		ft_putstr("error: there is no path\n");
		exit(1);
	}
}

void	print_picture(t_mlx *mlx, char c, t_map *tc_map)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->f, mlx->x1, mlx->y1);
	if (c == '1')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->w, mlx->x1, mlx->y1);
	if (c == 'C')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->c, mlx->x1, mlx->y1);
	if (c == 'E')
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->g, mlx->x1, mlx->y1);
	if (c == 'P')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->p, mlx->x1, mlx->y1);
		if (tc_map->exit_col == tc_map->p_col
			&& tc_map->exit_row == tc_map->p_row)
			exit_checker(mlx, tc_map);
	}
}

void	put_picture(t_mlx *mlx, t_map *tc_map)
{
	int	i;
	int	j;

	i = 0;
	mlx->y1 = 0;
	while (tc_map->map[i] != NULL)
	{
		j = 0;
		mlx->x1 = 0;
		while (tc_map->map[i][j] != '\0')
		{
			print_picture(mlx, tc_map->map[i][j], tc_map);
			j++;
			mlx->x1 += 64;
		}
		mlx->y1 += 64;
		i++;
	}
}
