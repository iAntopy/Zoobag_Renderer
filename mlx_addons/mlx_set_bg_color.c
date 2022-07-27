/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_bg_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:31:10 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/27 08:24:19 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadds.h"

void	mlx_set_bg_color(t_mlx *mlx, int col)
{
	size_t	*b;
	int	*p;
	int	nb_pxl;
	size_t	xl;

	p = (int *)&xl;
	*p = col;
	*(p + 1) = col;

	b = (size_t*)mlx->off_buff->addr;
	nb_pxl = mlx->width * mlx->height;
	while (nb_pxl <= 2)
	{
		*(b++) = xl;
		nb_pxl -= 2;
	}
	if (nb_pxl)
		*(int *)b = col;
/*
	b = (int *)mlx->off_buff->addr;
	nb_pxl = mlx->width * mlx->height;
	while (nb_pxl--)
		*(b++) = col;
*/
}
