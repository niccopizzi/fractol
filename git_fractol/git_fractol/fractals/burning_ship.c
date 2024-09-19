/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:08:45 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/19 14:08:27 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int burning_ship_set(double complex c, int max_iterations)
{
    double x0;
    double y0;
    double x;
    double y;
    double x2;
    double y2;
    int iteration;

    iteration = 0;
    x = 0.0;
    y = 0.0;
    y0 = cimag(c);
    x0 = creal(c);
    x2 = 0.0;
    y2 = 0.0;
    while ((x2 + y2) <= 4)
    {
        y = fabs((x + x) * y + y0);
        x = fabs(x2 - y2 + x0);
        x2 = x * x;
        y2 = y * y;
        if (iteration++ >= max_iterations || (x2 + y2 == 0.0))
            return (-1);
    }
    return (iteration % 55);
}

void calculate_burning_ship(t_ptrs data, t_fractal fractal)
{
    int julia_value;
    // int color_palette[16] = {0x000000, 0x400000, 0x7F0000, 0xBF0000, 0xFF0000, 0xFF3300, 0xFF6600, 0xFF9900, 0xFFFF00, 0xDFFF00, 0xBFFF00, 0x80FF00, 0x00FF00, 0x008000, 0x400000, 0x1A0000};
    int color_palette[] = {
        0x000000, 0x1A0000, 0x330000, 0x4C0000, 0x660000,
        0x7F0000, 0x930000, 0xA70000, 0xBF0000, 0xD70000,
        0xEF0000, 0xFF0000, 0xFF1900, 0xFF3300, 0xFF4C00,
        0xFF6600, 0xFF7F00, 0xFF9900, 0xFFB200, 0xFFCC00,
        0xFFE500, 0xFFFF00, 0xF2FF00, 0xE5FF00, 0xDFFF00,
        0xCFFF00, 0xBFFF00, 0xB2FF00, 0xA5FF00, 0x80FF00,
        0x70FF00, 0x60FF00, 0x50FF00, 0x40FF00, 0x30FF00,
        0x00FF00, 0x00E500, 0x00CC00, 0x00B200, 0x008000,
        0x007000, 0x006000, 0x005000, 0x004000, 0x003000,
        0x400000, 0x330000, 0x260000, 0x1A0000, 0x130000,
        0x0C0000, 0x060000, 0x400000, 0x1A0000};
    double complex c;
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
            real = fractal.x_start + (float)x_axis / WIDTH * fractal.scale;
            imag = fractal.y_start + (float)y_axis / HEIGHT * fractal.scale;
            c = real + imag * I;
            julia_value = burning_ship_set(c, 55);
            if (julia_value == -1)
                image_put_pixel(data.image, x_axis, y_axis, 0x000000);
            else
                image_put_pixel(data.image, x_axis, y_axis, (color_palette[julia_value]));
            x_axis++;
        }
        y_axis++;
    }
    mlx_put_image_to_window(data.mlx_ptr, data.window_ptr, data.image->image, 0, 0);
}