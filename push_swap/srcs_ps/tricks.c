
#include <libft.h>

#include "push_swap.h"

void	test_swap(t_pile *pile_a, t_pile *pile_b, int *done)
{
	if (!*done)
	{
		if (pile_a->list != NULL && pile_a->last->previous != NULL
			&& (pile_a->last->value > (
				(t_list *)pile_a->last->previous)->value))
		{
			if (pile_b->list != NULL && pile_b->last->previous != NULL
				&& pile_b->last->value < (
					(t_list *)pile_b->last->previous)->value)
			{
				swap(pile_b);
				ft_putstr("ss\n");
			}
			else
				ft_putstr("sa\n");
			swap(pile_a);
			*done = 1;
		}
	}
}

void	test_r_rot(t_pile *pile_a, t_pile *pile_b, int *done)
{
	if (!*done)
	{
		if (pile_a->list != NULL && pile_a->list->next != NULL
			&& ((t_list *)pile_a->list->next)->value > pile_a->list->value
			&& pile_a->last->value > pile_a->list->value)
		{
			if (pile_b->list != NULL && pile_b->list->next
				&& ((t_list *)pile_b->list->next)->value < pile_b->list->value)
			{
				r_rotate(pile_b);
				ft_putstr("rrr\n");
			}
			else
				ft_putstr("rra\n");
			r_rotate(pile_a);
			*done = 1;
		}
	}
}

void	test_rot(t_pile *pile_a, t_pile *pile_b, int *done)
{
	if (!*done)
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
			*done = 1;
		}
	}
}

void	magic_trick(t_pile *pile_a, int *done)
{
	if (pile_a->list != NULL && pile_a->last->previous != NULL
		&& (((t_list *)pile_a->last->previous)->value > pile_a->list->value
		&& pile_a->nb_elem == 3))
	{
		swap(pile_a);
		ft_putstr("sa\n");
		rotate(pile_a);
		ft_putstr("ra\n");
		*done = 1;
	}
}