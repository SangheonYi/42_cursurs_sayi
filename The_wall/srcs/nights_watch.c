#include "the_wall.h"

int			ranger(const char c)
{
	const char	base[4] = {'_', '/', '\\', 'X'};
	int			i;

	i = -1;
	while (++i < 4)
	{
		if (c == base[i])
			return (i);
	}
	return (BASE_ERR);
}

static int	operand_len(char *code)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (++i < 16)
	{
		if (code[i] == '|')
			break ;
		else if (ranger(code[i]) != BASE_ERR)
			len++;
	}
	return (len);
}

int			builder(t_tw *tw, char *code, int sep)
{
	int	i;
	int	base_idx;
	int	len;

	// printf("builder code: %s, sep: %d\n", code, sep);
	if (sep == 3)
	{
		if (!(tw->tmp = ft_calloc(sizeof(int), 5)))
			return (ALLOC_BUILDER_ERR);
		i = -1;
		sep = 0;
		len = operand_len(code);
		while (++i < GATE_START)
		{
			len--;
			if (code[i] != '|' && code[i] != '[' && code[i] != ']' && sep < 3)
			{
				if (len >= 0 && (base_idx = ranger(code[i])) && base_idx != BASE_ERR)
				{
					// printf("code[%d]: %c, idx: %d, len: %d, tmp[%d]: %d, ipow: %lld\n", i, code[i], base_idx, len, sep, tw->tmp[sep], ft_ipow(4, len));
					tw->tmp[sep] += ft_ipow(4, len) * base_idx;
					// printf("code[%d]: %c, idx: %d, len: %d, tmp[%d]: %d, ipow: %lld\n", i, code[i], base_idx, len, sep, tw->tmp[sep], ft_ipow(4, len));
				}
			}
			else if (code[i] == '|' && ++sep < 3)
				len = operand_len(code + i + 1);
			else if (code[i] == '[')
				tw->tmp[3] = -1;
			else if (code[i] == ']')
				tw->tmp[3] = -2;
		}
		// printf("code[%d]: %c, idx: %d, len: %d, tmp[%d]: %d, ipow: %lld\n", i, code[i], base_idx, len, sep, tw->tmp[sep], ft_ipow(4, len));
		ft_lstadd_back(&tw->nights_watch, ft_lstnew(tw->tmp));
		tw->tmp = 0;
	}
	return (VALID);
}

int			steward(t_tw *tw)
{
	int		fd;
	t_list	*book;

	book = tw->nights_watch;
	if ((fd = open("book.c", O_CREAT | O_WRONLY | O_TRUNC , 0644)) < 0)
		return (FILE_ERR);
	write(fd, "#include <stdio.h>\n", 19);
	write(fd, "#include <stdlib.h>\n", 20);
	write(fd, "int main(void){\n", 16);
	write(fd, "char *p = calloc(sizeof(char), 1024);\n", 38);
	write(fd, "int left;\n", 10);
	write(fd, "int right;\n", 11);
	// int	i = 0;

	while (book->next)
	{
		// printf("%d book_cont: %d %d %d\n", i++, *((int *)book->content), *((int *)book->content + 1), *((int *)book->content + 2));
		sam((int *)book->content, fd);
		book = book->next;
	}
	sam((int *)book->content, fd);
	write(fd, "free(p);\n", 9);
	write(fd, "return 0;}", 10);
	close(fd);
	return (VALID);
}
