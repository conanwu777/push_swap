/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:35:41 by cwu               #+#    #+#             */
/*   Updated: 2018/05/22 16:35:44 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	get_stacks(int k, char **tab)
{
	t_stacks	s;
	t_node		*tmp;
	int			i;

	tmp = NULL;
	i = -1;
	s.ops = NULL;
	while (++i < k)
	{
		s.a = (t_node*)malloc(sizeof(t_node));
		s.a->v = ft_atoi(tab[k - 1 - i]);
		s.a->nx = tmp;
		tmp = s.a;
		if (!ft_isint(tab[k - 1 - i]))
		{
			s.a = NULL;
			return (s);
		}
	}
	i--;
	s.tab = sorted_arr(&s);
	assign_rank(&s);
	s.b = NULL;
	return (s);
}

int			*sort(int *tab, int l)
{
	int tmp;
	int i;

	i = -1;
	while (++i < l - 1)
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
	i = -1;
	while (++i < l - 1)
		if (tab[i] == tab[i + 1])
		{
			free(tab);
			tab = NULL;
			break ;
		}
	return (tab);
}

int			*sorted_arr(t_stacks *s)
{
	t_node	*p;
	t_node	*t;
	int		*tab;
	int		i;

	p = s->a;
	t = p;
	s->l = count_nodes(p);
	s->exp = 1;
	i = s->l - 1;
	while (i >> 1)
	{
		i = i >> 1;
		s->exp++;
	}
	tab = (int*)malloc(sizeof(int) * s->l);
	i = 0;
	while (p)
	{
		tab[i] = p->v;
		p = p->nx;
		i++;
	}
	tab = sort(tab, i);
	return (tab);
}

void		assign_rank(t_stacks *s)
{
	t_node	*t;
	t_node	*t2;
	int		r;
	int		l;

	if (s->tab == NULL)
	{
		free_malloc(s);
		s->a = NULL;
	}
	l = count_nodes(s->a);
	t = s->a;
	t2 = NULL;
	r = 0;
	while (r < l && t)
	{
		if (s->tab[r] == t->v)
		{
			t->r = r;
			t2 = t;
			r = -1;
			t = t->nx;
		}
		r++;
	}
}
