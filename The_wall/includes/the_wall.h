#ifndef THE_WALL_H
# define THE_WALL_H
#include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "tw_def.h"


// int	check_code(char **code);
int		ch_synt(t_tw *tw);
int		ch_ft(t_tw *tw);
int		ranger(const char c);
int		builder(t_tw *tw, char *code, int sep);
int		steward(t_tw *tw);
void	sam(int *book_cont, int fd);
#endif
