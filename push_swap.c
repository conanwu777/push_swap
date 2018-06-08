/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:38:01 by cwu               #+#    #+#             */
/*   Updated: 2018/05/22 16:38:03 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_rev(t_list *ops)
{
	t_list	*t;
	int		i;

	t = (ops ? ops : 0);
	i = 0;
	while (t && t->nx)
		t = t->nx;
	while (t && t->pv)
	{
		ft_printf("%s\n", t->o);
		t = t->pv;
		i++;
	}
	if (t)
	{
		ft_printf("%s\n", t->o);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_stacks	s;

	if ((ac--) == 1)
		return (ft_printf("{O}Usage: push_swap numbers_to_sort\n"));
	av = split_arg(&ac, &av[1]);
	if (!(s = get_stacks(ac, av)).a)
		return (ft_printf("{Y}Error\n"));
	if (ac >= 3 && ac <= 5)
	{
		(ac == 3 ? small_list_3(&s) : small_list_5(&s, ac));
		cancel(&s.ops, s);
		print_list_rev(s.ops);
		free_malloc(&s);
		return (0);
	}
	recurainc(&s, s.exp);
	if (s.ops)
		s.ops->pv = NULL;
	cancel(&s.ops, s);
	print_list_rev(s.ops);
	free_malloc(&s);
	return (0);
}

void	small_list_3(t_stacks *s)
{
	if (s->a->r < s->a->nx->r && s->a->r < s->a->nx->nx->r)
	{
		ra(s);
		(s->a->r > s->a->nx->r ? sa(s) : 1);
		rra(s);
	}
	else if ((s->a->r < s->a->nx->r && s->a->r > s->a->nx->nx->r)
		|| (s->a->r > s->a->nx->r && s->a->r < s->a->nx->nx->r))
		(s->a->r > s->a->nx->r ? sa(s) : rra(s));
	else if (s->a->r > s->a->nx->r && s->a->r > s->a->nx->nx->r)
	{
		ra(s);
		(s->a->r < s->a->nx->r ? 1 : sa(s));
	}
	s->ops->pv = NULL;
}

void	small_list_5(t_stacks *s, int ac)
{
	int		j;

	if (s->a->r == 1 && s->a->nx->r == 0)
		sa(s);
	j = 0;
	while (j < 2)
	{
		if (s->a->r < 2)
		{
			pb(s);
			j++;
		}
		else
			ra(s);
	}
	if (ac == 5)
		small_list_3(s);
	else
		(s->a->r < s->a->nx->r ? 1 : sa(s));
	(s->b->r < s->b->nx->r ? sb(s) : 1);
	pa(s);
	pa(s);
	s->ops->pv = NULL;
}
