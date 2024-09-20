/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:26:11 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/20 15:31:33 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void calculate_fractal(t_data data, t_fractal fractal)
{
	
	if (fractal.type == 'M' || fractal.type == 'm')
		calculate_mandelbrot(data, fractal);
	if (fractal.type == 'J' || fractal.type == 'j')
		calculate_julia(data, fractal);
	if (fractal.type == 'B' || fractal.type == 'b')
		calculate_burning_ship(data, fractal);
	mlx_put_image_to_window(data.mlx_ptr, data.window_ptr, data.image->image, 0, 0);
}

void set_hooks(t_data data)
{
	calculate_fractal(data, data.fractal);
	mlx_hook(data.window_ptr, 17, 0, exit_hook, &data);
	mlx_key_hook(data.window_ptr, keys_hook, &data);
	mlx_mouse_hook(data.window_ptr, mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
}

void initialize_data_struct(char type, double complex c)
{
	t_data data;
	t_img_data image;
	t_fractal fractal;
	
	data.mlx_ptr = mlx_init();
	if (NULL == data.mlx_ptr)
		print_error_and_exit(&data, INIT_ERROR);
	data.window_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	if (NULL == data.window_ptr)
		print_error_and_exit(&data, WINDOW_ERROR);
	image.image = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	if (NULL == image.image)
		print_error_and_exit(&data, IMAGE_ERROR);
	image.image_address = mlx_get_data_addr(image.image, &image.bits_per_pixel, &image.line_len, &image.endianess);
	fractal.c = c;
	fractal.scale = 4.0;
	fractal.x_start = -2.0;
	fractal.y_start = -2.0;
	fractal.starting_color = 0x2C1014;
	fractal.type = type;
	data.image = &image;
	data.fractal = fractal;
	set_hooks(data);
}

int main(int argc, char *argv[])
{
	int type;

	if (argc < 2)
		print_error_and_exit(NULL, "Ooops.. it seems you forgot to give me the fractal to render!\n");
	type = is_fractal_valid(argv[1]);
	if (type == FALSE)
		print_error_and_exit(NULL, "Noooo you typed a fractal I don't know!\n");
	if ((type == 'J' || type == 'j'))
	{
		if (argc < 3 || is_complex_valid(argv[2]) == FALSE)
			initialize_data_struct(type, 0);
		else
			initialize_data_struct(type, ft_atoc(argv[2]));
	}
	else
		initialize_data_struct(type, 0);
	return (0);
}
