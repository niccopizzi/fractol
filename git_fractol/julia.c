/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:08:45 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/20 15:10:49 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int julia_set(double complex z, double complex c, int max_iterations)
{
    int iteration;

    iteration = 0;
    while (cabs(z) <= 2 && iteration < max_iterations)
    {
        z = z * z + c;
        iteration++;
    }
    return (iteration % 100);
}

void calculate_julia(t_data data, t_fractal fractal)
{
    float julia_value;
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
            julia_value = julia_set(real + imag * I, fractal.c, 100);
            image_put_pixel(data.image, x_axis, y_axis, linear_interpolation(data.fractal.starting_color, julia_value/100));
            x_axis++;
        }
        y_axis++;
    }
    mlx_put_image_to_window(data.mlx_ptr, data.window_ptr, data.image->image, 0, 0);
}
