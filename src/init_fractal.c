#include "fractol.h"

void	start_init(t_data *fract)
{
	fract->mlx = NULL;
	fract->win = NULL;
	fract->img = NULL;
	fract->buf = NULL;
	fract->set = -1;
	fract->min_real = 0;
	fract->max_real = 0;
	fract->min_imaginary = 0;
	fract->max_imaginary = 0;
	fract->k_real = 0;
	fract->k_imaginary = 0;
	fract->sx = 0;
	fract->rx = 0;
	fract->fx = 0;
	fract->palette = NULL;
	fract->color_pattern = -1;
	fract->color = 0;
}

void    layout(t_data *fract)
{
	if (fract->set == JULIA)
	{
		fract->min_real = -2.0;
		fract->max_real = 2.0;
		fract->min_imaginary = -2.0;
		fract->max_imaginary = fract->min_imaginary + (fract->max_real - fract->min_real) * HEIGHT / WIDTH;
	}
	else
	{
		fract->min_real = -2.0;
		fract->max_real = 1.0;
		fract->max_imaginary = -1.5;
		fract->min_imaginary = fract->max_imaginary + (fract->max_real - fract->min_real) * HEIGHT / WIDTH;
	}
}

static void	draw_img(t_data *fract)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	fract->palette = ft_calloc((MAX_ITERATIONS + 1), sizeof(int));
	if (!(fract->palette))
		safe_exit_free(error_msg("error initializing color scheme.", "", 1), fract);
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!(fract->img))
		safe_exit_free(error_msg("image creation error.", "", 1), fract);
	buf = mlx_get_data_addr(fract->img, &pixel_bits, &line_bytes, &endian);
	fract->buf = buf;
}

void	redraw_img(t_data *fract)
{
	if (fract->mlx && fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	if (fract->palette)
		free(fract->palette);
	if (fract->buf)
		fract->buf = NULL;
	draw_img(fract);
}

void	init(t_data *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		clean_exit(msg("MLX: error connecting to mlx.", "", 1), fract);
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "Fractol");
	if (!fract->win)
		clean_exit(msg("MLX: error creating window.", "", 1), fract);
	fract->sx = 2.0;
	fract->rx = 0.5;
	fract->fx = 1.0;
	layout(fract);
	color_shift(fract);
}