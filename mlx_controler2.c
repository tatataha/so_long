/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:39:40 by muhcelik          #+#    #+#             */
/*   Updated: 2023/05/06 16:57:49 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int *step, int dx, int dy, t_map *tc_map)
{
	if (tc_map->map[tc_map->p_row + dy][tc_map->p_col + dx] != '1')
	{
		if (tc_map->map[tc_map->p_row + dy][tc_map->p_col + dx] == 'C')
			tc_map->current_coin++;
		tc_map->map[tc_map->p_row][tc_map->p_col] = '0';
		tc_map->map[tc_map->p_row + dy][tc_map->p_col + dx] = 'P';
		tc_map->p_row += dy;
		tc_map->p_col += dx;
		ft_putstr("step:");
		ft_putnbr(++(*step));
		ft_putstr("\n");
	}
}

void	write_s(t_mlx *mlx, int step, t_map *tc_map)
{
	char	*v;
	char	*a;
	char	*b;

	v = ft_itoa(step);
	a = ft_itoa(tc_map->current_coin);
	b = ft_itoa(tc_map->coin_count);
	mlx_string_put(mlx->init, mlx->win, 5, 20, 0xf5fffa, "step: ");
	mlx_string_put(mlx->init, mlx->win, 5, 40, 0xf5fffa, "coin count: ");
	mlx_string_put(mlx->init, mlx->win, 100, 40, 0x000080, b);
	mlx_string_put(mlx->init, mlx->win, 45, 20, 0x97ffff, v);
	mlx_string_put(mlx->init, mlx->win, 83, 40, 0x97ffff, a);
	free(v);
	free(a);
	free(b);
}

int	ft_movement(int key, t_mlx *mlx)
{
	static int	step;
	t_map		*tc_map;

	tc_map = &mlx -> asd;
	if (key != 0 && key != 2 && key != 1 && key != 13 && key != 53)
		return (1);
	if (key == 53)
	{
		exit(0);
	}
	move(&step, (key == 2) - (key == 0), (key == 1) - (key == 13), tc_map);
	if ((tc_map->exit_col != tc_map->p_col
			|| tc_map->exit_row != tc_map->p_row))
			tc_map->map[tc_map->exit_row][tc_map->exit_col] = 'E';
	if (tc_map->exit_col == tc_map->p_col && tc_map->exit_row == tc_map->p_row)
		exit_checker(mlx, tc_map);
	put_picture(mlx, tc_map);
	write_s(mlx, step, tc_map);
	return (0);
}

void	related_to_mlx(t_map *tc_map, t_mlx *mlx)
{
	int	l;
	int	c;

	l = tc_map->l_cnt * 64;
	c = tc_map->w_cnt * 64;
	mlx->init = mlx_init();
	xpm_to_img(mlx);
	mlx->win = mlx_new_window(mlx->init, c, l, "so_long");
	put_picture(mlx, tc_map);
	ft_putstr("step:0\n");
	write_s(mlx, 0, tc_map);
	mlx->asd = (t_map){.map = tc_map -> map, .l_cnt = tc_map -> l_cnt, \
	.w_cnt = tc_map-> w_cnt, .p_col = tc_map -> p_col, \
	.p_row = tc_map -> p_row, .coin_count = tc_map -> coin_count, \
	.chk_player = tc_map -> chk_player, .exit_count = tc_map -> exit_count, \
	.exit_col = tc_map -> exit_col, .exit_row = tc_map -> exit_row, \
	.current_coin = tc_map -> current_coin};
	mlx_hook(mlx->win, 2, 1L << 0, ft_movement, mlx);
	mlx_hook(mlx->win, 17, 1L << 0, ft_exit, mlx);
	mlx_loop(mlx->init);
}
