/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:34:36 by cwu               #+#    #+#             */
/*   Updated: 2018/05/22 16:34:40 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# define FPF ft_printf

typedef struct		s_node
{
	int				v;
	int				r;
	struct s_node	*nx;
}					t_node;

typedef struct		s_count
{
	int				r;
	int				p;
	int				cons;
}					t_count;

typedef struct		s_list
{
	char			*o;
	struct s_list	*pv;
	struct s_list	*nx;
}					t_list;

typedef struct		s_stacks
{
	t_node			*a;
	t_node			*b;
	int				*tab;
	int				l;
	int				exp;
	t_list			*ops;
}					t_stacks;

typedef void		(*t_fp)(t_stacks *s);

typedef	struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef	struct		s_lookup
{
	char			*str;
	t_fp			f;
}					t_lookup;

t_stacks			get_stacks(int ac, char **av);
void				pa(t_stacks *s);
void				pb(t_stacks *s);
void				sa(t_stacks *s);
void				sb(t_stacks *s);
void				ra(t_stacks *s);
void				rb(t_stacks *s);
void				rra(t_stacks *s);
void				rrb(t_stacks *s);
void				ss(t_stacks *s);
void				rr(t_stacks *s);
void				rrr(t_stacks *s);
void				small_list_3(t_stacks *s);
void				small_list_5(t_stacks *s, int ac);
void				assign_rank(t_stacks *s);
void				recurainc(t_stacks *s, int e);
void				recurbdec(t_stacks *s, int e);
void				split(t_stacks *s, int e, t_count *c, int i);
void				cancel(t_list **ops, t_stacks s);
int					count_nodes(t_node *t);
int					count_list(t_node *t, int ref, int e);
int					*sort(int *tab, int l);
int					*sorted_arr(t_stacks *s);
int					max_digit(t_stacks s);
void				print_header(int w);
t_color				get_color(t_stacks s, t_node *t);
void				free_malloc(t_stacks *s);
int					verify(t_stacks *s);
void				print_nums(t_stacks s, t_node **t, int digits, int w);
void				print_stacks(t_stacks s, int i);
char				**split_arg(int *acp, char **av);

#endif
