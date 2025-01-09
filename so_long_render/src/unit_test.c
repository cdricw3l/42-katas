/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:51:28 by cb                #+#    #+#             */
/*   Updated: 2025/01/09 13:10:52 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int error_layer_test(void)
{
    int i = -1;
    int count;

    while (i < ERR_SCOPE + 10)
       count =  error_layer(i++);
    return(count); 
}

int dynamique_hook(t_data *d)
{
    static int k = 0;
    t_img_sets *data;
    t_img *im1;
    t_img *im2;
    t_img *im3;

    data = d->img_sets;
    printf("coici k %d et %p \n", k, data);
    // printf("coici k %p \n", data->img_set_global[k]);
    im1 = data->img_set_global[k];
    im2 = data->img_set_left[k];
    im3 = data->img_set_right[k];
    
    if(im1)
        mlx_put_image_to_window(d->mlx,d->window,im1->img, 10 , 10);
    if(im2)
        mlx_put_image_to_window(d->mlx,d->window,im2->img,250, 100) ;
    if(im3)
        mlx_put_image_to_window(d->mlx,d->window,im3->img,500, 300) ;
    k++;
    if(k == 14)
    {
        printf("retour de k a zero");
        k = 0;
    }
    sleep(1);
    return (0);
}

int main(void)
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
     printf("coici data %p \n", data);
    mlx_loop_hook(data->mlx,&dynamique_hook, data);
    mlx_loop(data->mlx);
    // free(data->mlx);
    // free(data);
    return (0);
}
