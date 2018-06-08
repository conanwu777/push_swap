/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:34:14 by cwu               #+#    #+#             */
/*   Updated: 2018/05/22 16:34:22 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lookup	g_lookup[] =
{	{"sa", &sa},
	{"sb", &sb},
	{"pa", &pa},
	{"pb", &pb},
	{"ra", &ra},
	{"rb", &rb},
	{"rra", &rra},
	{"rrb", &rrb},
	{0, 0}
};

void	sa(t_stacks *s)
{
	t_node *tmp;
	t_list *op;

	if (!(s->a) || !(s->a)->nx)
		return ;
	tmp = (s->a)->nx;
	(s->a)->nx = (s->a)->nx->nx;
	tmp->nx = s->a;
	s->a = tmp;
	op = (t_list*)malloc(sizeof(t_list));
	op->o = g_lookup[0].str;
	if (s->ops)
	{
		op->nx = s->ops;
		s->ops->pv = op;
	}
	else
		op->nx = NULL;
	s->ops = op;
}

void	sb(t_stacks *s)
{
	t_node *tmp;
	t_list *op;

	if (!(s->b) || !(s->b)->nx)
		return ;
	tmp = (s->b)->nx;
	(s->b)->nx = (s->b)->nx->nx;
	tmp->nx = s->b;
	s->b = tmp;
	op = (t_list*)malloc(sizeof(t_list));
	op->o = g_lookup[1].str;
	if (s->ops)
	{
		op->nx = s->ops;
		s->ops->pv = op;
	}
	else
		op->nx = NULL;
	s->ops = op;
}

void	ss(t_stacks *s)
{
	sa(s);
	sb(s);
}

void	pa(t_stacks *s)
{
	t_node *tmp;
	t_node *t2;
	t_list *op;

	if (!(s->b))
		return ;
	tmp = s->b;
	t2 = tmp->nx;
	tmp->nx = s->a;
	s->b = t2;
	s->a = tmp;
	op = (t_list*)malloc(sizeof(t_list));
	op->o = g_lookup[2].str;
	if (s->ops)
	{
		op->nx = s->ops;
		s->ops->pv = op;
	}
	else
		op->nx = NULL;
	s->ops = op;
}

void	pb(t_stacks *s)
{
	t_node *tmp;
	t_node *t2;
	t_list *op;

	if (!(s->a))
		return ;
	tmp = s->a;
	t2 = tmp->nx;
	tmp->nx = s->b;
	s->a = t2;
	s->b = tmp;
	op = (t_list*)malloc(sizeof(t_list));
	op->o = g_lookup[3].str;
	if (s->ops)
	{
		op->nx = s->ops;
		s->ops->pv = op;
	}
	else
		op->nx = NULL;
	s->ops = op;
}
