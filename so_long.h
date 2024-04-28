/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:40:06 by muhcelik          #+#    #+#             */
/*   Updated: 2023/05/06 16:55:32 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./SRC/get_next_line/get_next_line.h"
# include <fcntl.h>
# include "./SRC/mlx/mlx.h"

typedef struct s_map
{
	char	**map;
	int		l_cnt;
	int		w_cnt;
	int		p_col;
	int		p_row;
	int		coin_count;
	int		chk_player;
	int		exit_count;
	int		exit_col;
	int		exit_row;
	int		current_coin;
}	t_map;

typedef struct s_mlx
{
	char	*p_p;
	char	*w_p;
	char	*c_p;
	char	*g_p;
	char	*f_p;
	char	*m_p;

	int		x;
	int		y;

	int		x1;
	int		y1;

	char	*p;
	char	*w;
	char	*c;
	char	*g;
	char	*f;
	char	*m;

	void	*win;
	void	*init;
	t_map	asd;
}	t_mlx;

void	map_lines(char **argv, t_map *tc_map);
void	readmap(char **argv, t_map *tc_map);
void	map_info(char **argv, t_map *tc_map);
void	check_arg(char **argv, t_map *tc_map);
void	check_map_chars(char c);
void	wall_check(char **argv, t_map *tc_map);
void	wall_row_check(t_map *tc_map);
int		ber_check(char **argv);
char	*ft_strdup(const char *s1);
int		path_checker(t_map *tc_map);
void	xpm_to_img(t_mlx *map);
void	related_to_mlx(t_map *tc_map, t_mlx *mlx);
void	put_picture(t_mlx *mlx, t_map *tc_map);
void	print_picture(t_mlx *mlx, char c, t_map *tc_map);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	exit_checker(t_mlx *mlx, t_map *tc_map);
char	*ft_itoa(int n);
void	map_free(char **map);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);
int		ft_exit(int key, t_mlx *mlx);
#endif