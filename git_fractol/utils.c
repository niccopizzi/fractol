/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:07:25 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/20 15:38:04 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void image_put_pixel(t_img_data *image, int x, int y, int color)
{
	int offset;
	char *pixel_address;

	offset = (y * image->line_len + x * (image->bits_per_pixel / 8));
	pixel_address = (image->image_address) + offset;
	*(unsigned int *)pixel_address = color;
}
int linear_interpolation(int color_one, float gradient)
{
	int complementary_color;
	int red;
	int green;
	int blue;
	int interpol_color;

	if(gradient == 0)
		return(0);
	red = 255 - (color_one >> 16 & 0xFF);
	green = 255 - (color_one >> 8 & 0xFF);
	blue = 255 - (color_one & 0xFF);
	complementary_color = (red << 16 | green << 8 | blue);
	interpol_color = (color_one) + (complementary_color - color_one) * gradient;
	return (interpol_color);
}