/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihakoby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:22:10 by sihakoby          #+#    #+#             */
/*   Updated: 2025/07/04 18:25:13 by sihakoby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(double c_real, double c_imaginary)
{
	int		n;
	double	z_real;
	double	z_imaginary;
	double	tmp;

	z_real = 0;
	z_imaginary = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((z_real * z_real + z_imaginary * z_imaginary) > 4.0)
			break ;
		z_real = fabs(z_real);
		z_imaginary = fabs(z_imaginary);
		tmp = 2 * z_real * z_imaginary + c_imaginary;
		z_real = z_real * z_real - z_imaginary * z_imaginary + c_real;
		z_imaginary = tmp;
		n++;
	}
	return (n);
}
