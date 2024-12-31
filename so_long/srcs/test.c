#include "../include/so_long.h"


typedef struct	s_i {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_i;

int  main(void)
{
    void *mlx;
    void *win;
    char **xpm;
    t_img2 *i2;
    char	*relative_path = "/home/cb/Documents/42K/so_long/items/summer.xpm";
    int w = 0;
    int h = 0;

    mlx = mlx_init();
    if(mlx)
    {
        win = mlx_new_window(mlx,1920,1080,"hello");
        i2 = mlx_xpm_file_to_image(mlx,relative_path,&w,&h);
        printf("voici l'adresse de l'image %p\n", i2->data);
        mlx_loop(mlx);

    }
    else
        printf("Erreur\n");
    return(0);
}