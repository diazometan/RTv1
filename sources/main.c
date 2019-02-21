/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 10:51:40 by rgyles            #+#    #+#             */
/*   Updated: 2019/02/21 14:17:48 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static int		close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

static void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractol");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.img_data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
		&mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
}

int	main(int args, char **argv)
{
	t_mlx	mlx;

	init_mlx(&mlx);
	create_img(&mlx);
	mlx_hook(mlx.win_ptr, 2, 0, &key_press, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &close_win, &mlx);
	mlx_loop(mlx.mlx_ptr);
	printf("first run successful\n");
	ft_putstr("libft works fine\n");
	return (0);
}
