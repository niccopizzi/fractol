/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:07:25 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/19 12:24:11 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void calculate_fractal(t_ptrs data, t_fractal fractal)
{
	if (fractal.type == 'M' || fractal.type == 'm')
		calculate_mandelbrot(data, fractal);
	if (fractal.type == 'J' || fractal.type == 'j')
		calculate_julia(data, fractal);
	if( fractal.type == 'B' || fractal.type == 'b')
		calculate_burning_ship(data, fractal);
	 mlx_put_image_to_window(data.mlx_ptr, data.window_ptr, data.image->image, 0, 0);
}
void image_put_pixel(t_img_data *image, int x, int y, int color)
{
	int offset;
	char *pixel_address;
	
	offset = (y * image->line_len + x * (image->bits_per_pixel / 8));
	pixel_address = (image->image_address) + offset;
	*(unsigned int *)pixel_address = color;
}

int is_complex_valid(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (FALSE);
	while (str[i] != 0)
	{
		if (ft_isspace(str[i]) == FALSE && (str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-' && (str[i] == 'i' && str[i + 1] != 0))
			return (FALSE);
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == str[i + 1])
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
int enconde_in_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}