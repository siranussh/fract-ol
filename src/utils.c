#include "fractol.h"

void	safe_exit_free(int exit_code, t_data *fract)
{
	if (!fract)
		exit(exit_code);
	if (fract->palette)
		free(fract->palette);
	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	if (fract->win && fract->mlx)
		mlx_destroy_window(fract->mlx, fract->win);
	if (fract->mlx)
	{
		mlx_loop_end(fract->mlx);
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
	}
	exit(exit_code);
}

int	error_msg(char *str1, char *str2, int errno)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	return (errno);
}

int	close_program(t_data *mlx)
{
	safe_exit_free(0, mlx);
	return (0);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (c);
	return (0);
}

int	ft_ishexdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	c = ft_toupper(c);
	if (c >= 'A' && c <= 'F')
		return (c);
	else
		return (0);
}