/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palletes_managing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihakoby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:58:20 by sihakoby          #+#    #+#             */
/*   Updated: 2025/07/04 19:58:32 by sihakoby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_shift_special(t_data *fract)
{
	int	alt_color;

	if (fract->color == 0xFFFFFF)
		alt_color = 0xCCCCCC;
	else
		alt_color = fract->color;
	if (fract->color_pattern == 5)
		set_color_contrasted(fract, alt_color);
	else if (fract->color_pattern == 6)
		set_color_opposites(fract, fract->color);
	else if (fract->color_pattern == 7)
		set_color_graphic(fract, fract->color);
	else if (fract->color_pattern == 8)
		set_color_multiple(fract, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

static void	color_shift_striped(t_data *fract)
{
	if (fract->color_pattern == 2)
		set_color_zebra(fract, fract->color);
	else if (fract->color_pattern == 3)
		set_color_triad(fract, fract->color);
	else if (fract->color_pattern == 4)
		set_color_tetra(fract, fract->color);
	else
		color_shift_special(fract);
}

void	color_shift(t_data *fract)
{
	int	alt_color;

	fract->color_pattern = (fract->color_pattern + 1) % 9;
	redraw_img(fract);
	if (fract->color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = fract->color;
	if (fract->color_pattern == 0)
		set_color_mono(fract, alt_color);
	else if (fract->color_pattern == 1)
		set_color_multiple(fract, (int [4]){0x000000, alt_color,
			get_percent_color(fract->color, 50), 0xFFFFFF}, 4);
	else
		color_shift_striped(fract);
}
