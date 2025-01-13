/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:51:28 by cb                #+#    #+#             */
/*   Updated: 2025/01/10 15:32:20 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <dirent.h>
#include <X11/keysym.h>

int error_layer_test(void)
{
    int i = -1;
    int count;

    while (i < ERR_SCOPE + 10)
       count =  error_layer(i++);
    return(count); 
}

void ft_slice_img(t_img *img)
{
    printf("voici les info sur l'image: \n");
    printf(" addresse img %p, bit_px %d, frame size %d \n", img, img->bit_per_pixel, img->frame_size);
    printf(" line len img %d, img class %s, largeur %d \n", img->line_length, img->class, img->width);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int dynamique_hook(t_data *d)
{   
   
    t_img_sets *data;
    t_img *im;
    t_img *new;

    data = d->img_sets;
    im = data->img_set_left[0];
    
    new = malloc(sizeof(t_img));
    ft_slice_img(im);
    mlx_put_image_to_window(d->mlx,d->window, im->img, 10, 10);
    if(d->mlx != NULL && (im->width / im->frame_size) != 0 )
    {
        new->img = mlx_new_image(d->mlx, 32 , 32);
        
        assert(new->img != NULL);
        assert(new->addr != NULL);
    }
    //my_mlx_pixel_put(new,32 , 32,0x00FF0000);
    //mlx_put_image_to_window(d->mlx, d->window, new, 10,10);
    sleep(1);
    return (0);
}

int ft_close_windows(int keycode, t_data **data)
{
    printf("voici le keycode %d\n", keycode);
	(void)data;
    if(keycode == 65307 || keycode == 64)
    {
        printf("voici %p \n", (*data)->img_sets);
        printf("data .mlx %p\n", (*data)->map);
	    mlx_destroy_window((*data)->mlx, (*data)->window);
        free_memory(data, 42);
        return(0);
    }
    return(1);
}


//test data initialisation and clean;

int unit_test_init_and_clean(void)
{
    t_data *data;

    data = malloc(sizeof(t_data));
    assert(data != NULL);
	data->mlx    = mlx_init();
    assert(data->mlx != NULL);
	
    char		**path_g;
	char		**path_l;
	char		**path_r;
    int i =0;
	path_g = get_paths(1);
	path_l = get_paths(2);
	path_r = get_paths(3);
    
    while (i < SET_SIZE)
    {
        int fd = open(path_g[i], O_RDONLY);
        int fd2 = open(path_l[i], O_RDONLY);
        int fd3 = open(path_r[i], O_RDONLY);
        assert(fd != -1);
        assert(fd2 != -1);
        assert(fd3 != -1);
        if(fd == -1 || fd2 == -1 || fd3 == -1)
            printf("ERREUR OUVERTURE PATH\n");
        close(fd);
        close(fd2);
        close(fd3);
        printf("[ G ] %s\n", path_g[i]);
        printf("[ L ] %s\n", path_l[i]);
        printf("[ R ] %s\n", path_r[i]);
        printf("%d \n", i);
        i++;
    }
    

    assert(path_g !=NULL);
    assert(path_l !=NULL);
    assert(path_r !=NULL);
    data->img_sets = malloc(sizeof(t_img_sets));

    int h = get_image_frame_size("../../tildset/number/610_9_1.xpm");
    assert(h == 1);
	if(!data->img_sets)
		return(error_layer(ERR_GET_IMGPATH));
    i = image_loader(data, path_g, path_l, path_r);
    printf("image i %d\n", i);
    assert(i == 0);
    free_path_memory(path_g, path_l, path_r);
    printf("fin du chargement des messages\n");

    data->window = mlx_new_window(data->mlx,1920, 1080,"hello");
    assert(data->window != NULL);
    data->map_name = "map/map3.ber";
    data->map = get_map(data);
    assert(data->map != NULL);
    printf("coici data %p \n", data->map);
    mlx_key_hook(data->window,&ft_close_windows, &data);
    mlx_loop_hook(data->mlx, &dynamique_hook, data);
    mlx_loop(data->mlx);
    return(0);    
}

int main(void)
{
    
    unit_test_init_and_clean();

    t_data *data;


    data = malloc(sizeof(t_data));
    assert(data != NULL);
    char *dir = "map";
    struct dirent *dent;
    DIR *j = opendir(dir);
    if (j == NULL)
    {
       perror(0);
       return(0);
    }
    dent = readdir(j);
    int i = 0;
    while (dent != NULL)
    {   

        if(dent->d_name[ft_strlen(dent->d_name) - 1] == 'r')
        {
            data->map_name = ft_strjoin("map/",dent->d_name);
            data->map = get_map(data);
            printf("iindex de map : %d\n", i);
            if(data->map == NULL)
            {
                error_layer(99);
                printf("result error: %s\n", data->map_name);
            }
            free(data->map_name);
            assert(data->map != NULL );
            assert(check_map(data) == 0);
        }
        dent = readdir(j);
        i++;
    }
    closedir(j);
    
    //printf("voivci la screen size %d et %d\n", data->xy_data.screen_size.col, data->xy_data.screen_size.row);
    (void)data;
    return (0);
}
