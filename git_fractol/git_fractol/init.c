/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:26:11 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/19 12:28:13 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void start_all(t_ptrs data)
{
	calculate_fractal(data, data.fractal);
	mlx_key_hook(data.window_ptr, keys_hookup, &data);
	mlx_hook(data.window_ptr, 17, 0, exit_hook, &data);
	mlx_mouse_hook(data.window_ptr, mouse_hookup, &data);
	mlx_loop(data.mlx_ptr);
}

void *initialize_variables(char type, double complex c)
{
	t_ptrs data;
	t_img_data image;
	t_fractal fractal;

	data.mlx_ptr = mlx_init();
	if (NULL == data.mlx_ptr)
		return (NULL);
	data.window_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	if (NULL == data.window_ptr)
		return (NULL);
	image.image = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	if (NULL == image.image)
		return (NULL);
	data.image = &image;
	data.image->image_address = mlx_get_data_addr(data.image->image, &data.image->bits_per_pixel, &data.image->line_len, &data.image->endianess);
	fractal.c = c;
	fractal.scale = 4.0;
	fractal.x_start = -2.0;
	fractal.y_start = -2.0;
	fractal.type = type;
	fractal.shade = 0;
	data.fractal = fractal;
	start_all(data);
	return (NULL);
}

int is_fractal_valid(char *fractal, int arguments)
{
	char *possible_fractals[] = {"Mandelbrot", "mandelbrot", "Julia", "julia", "Burning ship", "burning ship", "burning"};
	int i;

	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(fractal, possible_fractals[i]) == 0)
		{
			if (i >= 3 && arguments < 3)
				return (FALSE);
			return (possible_fractals[i][0]);
		}
		i++;
	}
	return (FALSE);
}

int main(int argc, char *argv[])
{
	int type;

	if (argc < 2)
	{
		printf("Please insert only one of the following fractals\n-> Mandelbrot\n-> Julia\n-> Burning Ship\nFor Julia set insert a value of c as well\n");
		exit(EXIT_FAILURE);
	}
	type = is_fractal_valid(argv[1], argc);
	if (type == FALSE)
	{
		printf("Please insert a valid type of fractal\nThe available types are:\n-> Mandelbrot\n-> Julia\n-> Burning Ship\n");
		printf("For Julia set remember to insert a valid value of c\n");
		exit(EXIT_FAILURE);
	}
	if ((type == 'J' || type == 'j'))
	{
		if (is_complex_valid(argv[2]) == FALSE)
		{
			printf("Please insert a valid C parameter : a+bi\n");
			exit(EXIT_FAILURE);
		}
		initialize_variables(type, ft_atoc(argv[2]));
	}
	else
		initialize_variables(type, 0);
	return (0);
}
