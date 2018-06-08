/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_on.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:38:01 by cwu               #+#    #+#             */
/*   Updated: 2018/05/24 18:38:04 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_nodes(t_node *t)
{
	int l;

	l = 0;
	while (t)
	{
		l++;
		t = t->nx;
	}
	return (l);
}

void	free_malloc(t_stacks *s)
{
	t_node *t;
	t_node *t2;
	t_list *op;

	t = s->a;
	while (t)
	{
		t2 = t;
		t = t->nx;
		free(t2);
	}
	(s->tab ? free(s->tab) : 1);
	op = s->ops;
	while (op)
	{
		s->ops = op->nx;
		free(op);
		op = s->ops;
	}
}

void	rrr(t_stacks *s)
{
	rra(s);
	rrb(s);
}

void	print_stacks(t_stacks s, int i)
{
	t_node *a;
	t_node *b;

	a = s.a;
	b = s.b;
	while (i == 1 && (a || b))
	{
		if (a)
		{
			printf("%d ", (a->v));
			a = a->nx;
		}
		else
			printf("  ");
		if (b)
		{
			printf("%d\n", (b->v));
			b = b->nx;
		}
		else
			printf(" \n");
	}
	if (i == 1)
		printf("_ _\na b\n");
}

char	**split_arg(int *acp, char **av)
{
	char **tab;

	if (*acp != 1)
		return (av);
	*acp = cw_countw(av[0], ' ');
	tab = ft_strsplit(av[0], ' ');
	return (tab);
}
