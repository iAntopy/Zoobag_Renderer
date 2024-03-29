/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_bg_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:31:10 by iamongeo          #+#    #+#             */
/*   Updated: 2022/08/06 15:38:11 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadds.h"

void	mlx_set_bg_color(t_mlx *mlx, int col)
{
	size_t	*b;
	int	*p;
	size_t	total_bytes;
	size_t	xl;

	printf("starting set bg color\n");
	p = (int *)&xl;
	*p = col;
	*(p + 1) = col;

	b = (size_t *)mlx->off_buff->addr;
	total_bytes = mlx->buff_size;
	printf("set bg col : total_bytes to set : %zu\n", total_bytes);
	while (total_bytes >= sizeof(size_t))
	{
		*(b++) = xl;
		total_bytes -= sizeof(size_t);
	}
	printf("set bg col : total_bytes left : %zu\n", total_bytes);
	p = (int *)b;
	while (total_bytes >= sizeof(int))
	{
		*(p++) = col;
		total_bytes -= sizeof(int);
	}
	printf("set bg col : background color set successfully\n");
}
