/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_buffers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:04:27 by iamongeo          #+#    #+#             */
/*   Updated: 2022/08/03 19:53:18 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlxadds.h"

// pushes screen_buff to window and swaps buffers for next draw.
void	mlx_render_buffer(t_mlx *mlx)
{
	printf("Render buffer starts\n");
	printf("swapping buffers\n");
	mlx_swap_buffers(mlx);
	printf("buffers swapped\n");
	printf("Putting imag to window\n");
	printf("conn ptr %p, win ptr %p, screen_buff ptr %p\n", mlx->conn, mlx->win, mlx->screen_buff);
	if (mlx_put_image_to_window(mlx->conn, mlx->win, mlx->screen_buff->img, 0, 0) >= 0)
		printf("Buffer rendered successfully\n");
}
