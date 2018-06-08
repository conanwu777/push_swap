/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:35:01 by cwu               #+#    #+#             */
/*   Updated: 2018/05/22 16:35:04 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			cancellation_pair(char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "pa") && !ft_strcmp(s2, "pb"))
			|| (!ft_strcmp(s1, "pb") && !ft_strcmp(s2, "pa"))
			|| (!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra"))
			|| (!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "rrb"))
			|| (!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra"))
			|| (!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb"))
			|| (!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sa"))
			|| (!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sb")))
		return (1);
	return (0);
}

void		cancel(t_list **ops, t_stacks s)
{
	t_list *t;

	t = *ops;
	while (*ops && t && t->nx && s.a)
		if (cancellation_pair(t->o, t->nx->o))
		{
			if (t == *ops)
			{
				*ops = (*ops)->nx->nx;
				if (*ops)
					(*ops)->pv = NULL;
			}
			else if (!t->nx->nx)
				t->pv->nx = NULL;
			else
			{
				t->pv->nx = t->nx->nx;
				t->nx->nx->pv = t->pv;
			}
			free(t);
			free(t->nx);
			t = *ops;
		}
		else
			t = t->nx;
}

int			count_list(t_node *t, int ref, int e)
{
	int l;

	l = 0;
	while (t)
	{
		if ((t->r >> e) == ref)
			l++;
		t = t->nx;
	}
	return (l);
}
