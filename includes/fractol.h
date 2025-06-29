#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 60

# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32
# define KEY_ONE 49
# define KEY_TWO 50
# define KEY_THREE 51
# define KEY_FOUR 52
# define KEY_FIVE 53
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_BTN 3
# define MOUSE_BTN 1
# define MOUSE_BTN_2 3
# define KEY_K 107

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	double	min_real;
	double	max_real;
	double	min_imaginary;
	double	max_imaginary;
	double	k_real;
	double	k_imaginary;
	double	sx;
	double	rx;
	double	fx;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_data;

int		mandelbrot(double c_real, double c_imaginary);
int		julia(t_data *fract, double z_real, double z_imaginary);
int		burning_ship(double c_real, double c_imaginary);
void	draw_fractal(t_data *fract);
int		update_julia(int x, int y, t_data *fract);
void	color_shift(t_data *fract);
void	set_color_mono(t_data *fract, int color);
void	set_color_multiple(t_data *fract, int colors[4], int n);
void	set_color_zebra(t_data *fract, int color);
void	set_color_triad(t_data *fract, int color);
void	set_color_tetra(t_data *fract, int color);
void	set_color_opposites(t_data *fract, int color);
void	set_color_contrasted(t_data *fract, int color);
void	set_color_graphic(t_data *fract, int color);
int		get_percent_color(int color, double percent);
int		key_event(int keycode, t_data *mlx);
int		mouse_event(int keycode, int x, int y, t_data *mlx);
void	start_init(t_data *fract);
void	redraw_img(t_data *fract);
void	init(t_data *fract);
void	layout(t_data *fract);
void	get_color(t_data *fract, int ac, char **av);
double	ft_atof(char *str);
int		close_program(t_data *mlx);
void	safe_exit_free(int exit_code, t_data *fract);
int		error_msg(char *str1, char *str2, int errno);
void	help_msg(t_data *fract);
void	print_controls(void);
int     ft_isspace(int c);
int     ft_ishexdigit(int c);

#endif