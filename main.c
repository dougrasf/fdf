#include "fdf.h"

static int validations(int argc, char **argv)
{
	int fd;
	char *buff;
	int len;

	buff = (char *)malloc(2 + 1);
	fd = open(argv[1], O_RDONLY);
	len = ft_strlen(argv[1]);
	if(argc != 2 || len == NULL)
	{
		ret = ft_printf("Arguments Error\n");
		return(1);
	}
	else if(ft_strnstr(argv[1], ".fdf", len) != NULL)
	{
		ret = ft_printf("File extension Error\n");
		return(1);
	}
	else if(read(fd, buff, 2) == 0)
	{
		ret = ft_printf("Map Error\n");
		return(1);
	}
	free(buff);
	return(0)
}

void init_mlx(t_fdf *fdf, char **argv)
{
	
}

int main(int argc, char *argv[])
{
	t_fdf *fdf;
	int len;

	if(validations(argc,argv) == 1)
		return(1);
	init_mlx(fdf, argv[1]);
	return(0);
}

/*

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

	x = 200;
	y = 200;

	if(argc != 2)
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
	mlx_key_hook(fdf->win, &key_hook, fdf);
	mlx_loop(fdf->mlx);
	
*/
