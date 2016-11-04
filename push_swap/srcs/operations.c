
#include <stdlib.h>

#include "push_swap.h"

void	swap(t_pile *pile)
{
	if (!(pile->nb_elem > 1))
		return ;
	pile->last->value ^= ((t_list *)(pile->last->previous))->value;
	((t_list *)(pile->last->previous))->value ^= pile->last->value;
	pile->last->value ^= ((t_list *)(pile->last->previous))->value;
}

void	push(t_pile *pile_a, t_pile *pile_b)
{
	if (!(pile_b->nb_elem > 0))
		return ;
	push_back(&pile_a->list, &pile_a->last, create_elem(pile_b->last->value));
	if (pile_b->last->previous != NULL)
	{
		pile_b->last = pile_b->last->previous;
		free(pile_b->last->next);
		pile_b->last->next = NULL;
	}
	else
	{
		free(pile_b->last);
		pile_b->last = NULL;
		pile_b->list = NULL;
	}
	pile_a->nb_elem++;
	pile_b->nb_elem--;
}

void	rotate(t_pile *pile)
{
	t_list	*tmp;

	tmp = pile->last;
	while (tmp->previous != NULL)
	{
		tmp->value ^= ((t_list *)(tmp->previous))->value;
		((t_list *)(tmp->previous))->value ^= tmp->value;
		tmp->value ^= ((t_list *)(tmp->previous))->value;
		tmp = tmp->previous;
	}
}

void	r_rotate(t_pile *pile)
{
	t_list	*tmp;

	tmp = pile->list;
	while (tmp->next != NULL)
	{
		tmp->value ^= ((t_list *)(tmp->next))->value;
		((t_list *)(tmp->next))->value ^= tmp->value;
		tmp->value ^= ((t_list *)(tmp->next))->value;
		tmp = tmp->next;
	}
}
