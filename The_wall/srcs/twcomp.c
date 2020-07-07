#include "the_wall.h"

static int	is_valid_tw(t_tw *tw, int fd)
{
	int wall_row = 0;
	while(get_next_line(fd, &(tw->code)) > 0)
	{
		printf("%d. row: %d, code: %s\n", ++wall_row, tw->row, tw->code);
		tw->ret = ch_synt(tw);
		if (tw->code)
			free(tw->code);
		tw->code = 0;
		if (tw->row < 3)
			tw->row++;
		else
			tw->row = 0;
		if (tw->ret != VALID)
			return (tw->ret);
	}
	printf("%d. row: %d, code: %s\n", ++wall_row, tw->row, tw->code);
	tw->ret = ch_synt(tw);
	if (tw->code)
		free(tw->code);
	tw->code = 0;
	if (tw->is_lp == LP_SYNT_ERR)
		return (LP_SYNT_ERR);
	return (tw->ret);
}

int			main(int argc, char **argv)
{
	t_tw	*tw;
	int		fd_source;

	if (argc != 2)
	{
		printf("give one tw file\n");
		return (0);
	}
	if (!(tw = ft_calloc(sizeof(t_tw), 1)))
		return (ALLOC_TW_ERR);
	if ((fd_source = open(argv[1], O_RDONLY)) < 0)
		return (FILE_ERR);
	if ((tw->ret = is_valid_tw(tw, fd_source)) != VALID)
	{
		printf("syntax ERROR: #%d\n", tw->ret);
		return (tw->ret);
	}
	if ((tw->ret = steward(tw)) != VALID)
	{
		printf("steward ERROR: #%d\n", tw->ret);
		return (tw->ret);
	}
	ft_lstclear(&tw->nights_watch, free);
	free(tw);
	system("gcc book.c -o The_wall");
	system("rm book.c");
	return (0);
}
