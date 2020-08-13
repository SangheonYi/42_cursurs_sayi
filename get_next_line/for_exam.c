#include "get_next_line.h"

int get_next_line(char **line)
{
    static char *str;
    char        *tmp;
    char        buf[BUFFER_SIZE + 1];
    int         nbit;

    nbit = 1;
    while (ft_strchr(str, '\n') && nbit != 0)
    {
        if ((nbit = read(0, buf, BUFFER_SIZE)) < 0)
            return (-1);
        buf[BUFFER_SIZE] = '\0';
        tmp = str;
        str = (str == NULL) ? ft_strjoin(buf, "") : ft_strjoin(tmp, buf);
        if (tmp != NULL)
            free(tmp);
    }
    if ((tmp = ft_strchr(str, '\n')) != NULL)
    {
        *tmp = 0;
        *line = ft_strjoin(str, "");

    }
}
