#include "the_wall.h"

static int	ch_gate(t_tw *tw)
{
	const char	gate[4][8] =
	{
		{'\\', '_', '_', '|', '_', '_', '/', 0},
		{'_', '|', '\\', '|', '/', '|', '_', 0},
		{'_', '|', '/', '|', '\\', '|', '_', 0},
		{'/', '_', '_', '|', '_', '_', '\\', 0}};
	int			i;

	i = -1;
	while (gate[tw->row][++i])
	{
		if (gate[tw->row][i] != tw->code[GATE_START + i])
		{
			if (!(tw->row % 3) && i && i != 3 && i != 6
			&& ranger(tw->code[GATE_START + i]) != BASE_ERR)
			{
				tw->op_type = OP_IN;
				continue ;
			}
			// printf("row: %d i: %d\n", tw->row, i);
			// printf("gate cmp: %c ? %c\n", gate[tw->row][i], tw->code[GATE_START + i]);
			// printf("tw->row %% 3: %d ? %d\n", tw->row % 3, ranger(tw->code[GATE_START + i]));
			return (GATE_ERR);
		}
		tw->op_type = OP_POST;
	}
	return (VALID);
}

static int	ch_base(t_tw *tw)
{
	int	sep;
	int	i;
	int	base_idx;

	sep = 0;
	i = 0;
	if (!tw->row && tw->code[i] == '[')
	{
		// printf("c: %c\n", tw->code[i]);
		tw->is_lp = LP_SYNT_ERR;
		i++;
	}
	while (i < GATE_START)
	{
		// printf("c: %c\n", tw->code[i]);
		if ((base_idx = ranger(tw->code[i])) == BASE_ERR)
		{
			if (tw->code[i++] == '|' && ++sep)
				continue ;
			return (BASE_ERR);
		}
		i++;
	}
	if (sep % 3 || sep > 3)
		return (SEPER_ERR);
	if (builder(tw, tw->code, sep) == ALLOC_BUILDER_ERR)
		return (ALLOC_BUILDER_ERR);
	sep = 0;
	i = GATE_END;
	while (++i < WALL_LEN)
	{
		// printf("c: %c\n", tw->code[i]);
		if (ranger(tw->code[i]) == BASE_ERR)
		{
			if (tw->code[i] == '|' && ++sep < 4)
				continue ;
			if (i == WALL_LEN - 1 && tw->code[i] == ']')
			{
				tw->is_lp = VALID;
				continue ;
			}
			return (BASE_ERR);
		}
	}
	if (sep % 3 || sep > 3)
		return (SEPER_ERR);
	if (builder(tw, tw->code + GATE_END + 1, sep) == ALLOC_BUILDER_ERR)
		return (ALLOC_BUILDER_ERR);
	return (VALID);
}

int			ch_synt(t_tw *tw)
{
	int	len;

	if ((len = ft_strlen(tw->code)) != WALL_LEN)
		return (len ? LEN_ERR : VALID);
	if (ch_gate(tw) != VALID)
		return (GATE_ERR);
	if (ch_base(tw) != VALID)
		return (BASE_ERR);
	return (VALID);
}
