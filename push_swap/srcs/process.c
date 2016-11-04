
#include <libft.h>

#include "push_swap.h"

void	preset_pile(t_pile *pile_a, t_pile *pile_b)
{
	pile_a->list = NULL;
	pile_a->last = NULL;
	pile_b->list = NULL;
	pile_b->last = NULL;
	pile_a->nb_elem = 0;
	pile_b->nb_elem = 0;
}

int		process_arg(t_pile *pile, char **av, int size)
{
	char	array[size];
	int		ret;
	int		i;

	while (*av)
	{
		if (!is_number(*av))
			return (0);
		ret = ft_atoi(*av);
		push_front(&pile->list, create_elem(ret));
		if (!pile->nb_elem)
			pile->last = pile->list;
		array[pile->nb_elem] = ret;
		i = 0;
		while (i < pile->nb_elem)
		{
			if (ret == array[i])
				return (0);
			i++;
		}
		pile->nb_elem++;

		av++;
	}
	return (1);
}