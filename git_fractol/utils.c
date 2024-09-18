/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:03 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/18 11:56:11 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void calculate_fractal(t_ptrs data, t_fractal fractal)
{
	if (fractal.type == 'M' || fractal.type == 'm')
		calculate_mandelbrot(data, fractal);
	if (fractal.type == 'J' || fractal.type == 'j')
		calculate_julia(data, fractal);
}
void image_put_pixel(t_img_data *image, int x, int y, int color)
{
	int offset;
	char *pixel_address;

	/* if (x > WIDTH || y > HEIGHT)
	{
		x = x & WIDTH;
		y = y % HEIGHT;
	} */
	offset = (y * image->line_len + x * (image->bits_per_pixel / 8));
	pixel_address = (image->image_address) + offset;
	*(unsigned int *)pixel_address = color;
}
