/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:01:47 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/20 14:44:13 by npizzi           ###   ########.fr       */
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

#define WIDTH 800
#define HEIGHT 600

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_MODE_RESET "\x1b[0m"

#define MODE_BOLD "\x1b[1m"
#define MODE_DIM "\x1b[2m"
#define MODE_ITALIC "\x1b[3m"
#define MODE_UNDERLINE "\x1b[4m"
#define MODE_BLINKING "\x1b[5m"
#define MODE_REVERSE "\x1b[7m"
#define MODE_STRIKETHROUGH "\x1b[9m"

#define INIT_ERROR "... There was a DISASTER! It was not possible to estasblish a connection with the X Server\n"
#define WINDOW_ERROR "... RUN, EVERYTHING IS BURNING! ... Just kidding, but there was an error in creating the window\n"
#define IMAGE_ERROR "... TRUE HORRROR! It seems that there was an error in creating the image\n"

typedef struct fractal
{
    double x_start;
    double y_start;
    double scale;
    double complex c;
    int starting_color;
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
} t_data;

int exit_hook(t_data *data);
int keys_hook(int key, t_data *data);
int mouse_hook(int button, int x, int y, t_data *data);
int is_complex_valid(char *str);
int is_fractal_valid(char *fractal);
int linear_interpolation(int color_one, float gradient);
void calculate_fractal(t_data data, t_fractal fractal);
void calculate_burning_ship(t_data data, t_fractal fractal);
void calculate_mandelbrot(t_data data, t_fractal fractal);
void calculate_julia(t_data data, t_fractal fractal);
void close_all(t_data *data);
void image_put_pixel(t_img_data *image, int x, int y, int color);
void print_error_and_exit(t_data *data, char *str);
#endif