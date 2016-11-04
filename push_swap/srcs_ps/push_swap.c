
#include <libft.h>

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

//Check if higher value in pos 2 then r_rot

void	ordering(t_pile *pile_a, t_pile *pile_b)
{
	// print_list_reverse(pile_a->last, "A");
	while (!is_ordered(pile_a, pile_b))
	{
		if (pile_a-> list != NULL
			&& pile_a->last->value > pile_a->list->value)
		{
			if (pile_b->list != NULL
				&& pile_b->last->value > pile_b->list->value)
			{
				rotate(pile_b);
				ft_putstr("rr\n");
			}
			else
				ft_putstr("ra\n");
			rotate(pile_a);
		}
		else if (pile_a->list != NULL && pile_a->last->previous != NULL
			&& pile_a->last->value > ((t_list *)pile_a->last->previous)->value)
		{
			if (pile_b->list != NULL && pile_b->last->previous != NULL
				&& pile_b->last->value < ((t_list *)pile_b->last->previous)->value)
			{
				swap(pile_b);
				ft_putstr("ss\n");
			}
			else
				ft_putstr("sa\n");
			swap(pile_a);
		}
		else if (((t_list *)pile_a->last->previous)->previous != NULL
			&& ((t_list *)pile_a->last->previous)->value > pile_a->list->value)
		{
			ft_putstr("sa\n");
			swap(pile_a);
		}
		else if (pile_b->list != NULL && pile_b->nb_elem > 0 && ordered(pile_a))
		{
			ft_putstr("pa\n");
			push(pile_a, pile_b);
		}
		else
		{
			ft_putstr("pb\n");
			push(pile_b, pile_a);
		}
		// print_list_reverse(pile_a->last, "A");
		// print_list_reverse(pile_b->last, "B");
	}
}

int		main(int ac, char **av)
{
	t_pile		pile_a;
	t_pile		pile_b;

	if (ac > 1)
	{
		preset_pile(&pile_a, &pile_b);
		if (process_arg(&pile_a, av + 1, ac - 1))
			ordering(&pile_a, &pile_b);
		else
			ft_putstr("Error.\n");
	}
	return (0) ;
}
