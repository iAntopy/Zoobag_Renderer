/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_buff_put_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:50:46 by iamongeo          #+#    #+#             */
/*   Updated: 2022/08/03 20:51:10 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadds.h"

void	mlx_buff_put_pixel(t_img *buff, int x, int y, int color)
{
	char	*pix;

//	printf("buff ptr in put pixel : %p\n", buff);
//	printf("buff->addr ptr in put pixel : %p\n", buff->addr);
//	printf("line_len : %d\n", buff->line_len);
	pix = buff->addr + (y * buff->line_len) + (x * buff->bytes_per_pxl);
//	printf("pix ptr at (%d, %d) : %p\n", x, y, pix);
	*(unsigned int *)pix = color;
}
