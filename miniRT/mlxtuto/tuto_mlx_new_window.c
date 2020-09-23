#include <mlx.h>

int     main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();//mlx 초기화
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");//새 창을 생성하고 식별자를 반환
    mlx_loop(mlx);//새로 생성한 창이 있는 mlx를 rendering 후 대기
}     