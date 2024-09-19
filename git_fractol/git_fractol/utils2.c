/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:07:25 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/18 08:30:03 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int is_complex_valid(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (FALSE);
	while (str[i] != 0)
	{
		if (ft_isspace(str[i]) == FALSE && (str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-' && (str[i] == 'i' && str[i + 1] != 0))
			return (FALSE);
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == str[i + 1])
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
int enconde_in_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void color_window(void *mlx_ptr, void *win_ptr, t_img_data *image, int color)
{
	for (int i = 0; i <= WIDTH; i++)
	{
		for (int x = 0; x <= HEIGHT; x++)
			image_put_pixel(image, i, x, color);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, image->image, 0, 0);
}