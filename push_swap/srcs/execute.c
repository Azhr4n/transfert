
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

#include "get_next_line.h"
#include "push_swap.h"

void	exec_commands2(t_pile *pile_a, t_pile *pile_b, char *command)
{
	if (!ft_strcmp("ra", command))
		rotate(pile_a);
	else if (!ft_strcmp("rb", command))
		rotate(pile_b);
	else if (!ft_strcmp("rr", command))
	{
		rotate(pile_a);
		rotate(pile_b);
	}
	else if (!ft_strcmp("rra", command))
		r_rotate(pile_a);
	else if (!ft_strcmp("rrb", command))
		r_rotate(pile_b);
	else if (!ft_strcmp("rrr", command))
	{
		r_rotate(pile_a);
		r_rotate(pile_b);
	}
}

void	exec_commands(t_pile *pile_a, t_pile *pile_b, char *command)
{
	if (!ft_strcmp("sa", command))
		swap(pile_a);
	else if (!ft_strcmp("sb", command))
		swap(pile_b);
	else if (!ft_strcmp("ss", command))
	{
		swap(pile_a);
		swap(pile_b);
	}
	else if (!ft_strcmp("pa", command))
		push(pile_a, pile_b);
	else if (!ft_strcmp("pb", command))
		push(pile_b, pile_a);
	exec_commands2(pile_a, pile_b, command);
}

int		executing(t_pile *pile_a, t_pile *pile_b, t_char_list *commands)
{
	t_char_list	*ptr;

	ptr = commands;
	while (ptr)
	{
		exec_commands(pile_a, pile_b, ptr->value);
		ptr = ptr->next;
	}
	return (is_ordered(pile_a, pile_b));
}

int		command_exist(char *buff)
{
	static char	*com[] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(buff, com[i]))
			return (1);
		i++;
	}
	return (0);
}



int		reading_command(t_pile *pile_a, t_pile *pile_b)
{
	t_char_list	*commands;
	char		*line;
	int			size;

	commands = NULL;
	while (1)
	{
		if ((get_next_line(0, &line)) < 0)
			exit(-1);
		size = ft_strlen(line);
		if (!size)
			return (executing(pile_a, pile_b, commands));
		else if (size > 4 || !command_exist(line))
			ft_putstr("Error.\n");
		else
			push_back_cl(&commands, create_cl(ft_strdup(line)));
		free(line);
	}
	return (0);
}
