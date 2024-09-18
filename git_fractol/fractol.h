/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:01:47 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/18 12:21:37 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
#define _FRACTOL_H

#include "./minilibx-linux/mlx.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/keysym.h>

#define WIDTH 1200
#define HEIGHT 1080

#define X_START_VALUE -2.0
#define Y_START_VALUE -2.0

typedef struct fractal
{
    double x_start;
    double y_start;
    double range;
    double complex c;
    char type;

} t_fractal;

typedef struct img_data
{
    void *image;
    char *image_address;
    int bits_per_pixel;
    int line_len;
    int endianess;
} t_img_data;

typedef struct mlx_ptrs
{
    void *mlx_ptr;
    void *window_ptr;
    t_img_data *image;
    t_fractal fractal;
} t_ptrs;


int keys_hookup(int key, t_ptrs *data);
int enconde_in_rgb(int r, int g, int b);
int mandelbrot_set(double complex z, double complex c, int calls, int max_loops);
void calculate_fractal(t_ptrs data, t_fractal fractal);
void calculate_mandelbrot(t_ptrs data, t_fractal fractal);
void calculate_julia(t_ptrs data, t_fractal fractal);
void image_put_pixel(t_img_data *image, int x, int y, int color);
double complex ft_atoc(char *str);
int is_complex_valid(char *str);
int exit_hook(t_ptrs *data);
#endif