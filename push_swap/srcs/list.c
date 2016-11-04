
#include <libft.h>
#include <stdlib.h>

#include "push_swap.h"

t_list	*create_elem(int value)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		exit(-1);
	new->next = NULL;
	new->previous = NULL;
	new->value = value;
	return (new);
}

void	push_front(t_list **list, t_list *new)
{
	new->next = *list;
	if (*list != NULL)
		(*list)->previous = new;
	*list = new;
}

void	push_back(t_list **list, t_list **last, t_list *new)
{
	if (*list == NULL)
	{
		*list = new;
		*last = new;
	}
	else
	{
		(*last)->next = new;
		new->previous = *last;
		*last = new;
	}
}

void	print_list(t_list *list, char *name)
{
	ft_putstr("Print : ");
	ft_putendl(name);
	while (list)
	{
		ft_putendl(ft_itoa(list->value));
		list = list->next;
	}
}

void	print_list_reverse(t_list *last, char *name)
{
	ft_putstr("Print reverse : ");
	ft_putendl(name);
	while (last)
	{
		ft_putendl(ft_itoa(last->value));
		last = last->previous;
	}
}
