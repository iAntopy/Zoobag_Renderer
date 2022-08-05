/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:24:57 by iamongeo          #+#    #+#             */
/*   Updated: 2022/08/04 15:33:56 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadds.h"

void	mlx_close(t_mlx *mlx)
{
	printf("mlx_close : destroying screen_buff\n");
	if (mlx->screen_buff)
		mlx_destroy_image(mlx->conn, mlx->screen_buff->img);
	printf("mlx_close : destroying off_buff\n");
	if (mlx->off_buff)
		mlx_destroy_image(mlx->conn, mlx->off_buff->img);
	printf("mlx_close : buffers destroyed\n");
	mlx->screen_buff = NULL;
	mlx->off_buff = NULL;
	printf("mlx_close : destroying window\n");
	mlx_destroy_window(mlx->conn, mlx->win);
#ifdef __linux__
	printf("mlx_close : linux destroying display\n");
	mlx_destroy_display(mlx->conn);
#endif
	printf("mlx_close : mlx close SUCCESSFUL !\n");
}
