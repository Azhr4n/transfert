
#include <stdlib.h>
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

void	free_2d(char **array)
{
	while (*array)
	{
		free(*array);
		array++;
	}
	free(array);
}

int		put_in_list(t_pile *pile, char *str)
{
	char	**array;
	char	**tmp;
	int		ret;

	array = ft_strsplit(str, ' ');
	tmp = array;
	while (*tmp)
	{
		if (!is_number(*tmp))
		{
			free_2d(array);
			return (0);
		}
		ret = ft_atoi(*tmp);
		push_front(&pile->list, create_elem(ret));
		if (!pile->nb_elem)
			pile->last = pile->list;
		pile->nb_elem++;
		tmp++;
	}
	free_2d(array);
	return (1);
}

int		process_arg(t_pile *pile, char **av)
{
	t_list	*offset;
	t_list	*ptr;

	while (*av)
	{
		put_in_list(pile, *av);
		av++;
	}
	offset = pile->list;
	while (((t_list *)offset->next)->next)
	{
		ptr = offset->next;
		while (ptr->next)
		{
			if (offset->value == ptr->value)
				return (0);
			ptr = ptr->next;
		}
		offset = offset->next;
	}
	return (1);
}