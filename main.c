#include "fdf.h"

void print_mtx(char **mtx) //func de teste //tirar dps
{
    int i = 0;
    while (mtx[i++])
        ft_printf("%s\n", mtx[i]);
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

void	ft_free(char **split)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (split[i++])
		free(split[i]);
	free(split);
}

void init_matriz(t_fdf *fdf, char *file)
{
	int i;
	int j;
	char **mtz;

	i = 0;
	j = 0;
	fdf->map = malloc(sizeof (t_map));
	fdf->map->fd = open(file, O_RDONLY);

	fdf->map->line = get_next_line(fdf->map->fd);
	mtz = ft_split(fdf->map->line, ' ');
	while(mtz[i])
		i++;
	 fdf->map->x = i;
	// pega quantos elementos tem em x

	ft_free(mtz);
	while(fdf->map->line)
	{
		j++;
		free(fdf->map->line);
		fdf->map->line = get_next_line(fdf->map->fd);
	}
	fdf->map->y = j;
	// pega quantos elementos tem em y

	fdf->map->matriz = (int **)malloc((fdf->map->y + 1) * sizeof(int *));
	i = -1;
	while(++i < fdf->map->y)
		fdf->map->matriz[i] = (int *)malloc((fdf->map->x + 1) * sizeof(int));
	// aloca espaço para a matriz baseado no numero de elementos x e y
	close(fdf->map->fd);
	free(fdf->map->line);
	fdf->map->fd = open(file, O_RDONLY);
	j = 0;
	fdf->map->line = get_next_line(fdf->map->fd);
	ft_printf("%s", fdf->map->line);
	while(fdf->map->line)
	{
	i = -1;
	mtz = ft_split(fdf->map->line, ' ');
	print_mtx(mtz);
	while(mtz[++i])
			fdf->map->matriz[j][i] = ft_atoi(mtz[i]);
		j++;
		ft_free(mtz);
		free(fdf->map->line);
		fdf->map->line = get_next_line(fdf->map->fd);
	}
	//print_mtx(mtz);
	ft_printf("\n\n%i\n", fdf->map->matriz[0][1]);
}

void init_fdf(t_fdf *fdf, char *file)
{
	init_matriz(fdf, file);
	return;
}

int main(int argc, char *argv[])
{
	t_fdf *fdf;

	fdf = NULL;
	fdf = malloc(sizeof (t_fdf));
	if(validations(argc, argv) == 1)
		return(1);
	init_fdf(fdf, argv[1]);
	return(0);
}
