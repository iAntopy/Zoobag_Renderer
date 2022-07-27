/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:24:57 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/25 21:31:18 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadds.h"

void	mlx_close(t_mlx *mlx)
{
	if (mlx->screen_buff)
		mlx_destroy_image(mlx->conn, mlx->screen_buff->img);
	if (mlx->off_buff)
		mlx_destroy_image(mlx->conn, mlx->off_buff->img);
	mlx->screen_buff = NULL;
	mlx->off_buff = NULL;
	mlx_destroy_window(mlx->conn, mlx->win);
#ifdef __linux__
	mlx_destroy_display(mlx->conn);
#endif
}
