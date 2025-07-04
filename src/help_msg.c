/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihakoby <sihakoby@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:40:35 by sihakoby          #+#    #+#             */
/*   Updated: 2025/07/04 20:08:21 by sihakoby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_fractal_options(void)
{
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tB - Burning Ship", 1);
	ft_putendl_fd("./fractol <type>", 1);
	ft_putendl_fd("\tJ - Julia", 1);
	ft_putendl_fd("./fractol <type> 0.285 0.01", 1);
}

void	print_color_options(void)
{
	ft_putendl_fd("The hex color code must be formatted as RRGGBB:", 1);
	ft_putendl_fd("./fractol <type> <color>", 1);
	ft_putendl_fd("./fractol M 0066FF\e[0m", 1);
	ft_putendl_fd("./fractol J 0.285 0.01 CC6600\e[0m", 1);
}

void	help_msg(t_data *fract)
{
	ft_putendl_fd("Fract'ol Usage and Controls", 1);
	print_fractal_options();
	print_color_options();
	exit_free(EXIT_FAILURE, fract);
}
