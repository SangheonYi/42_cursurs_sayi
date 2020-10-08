#include <mlx.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

int             close(int keycode, t_vars *vars)// 이벤트 발생시 call될 함수
{
    mlx_destroy_window(vars->mlx, vars->win);//창을 닫는다.
	return 0;
}

int             main(void)
{
    t_vars      vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_key_hook(vars.win, close, &vars);// 생성된 창에서 입력 이벤트가 발생 시 close 함수를 실행한다.
    mlx_loop(vars.mlx);
} 