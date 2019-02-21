/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 10:54:36 by rgyles            #+#    #+#             */
/*   Updated: 2019/02/21 14:12:37 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

//TEMPORARY
# include <stdio.h>
//END

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200

typedef struct	s_img
{
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

void			create_img(t_mlx *mlx);
int				key_press(int key, t_mlx *mlx);
#endif
