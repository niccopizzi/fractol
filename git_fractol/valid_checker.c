/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:50:18 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/20 09:23:45 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int is_fractal_valid(char *fractal)
{
    char *possible_fractals[] = {"Mandelbrot", "mandelbrot", "Julia", "julia", "Burning ship", "burning ship"};
    int i;

    i = 0;
    while (i < 6)
    {
        if (ft_strncmp(fractal, possible_fractals[i], 13) == 0)
            return (possible_fractals[i][0]);
        i++;
    }
    return (FALSE);
}

int is_complex_valid(char *str)
{
    int i;

    i = 0;
    while (str[i] != 0)
    {
        if (str[i] == 'i' && str[i + 1] == 0)
            return(TRUE);
        if (ft_isspace(str[i]) == FALSE && (ft_isdigit(str[i]) == FALSE) && str[i] != '+' && str[i] != '-')
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