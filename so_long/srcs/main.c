#include "../mlx_linux/mlx.h"
#include <stdio.h>


int	main(void)
{
    void	*mlx;
    void    *new_w;


    mlx = mlx_init();
    new_w = mlx_new_window(mlx, 1920, 1080, "hello");
    mlx_loop(mlx);
    printf("%p\n", mlx);
    return(0);
}


//valgrind --leak-check=yes myprog arg1 arg2