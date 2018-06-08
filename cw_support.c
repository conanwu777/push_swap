/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 22:59:32 by cwu               #+#    #+#             */
/*   Updated: 2018/05/23 22:59:33 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		max_digit(t_stacks s)
{
	int n;
	int i;

	i = 0;
	n = s.tab[s.l - 1];
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	print_header(int w)
{
	int			count;

	settext(234, 229, 211);
	if (w >= 7)
		ft_putstr("          Stack a");
	else
		ft_putstr("          a");
	count = -1;
	while (++count < (w >= 7 ? w - 7 : w - 1))
		write(1, " ", 1);
	if (w >= 7)
		ft_printf("          Stack b\n");
	else
		ft_printf("          b\n");
	ft_printf("          ");
	count = -1;
	while (++count < w)
		write(1, "=", 1);
	ft_printf("          ");
	count = -1;
	while (++count < w)
		write(1, "=", 1);
	write(1, "\n", 1);
}

t_color	get_color(t_stacks s, t_node *t)
{
	t_color c;
	int		r;

	r = t->r * 600 / s.l;
	if (r <= 300)
	{
		c.r = (r <= 200 ? 18 + 108 * r / 200 :
			126 + 116 * (r - 200) / 100);
		c.g = (r <= 200 ? 86 + 139 * r / 200 :
			225 + 27 * (r - 200) / 100);
		c.b = (r <= 200 ? 169 + 55 * r / 200 :
			224 - 24 * (r - 200) / 100);
	}
	else
	{
		c.r = (r <= 400 ? 242 + 13 * (r - 300) / 100 :
			255 - 57 * (r - 400) / 200);
		c.g = (r <= 400 ? 252 - 52 * (r - 300) / 100 :
			200 - 200 * (r - 400) / 200);
		c.b = (r <= 400 ? 224 - 195 * (r - 300) / 100 :
			5 - 5 * (r - 400) / 200);
	}
	return (c);
}

int		verify(t_stacks *s)
{
	t_node	*t;

	if (s->b != 0 || s->a == 0)
	{
		free_malloc(s);
		return (-1);
	}
	t = s->a;
	while (t->nx)
	{
		if (t->r > t->nx->r)
		{
			free_malloc(s);
			return (-1);
		}
		t = t->nx;
	}
	free_malloc(s);
	return (0);
}

void	print_nums(t_stacks s, t_node **t, int digits, int w)
{
	int count;

	count = 0;
	while (count < w && *t)
	{
		settext(get_color(s, *t).r, get_color(s, *t).g, get_color(s, *t).b);
		count += ft_printf("%0*d ", digits, (*t)->v);
		*t = (*t)->nx;
	}
	while (count < w + 10)
	{
		write(1, " ", 1);
		count++;
	}
}
