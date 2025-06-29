#include "fractol.h"

int	mandelbrot(double c_real, double c_imaginary)
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
		if ((z_real * z_real+ z_imaginary * z_imaginary) > 4.0)
			break ;
		tmp = 2 * z_real * z_imaginary + c_imaginary;
		z_real = z_real * z_real - z_imaginary * z_imaginary + c_real;
		z_imaginary = tmp;
		n++;
	}
	return (n);
}