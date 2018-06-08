/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:40:16 by cwu               #+#    #+#             */
/*   Updated: 2018/05/22 15:40:18 by cwu              ###   ########.fr       */
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

void	ra(t_stacks *s)
{
	t_node *t2;
	t_node *tmp;
	t_list *op;

	if (!(s->a) || !(s->a)->nx)
		return ;
	tmp = (s->a)->nx;
	t2 = tmp;
	while (tmp->nx)
		tmp = tmp->nx;
	tmp->nx = s->a;
	(s->a)->nx = NULL;
	s->a = t2;
	op = (t_list*)malloc(sizeof(t_list));
	op->o = g_lookup[4].str;
	if (s->ops)
	{
		op->nx = s->ops;
		s->ops->pv = op;
	}
	else
		op->nx = NULL;
	s->ops = op;
}

void	rb(t_stacks *s)
{
	t_node *t2;
	t_node *tmp;
	t_list *op;

	if (!(s->b) || !(s->b)->nx)
		return ;
	tmp = (s->b)->nx;
	t2 = tmp;
	while (tmp->nx)
		tmp = tmp->nx;
	tmp->nx = s->b;
	(s->b)->nx = NULL;
	s->b = t2;
	op = (t_list*)malloc(sizeof(t_list));
	op->o = g_lookup[5].str;
	if (s->ops)
	{
		op->nx = s->ops;
		s->ops->pv = op;
	}
	else
		op->nx = NULL;
	s->ops = op;
}

void	rr(t_stacks *s)
{
	ra(s);
	rb(s);
}

void	rra(t_stacks *s)
{
	t_node *t2;
	t_node *tmp;
	t_list *op;

	if (!(s->a) || !(s->a)->nx)
		return ;
	tmp = s->a;
	while (tmp->nx)
	{
		t2 = tmp;
		tmp = tmp->nx;
	}
	t2->nx = NULL;
	tmp->nx = s->a;
	s->a = tmp;
	op = (t_list*)malloc(sizeof(t_list));
	op->o = g_lookup[6].str;
	if (s->ops && s->ops->o)
	{
		op->nx = s->ops;
		s->ops->pv = op;
	}
	else
		op->nx = NULL;
	s->ops = op;
}

void	rrb(t_stacks *s)
{
	t_node *t2;
	t_node *tmp;
	t_list *op;

	if (!(s->b) || !(s->b)->nx)
		return ;
	tmp = s->b;
	while (tmp->nx)
	{
		t2 = tmp;
		tmp = tmp->nx;
	}
	t2->nx = NULL;
	tmp->nx = s->b;
	s->b = tmp;
	op = (t_list*)malloc(sizeof(t_list));
	op->o = g_lookup[7].str;
	if (s->ops)
	{
		op->nx = s->ops;
		s->ops->pv = op;
	}
	else
		op->nx = NULL;
	s->ops = op;
}
