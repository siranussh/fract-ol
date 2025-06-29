#include "fractol.h"

int	update_julia(int x, int y, t_data *fract)
{
	fract->k_real = fract->min_real + (double)x * (fract->max_real - fract->min_real) / WIDTH;
	fract->k_imaginary = fract->max_imaginary + (double)y * (fract->min_imaginary - fract->max_imaginary) / HEIGHT;
	draw_fractal(fract);
	return (0);
}

int	julia(t_data *fract, double z_real, double z_imaginary)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((z_imaginary * z_imaginary + z_real * z_real) > 4.0)
			break ;
		tmp = 2 * z_real * z_imaginary + fract->k_imaginary;
		z_real = z_real * z_real- z_imaginary * z_imaginary + fract->k_real;
		z_imaginary = tmp;
		n++;
	}
	return (n);
}