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
    t_i i;
    t_i *image = &i;
    
    char	*relative_path = "/home/cb/Documents/42K/so_long/srcs/dino.xpm";
    int w = 0;
    int h = 0;
    mlx = mlx_init();
    win = mlx_new_window(mlx,1920,1080,"hello");
    i.img = mlx_xpm_file_to_image(mlx,relative_path, &w,&h);
    if(!i.img)
        return(1);
    i.addr = mlx_get_data_addr(image, &image->bits_per_pixel, &image->line_length,&image->endian);
    //printf("voici adresse %p\n",img.img->addr);
    mlx_put_image_to_window(mlx,win, image,w,h);
    mlx_loop(mlx);
    return(0);
}