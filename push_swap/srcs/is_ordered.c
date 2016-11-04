
#include <stdlib.h>

#include "push_swap.h"

#include <stdio.h>

int		ordered(t_pile *pile)
{
	t_list	*ptr;

	ptr = pile->list;
	while (ptr->next)
	{
		if (ptr->value <= ((t_list *)ptr->next)->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int		is_ordered(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->nb_elem > 0 || pile_b->list != NULL)
		return (0);
	return (ordered(pile_a));
}
