/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:50:20 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/20 14:44:08 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void close_all(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image->image);
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void print_error_and_exit(t_data *data, char *str)
{
    if (data != NULL)
    {
        if (data->image->image != NULL)
            mlx_destroy_image(data->mlx_ptr, data->image->image);
        if (data->window_ptr != NULL)
            mlx_destroy_window(data->mlx_ptr, data->window_ptr);
        if (data->mlx_ptr != NULL)
            mlx_destroy_display(data->mlx_ptr);
        printf(MODE_BOLD ANSI_COLOR_RED "%s" ANSI_MODE_RESET, str);
        exit(EXIT_FAILURE);
    }
    printf("%s", str);
    printf("These are the fractals you can choose:\n");
    printf("-> " MODE_BOLD ANSI_COLOR_BLUE "Mandelbrot\n"ANSI_MODE_RESET);
    printf("-> " MODE_BOLD ANSI_COLOR_GREEN "Julia\n" ANSI_MODE_RESET);
    printf("-> " MODE_BOLD ANSI_COLOR_RED "Burning Ship\n" ANSI_MODE_RESET);
    exit(EXIT_FAILURE);
}
