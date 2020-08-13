#include <mlx.h>
#include <stdio.h>
typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int   bits_per_pixel;
    int   line_length;
    int   endian;
}            t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             close(int keycode, t_vars *vars)
{
        mlx_destroy_window(vars->mlx, vars->win);
        printf("close called\n");
}

int             main(void)
{
    t_vars  vars;
    t_data  img;
    void    *mlx;
    void    *mlx_win;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_key_hook(vars.win, close, &vars);

    // img.img = mlx_new_image(mlx, 400, 200);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
    //                              &img.endian);
    // for (int i = 0; i < 100; i++)
    // {
    //     my_mlx_pixel_put(&img, 5, i, 0x00FFFF00);
    //     my_mlx_pixel_put(&img, i, i, 0x00FFFF00);
    //     my_mlx_pixel_put(&img, i, 5, 0x00FFFF00);
    // }

    // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_key_hook(vars.win, close, &vars);
    mlx_hook(vars.win, 3, 1L<<1, close, &vars);
    mlx_loop(vars.mlx);
}
