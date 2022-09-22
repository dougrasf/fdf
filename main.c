#include "fdf.h"

void print_mtx(char **mtx) //func de teste //tirar dps
{
    int i = 0;
    while (mtx[i])
        ft_printf("%s\n", mtx[i++]);
}

static int validations(int argc, char **argv)
{
	int len;

	len = ft_strlen(argv[1]);
	if(argc != 2 || len == 0)
	{
		ft_printf("Arguments Error\n");
		return(1);
	}
	else if(!ft_strnstr(argv[1], ".fdf", len))
	{
		ft_printf("File extension Error\n");
		return(1);
	}
	return(0);
}

void init_fdf(t_fdf *fdf, char *file)
{
	fdf->map = malloc(sizeof (t_map));
	fdf->map->fd = open(file, O_RDONLY);
	fdf->map->buff = get_next_line(fdf->map->fd);
	while(fdf->map->buff)
	{
		fdf->map->line = ft_strjoin(fdf->map->line, fdf->map->buff);
		free(fdf->map->buff);
		fdf->map->buff = get_next_line(fdf->map->fd);
	}
	 fdf->map->matriz = ft_split(fdf->map->line, '\n');
	free(fdf->map->line);
	close(fdf->map->fd);
}

int main(int argc, char *argv[])
{
	t_fdf *fdf;

	fdf = malloc(sizeof (t_fdf));
	if(validations(argc, argv) == 1)
		return(1);
	init_fdf(fdf, argv[1]);
	print_mtx(fdf->map->matriz);
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
