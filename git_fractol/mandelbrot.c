/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:21:27 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/20 15:28:48 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int mandelbrot_set(double complex c, int max_iterations)
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
        y = (x + x) * y + y0;
        x = x2 - y2 + x0;
        x2 = x * x;
        y2 = y * y;
        iteration++;
    }
    return (iteration % 100);
}

void calculate_mandelbrot(t_data data, t_fractal fractal)
{
    float mandelbrot_value;
    int x_axis;
    int y_axis;
    double real;
    double imag;
    
    y_axis = 0;
    while (y_axis <= HEIGHT)
    {
        x_axis = 0;
        while (x_axis <= WIDTH)
        {
            real = fractal.x_start + (double)x_axis / WIDTH * fractal.scale;
            imag = fractal.y_start + (double)y_axis / HEIGHT * fractal.scale;
            mandelbrot_value = mandelbrot_set(real + imag * I, 100);
            image_put_pixel(data.image, x_axis, y_axis, linear_interpolation(data.fractal.starting_color, mandelbrot_value/100));
            x_axis++;
        }
        y_axis++;
    }
}
