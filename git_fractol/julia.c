/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:08:45 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/18 12:24:00 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_set(double complex z, double complex c, int calls, int max_iterations)
{

    if (cabs(z) > ((1 + sqrt(1 + 4 * cabs(c)) / 2)))
        return (calls % 16);
    calls++;
    if (calls >= max_iterations)
        return (-1);
    return (julia_set(cpow(z, 2) + c, c, calls, max_iterations));
}

void calculate_julia(t_ptrs data, t_fractal fractal)
{
    int julia_value;
    int color_palette[16] = {0x42200F, 0x19071A, 0x09012F, 0x040449, 0x000764, 0x0C2C8A, 0x1852B1, 0x397DD1, 0x86B5E5, 0xD3ECF8, 0xF1E9BF, 0xF8C95F, 0xFFAA00, 0xCC8000, 0x995700, 0x6A3403};
    int color_palette2[10] = {0x007F5F, 0x2B9348, 0x55A630, 0x80B918, 0xAACC00, 0xBFD200, 0xD4D700, 0xDDDF00, 0xEEEF20, 0xFFFF3F};
    double complex z;
    double real;
    double imag;
    int x_axis;
    int y_axis;

    y_axis = 0;
    while (y_axis <= HEIGHT)
    {
        x_axis = 0;
        while (x_axis <= WIDTH)
        {
            real = fractal.x_start + (float)x_axis/WIDTH* 4.0;
            imag = fractal.y_start + (float)y_axis/HEIGHT* 4.0;
            z = real +  imag * I;
            julia_value = julia_set(z, fractal.c, 0, 50);
            if (julia_value == -1)
                image_put_pixel(data.image, x_axis, y_axis, 0x000000);
            else
                image_put_pixel(data.image, x_axis, y_axis, color_palette[julia_value]);
            x_axis++;
        }
        y_axis++;
    }
    mlx_put_image_to_window(data.mlx_ptr, data.window_ptr, data.image->image, 0, 0);
}