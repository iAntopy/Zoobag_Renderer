/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_double_buff_window.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 04:01:40 by iamongeo          #+#    #+#             */
/*   Updated: 2022/08/08 23:41:51 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlxadds.h"

static int	init_screen_buffers(t_mlx *mlx, t_img *b1, t_img *b2)
{
	b1->img = mlx_new_image(mlx->conn, mlx->width, mlx->height);
	b2->img = mlx_new_image(mlx->conn, mlx->width, mlx->height);
	if (!b1->img || !b2->img)
		return (0);
	b1->addr = mlx_get_data_addr(b1->img, &b1->bytes_per_pxl, 
		&b1->line_len, &b1->endian);
	b2->addr = mlx_get_data_addr(b2->img, &b2->bytes_per_pxl,
		&b2->line_len, &b2->endian);
	b1->bytes_per_pxl /= 8;
	b2->bytes_per_pxl /= 8;
	printf("bytes per pixel : %d\n", b1->bytes_per_pxl);
	mlx->screen_buff = &mlx->buff1;
	mlx->off_buff = &mlx->buff2;
	mlx->nb_pix = mlx->width * mlx->height;
	mlx->buff_size = b1->line_len * mlx->height;
	printf("init_screen_buffer : mlx->buff_size : %zu\n", mlx->buff_size);
	return (1);
}

//Declare a t_mlx variable in main and pass its pointer to this function.
t_mlx	*mlx_init_double_buff_window(t_mlx *mlx, int width, int height, char *title)
{
	mlx->conn = mlx_init();
	if (!mlx->conn)
		return (NULL);
	mlx->win = mlx_new_window(mlx->conn, width, height, title);
	if (!mlx->win)
		return (NULL);
	mlx->width = width;
	mlx->height = height;
	mlx_clear_window(mlx->conn, mlx->win);
	init_screen_buffers(mlx, &mlx->buff1, &mlx->buff2);
	return (mlx);
}
