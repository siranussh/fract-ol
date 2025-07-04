/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihakoby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:25:46 by sihakoby          #+#    #+#             */
/*   Updated: 2025/07/04 18:28:42 by sihakoby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_data *fract, double zoom)
{
	double	center_real;
	double	center_imaginary;

	center_real = fract->min_real - fract->max_real;
	center_imaginary = fract->max_imaginary - fract->min_imaginary;
	fract->max_real = fract->max_real + (center_real - zoom * center_real)
		/ 2;
	fract->min_real = fract->max_real + zoom * center_real;
	fract->min_imaginary = fract->min_imaginary + (center_imaginary - zoom
			* center_imaginary) / 2;
	fract->max_imaginary = fract->min_imaginary + zoom * center_imaginary;
}

static void	move(t_data *fract, double distance, char direction)
{
	double	center_real;
	double	center_imaginary;

	center_real = fract->max_real - fract->min_real ;
	center_imaginary = fract->max_imaginary - fract->min_imaginary;
	if (direction == 'R')
	{
		fract->min_real += center_real * distance;
		fract->max_real += center_real * distance;
	}
	else if (direction == 'L')
	{
		fract->min_real -= center_real * distance;
		fract->max_real -= center_real * distance;
	}
	else if (direction == 'D')
	{
		fract->min_imaginary -= center_imaginary * distance;
		fract->max_imaginary -= center_imaginary * distance;
	}
	else if (direction == 'U')
	{
		fract->min_imaginary += center_imaginary * distance;
		fract->max_imaginary += center_imaginary * distance;
	}
}

static int	key_switch_set(int keycode, t_data *mlx)
{
	if (keycode == KEY_ONE && mlx->set != MANDELBROT)
		mlx->set = MANDELBROT;
	else if (keycode == KEY_TWO && mlx->set != JULIA)
		mlx->set = JULIA;
	else if (keycode == KEY_THREE && mlx->set != BURNING_SHIP)
		mlx->set = BURNING_SHIP;
	else
		return (1);
	layout(mlx);
	draw_fractal(mlx);
	return (0);
}

int	key_event(int keycode, t_data *mlx)
{
	if (keycode == KEY_ESC)
	{
		close_program(mlx);
		return (0);
	}
	else if (keycode == KEY_PLUS)
		zoom(mlx, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(mlx, 2);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(mlx, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(mlx, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(mlx, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(mlx, 0.2, 'R');
	else if (keycode == KEY_SPACE)
		color_shift(mlx);
	else if (!key_switch_set(keycode, mlx))
		return (1);
	else
		return (1);
	draw_fractal(mlx);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_data *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 2);
	else if (keycode == MOUSE_BTN)
	{
		if (mlx->set == JULIA)
			update_julia(x, y, mlx);
	}
	else
		return (0);
	draw_fractal(mlx);
	return (0);
}
