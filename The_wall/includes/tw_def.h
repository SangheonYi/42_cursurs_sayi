#ifndef TW_DEF_H
# define TW_DEF_H
# define GATE_START 16
# define GATE_MID 19
# define GATE_END 22
# define WALL_LEN 39
# define OP_POST 1
# define OP_IN 0
# define VALID 1

# define ALLOC_TW_ERR -1
# define FILE_ERR -2
# define LEN_ERR -3
# define GATE_ERR -4
# define BASE_ERR -5
# define FT_ERR -6
# define SEPER_ERR -7
# define LP_SYNT_ERR -8
# define ALLOC_BUILDER_ERR -9

typedef struct	s_tw
{
	char	*code;

	int		*tmp;
	int		row;
	int		op_type;
	int		ret;
	int		is_lp;

	t_list	*nights_watch;
}				t_tw;
#endif
