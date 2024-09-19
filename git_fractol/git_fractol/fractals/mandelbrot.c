/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:21:27 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/19 14:08:20 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int mandelbrot_set(double complex c, int max_loops)
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
        y = (x + x) * y + y0;
        x = x2 - y2 + x0;
        x2 = x * x;
        y2 = y * y;
        if (iteration++ >= max_loops || (x2 + y2 == 0.0))
            return (-1);
    }
    return (iteration % 55);
}

void calculate_mandelbrot(t_ptrs data, t_fractal fractal)
{
    int mandelbrot_value;
    double complex c;
    int x_axis;
    int y_axis;
    int color_palette[] = {
        0x2C1014, 0x251016, 0x1F1118, 0x191119, 0x140F1A, 0x100D26, 0x0D0A2D, 0x0A0733, 0x07053A, 0x040249, 0x020352,
        0x01055C, 0x000766, 0x06227E, 0x0C2C8A, 0x11388C, 0x18459C, 0x1F52B1, 0x2A60B7, 0x3468BB, 0x397DD1, 0x4E8BD8,
        0x6398DF, 0x79A6E5, 0x8FB3EB, 0xA6C1F1, 0xBCD0F7, 0xD3ECF8, 0xDEE2E5, 0xE8E6D2, 0xF1E9BF, 0xF4DF99, 0xF6D57A,
        0xF8C95F, 0xFAA741, 0xFC8523, 0xFF6200, 0xFF8500, 0xFF9300, 0xFFA100, 0xFFAA00, 0xDA9000, 0xCC8000, 0xB57100,
        0xA05F01, 0x995700, 0x8A4D03, 0x7C4302, 0x703B03, 0x653403, 0x5C2C05, 0x532506, 0x4A1F07, 0x42200F, 0x3B1B10};
    y_axis = 0;
    while (y_axis <= HEIGHT)
    {
        x_axis = 0;
        while (x_axis <= WIDTH)
        {
            c = fractal.x_start + (float)x_axis / WIDTH * fractal.scale + (fractal.y_start + (float)y_axis / HEIGHT * fractal.scale) * I;
            mandelbrot_value = mandelbrot_set(c, 55);
            if (mandelbrot_value == -1)
                image_put_pixel(data.image, x_axis, y_axis, 0x000000);
            else
                image_put_pixel(data.image, x_axis, y_axis, color_palette[mandelbrot_value]);

            x_axis++;
        }
        y_axis++;
    }
}
