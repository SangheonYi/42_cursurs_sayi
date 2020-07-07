#include "the_wall.h"

static void	the_oath(int fd)
{
	write(fd, "printf(\"Night gathers, and now my watch begins.\\n", 49);
	write(fd, "It shall not end until my death.\\n", 34);
	write(fd, "I shall take no wife, hold no lands, father no children.\\n", 58);
	write(fd, "I shall wear no crowns and win no glory.\\n", 42);
	write(fd, "I shall live and die at my post. I am the sword in the darkness.\\n", 66);
	write(fd, "I am the watcher on the walls. I am the shield that guards the realms of men.\\n", 79);
	write(fd, "I pledge my life and honor to the Night's Watch, for this night and all the nights to come.\\n", 93);
	write(fd, "―The Night's Watch oath\\n\")", 29);
}

static void	sam_swit(int book_int, int fd)
{
	switch (book_int)
	{
	case 62:
		write(fd, "printf(\"%c\\n\", *p)", 19);
		break;
	case 63:
		write(fd, "printf(\"%p\\n\", p)", 17);
		break;
	case 64:
		write(fd, "printf(\"%d\\n\", right)", 21);
		break;
	case 65:
		write(fd, "printf(\"%d\\n\", left)", 20);
		break;
	case 66:
		write(fd, "(*p)++", 6);
		break;
	case 67:
		write(fd, "(*p)--", 6);
		break;
	case 68:
		write(fd, "p++", 3);
		break;
	case 69:
		write(fd, "p--", 3);
		break;
	case 70:
		write(fd, "*p = right", 10);
		break;
	case 71:
		write(fd, "printf(\"Winter Is Coming\\n\")", 28);
		break;
	case 72:
		the_oath(fd);
		break;
	default:
		break;
	}
}

void		sam(int *book_cont, int fd)
{
	int		i;
	char	c;

	i = -1;
	c = 0;
	if (book_cont[3] == -1)
		write(fd, "while (*p)\n{\n", 13);
	while (++i < 3)
	{
		// printf("write book[%d]: %d, c: %c\n", i, book_cont[i], c);
		if (book_cont[i] < 62 && i < 2)
		{
			if (!i)
				write(fd, "left = ", 7);
			else if (i == 1)
				write(fd, "right = ", 8);
			if (book_cont[i] < 10)
				c = book_cont[i] + '0';
			else if (book_cont[i] < 36)
				c = book_cont[i] + 'a' - 10;
			else
				c = book_cont[i] + 'A' - 33;
			if (book_cont[i] > 10)
				write(fd, "'", 1);
			write(fd, &c, 1);
			if (book_cont[i] > 10)
				write(fd, "'", 1);
		}
		else
			sam_swit(book_cont[i], fd);
		write(fd, ";\n", 2);
	}
	// printf("write book[%d]: %d, c: %c\n", i, book_cont[i], c);
	if (book_cont[3] == -2)
		write(fd, "}\n", 2);
}
