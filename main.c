#include "fdf.h"

static int key_hook(int key, t_fdf *fdf)
{
	if(key == 65307 || key == 113) // ESC ou Q
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		free(fdf);
		exit(0);
	}
	else
		ft_printf("tecla:%i\n", key);
	return(0);
}

int main(int argc, char *argv[])
{
	t_fdf *fdf;

	if(argc < 2 || argv == NULL)
		return(0);
	fdf = malloc(sizeof * (fdf));
	if(fdf == NULL)
		return(0);
	fdf->mlx = mlx_init();
	if(fdf->mlx == NULL)
	{
		free(fdf);
		return(0);
	}
	fdf->win = mlx_new_window(fdf->mlx, 600, 600, "Fdf");
	if(fdf->win)
		{
			free(fdf->mlx);
			free(fdf);
			return(0);
		}
	mlx_key_hook(fdf->win, &key_hook, fdf);
	mlx_loop(fdf->mlx);
	return(0);
}

/*
	x = 200;
	y = 200;
	while(x++ < 400 && y++ < 400)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x,200,225);
		mlx_pixel_put(fdf->mlx, fdf->win,x,400,225);
		mlx_pixel_put(fdf->mlx, fdf->win, 200,y,225);
		mlx_pixel_put(fdf->mlx, fdf->win,400,y,225);
	}
	mlx_string_put(fdf->mlx, fdf->win, 250,300, 0x00FF00, "suco ");
	mlx_string_put(fdf->mlx, fdf->win, 280,300, 0xFF00FF, "addes ");
	mlx_string_put(fdf->mlx, fdf->win, 316,300, 0xFF4500, "de maca");
*/
