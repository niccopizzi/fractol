/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:54:00 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/19 12:06:59 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_all(t_ptrs *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image->image);
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int exit_hook(t_ptrs *data)
{
	close_all(data);
	exit(EXIT_SUCCESS);
}

int mouse_hookup(int button, int x, int y, t_ptrs *data)
{
	float scale_change;

	if (button == 4)
	{
		scale_change = data->fractal.scale * 0.8 - data->fractal.scale;
		data->fractal.scale *= 0.8;
		data->fractal.x_start -= ((float)x / WIDTH) * scale_change;
		data->fractal.y_start -= ((float)y / HEIGHT) * scale_change;
		calculate_fractal(*data, data->fractal);
	}

	if (button == 5)
	{
		scale_change = data->fractal.scale * 1.2 - data->fractal.scale;
		data->fractal.scale *= 1.2;
		data->fractal.x_start -= ((float)x / WIDTH) * scale_change;
		data->fractal.y_start -= ((float)y / HEIGHT) * scale_change;
		calculate_fractal(*data, data->fractal);
	}
	return (0);
}
int keys_hookup(int key, t_ptrs *data)
{
	if (key == XK_Escape)
	{
		close_all(data);
		return (EXIT_SUCCESS);
	}
	if (key == XK_Left)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c -= 0.01;
		else
			data->fractal.x_start -= 0.05 * (4.0 * data->fractal.scale);
		calculate_fractal(*data, data->fractal);
	}
	if (key == XK_Right)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c += 0.01;
		else
			data->fractal.x_start += 0.05 * (4.0 * data->fractal.scale);
		calculate_fractal(*data, data->fractal);
	}
	if (key == XK_Down)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c -= 0.01 * I;
		else
			data->fractal.y_start += 0.05 * (4.0 * data->fractal.scale);
		calculate_fractal(*data, data->fractal);
	}
	if (key == XK_Up)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c += 0.01 * I;
		else
			data->fractal.y_start -= 0.05 * (4.0 * data->fractal.scale);
		calculate_fractal(*data, data->fractal);
	} 
	if (key == XK_plus || key == 65451)
	{
		data->fractal.shade += 1;
		calculate_fractal(*data, data->fractal);
	}
	return (0);
}
