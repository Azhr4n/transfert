
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_list
{
	int			value;
	void		*next;
	void		*previous;
}				t_list;

typedef struct	s_char_list
{
	char		*value;
	void		*next;
}				t_char_list;

typedef struct	s_pile
{
	t_list		*list;
	t_list		*last;
	int			nb_elem;
}				t_pile;

/* operations.c */
void			swap(t_pile *pile);
void			push(t_pile *pile_a, t_pile *pile_b);
void			rotate(t_pile *pile);
void			r_rotate(t_pile *pile);

/* is_number.c */
int				is_number(char *str);

/* list.c */
t_list			*create_elem(int value);
void			push_front(t_list **list, t_list *new);
void			push_back(t_list **list, t_list **last, t_list *new);
void			print_list(t_list *list, char *name);
void			print_list_reverse(t_list *last, char *name);

/* char_list.c */
t_char_list		*create_cl(char *value);
void			push_back_cl(t_char_list **list, t_char_list *new);

/* process.c */
void			preset_pile(t_pile *pile_a, t_pile *pile_b);
int				process_arg(t_pile *pile, char **av, int size);

/* execute.c */
int				reading_command(t_pile *pile_a, t_pile *pile_b);

/* is_ordered.c */
int				is_ordered(t_pile *pile_a, t_pile *pile_b);
int				ordered(t_pile *pile);

#endif