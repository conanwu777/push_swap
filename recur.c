/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:49:20 by cwu               #+#    #+#             */
/*   Updated: 2018/05/22 16:49:21 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split(t_stacks *s, int e, t_count *c, int i)
{
	t_node	*t;
	int		ref;
	int		l;

	t = (i == 1 ? s->a : s->b);
	ref = t->r >> e;
	t = (i == 1 ? s->a : s->b);
	l = count_list(t, ref, e);
	c->cons = 0;
	while (t && c->r + c->p < l && (t->r >> e) == ref)
	{
		if ((t->r >> (e - 1)) % 2 == i && (c->r++) >= 0)
		{
			(i == 1 ? ra(s) : rb(s));
			c->cons++;
		}
		else
		{
			(i == 1 ? pb(s) : pa(s));
			c->p++;
			c->cons = 0;
		}
		t = (i == 1 ? s->a : s->b);
	}
}

void	recurainc(t_stacks *s, int e)
{
	t_count	c;
	int		n;

	c.r = 0;
	c.p = 0;
	if (e == 1 && s->a->nx && s->a->nx->r >> 1 == s->a->r >> 1 &&
			s->a->r > s->a->nx->r)
		sa(s);
	if (e > 1 && s->a && s->a->nx)
	{
		if (count_list(s->a, s->a->r >> (e - 1), e - 1)
		< count_list(s->a, s->a->r >> e, e))
			split(s, e, &c, 1);
		n = count_nodes(s->a);
		if (c.r <= n / 2 || c.cons > n / 2)
			while (c.r--)
				rra(s);
		else
			while (c.r++ < n)
				ra(s);
		recurainc(s, e - 1);
		recurbdec(s, e - 1);
		while (c.p--)
			pa(s);
	}
}

void	recurbdec(t_stacks *s, int e)
{
	t_count	c;
	int		n;

	c.r = 0;
	c.p = 0;
	if (e == 1 && s->b->nx && s->b->nx->r >> 1 == s->b->r >> 1 &&
			s->b->r < s->b->nx->r)
		sb(s);
	if (e > 1 && s->b && s->b->nx)
	{
		if (count_list(s->b, s->b->r >> (e - 1), e - 1)
		< count_list(s->b, s->b->r >> e, e))
			split(s, e, &c, 0);
		n = count_nodes(s->b);
		if (c.r <= n / 2 || c.cons > n / 2)
			while (c.r--)
				rrb(s);
		else
			while (c.r++ < n)
				rb(s);
		recurainc(s, e - 1);
		recurbdec(s, e - 1);
		while (c.p--)
			pb(s);
	}
}
