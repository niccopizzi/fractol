/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:08:45 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/20 15:10:30 by npizzi           ###   ########.fr       */
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
    while ((x2 + y2) <= 4 && iteration < max_iterations)
    {
        y = fabs((x + x) * y + y0);
        x = fabs(x2 - y2 + x0);
        x2 = x * x;
        y2 = y * y;
        iteration++;
    }
    return (iteration % 100);
}

void calculate_burning_ship(t_data data, t_fractal fractal)
{
    float burning_value;
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
            real = fractal.x_start + (double)x_axis / WIDTH * fractal.scale;
            imag = fractal.y_start + (double)y_axis / HEIGHT * fractal.scale;
            burning_value = burning_ship_set(real + imag * I, 100);
            image_put_pixel(data.image, x_axis, y_axis, linear_interpolation(data.fractal.starting_color, burning_value/100));
            x_axis++;
        }
        y_axis++;
    }
    mlx_put_image_to_window(data.mlx_ptr, data.window_ptr, data.image->image, 0, 0);
}
