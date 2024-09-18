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
			data->fractal.c -= 0.05;
		else
			data->fractal.x_start -= 0.1;
		calculate_fractal(*data, data->fractal);
	}
	if (key == XK_Right)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c += 0.05;
		else
			data->fractal.x_start += 0.1;
		calculate_fractal(*data, data->fractal);
	}
	if (key == XK_Down)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c -= 0.05 * I;
		else
			data->fractal.y_start -= 0.1;
		calculate_fractal(*data, data->fractal);
	}
	if (key == XK_Up)
	{
		if (data->fractal.type == 'J' || data->fractal.type == 'j')
			data->fractal.c += 0.05 * I;
		else
			data->fractal.y_start += 0.1;
		calculate_fractal(*data, data->fractal);
	}
	return (0);
}