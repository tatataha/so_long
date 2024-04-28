/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:38:13 by muhcelik          #+#    #+#             */
/*   Updated: 2023/05/06 16:49:44 by muhcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	tc_map;
	t_mlx	*mlx;

	if (argc != 2)
	{
		ft_putstr("error: arguman count is not two\n");
		exit(1);
	}
	check_arg(argv, &tc_map);
	ber_check(argv);
	path_checker(&tc_map);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	related_to_mlx(&tc_map, mlx);
}
