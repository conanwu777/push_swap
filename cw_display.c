/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 00:29:03 by cwu               #+#    #+#             */
/*   Updated: 2018/05/23 00:29:04 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lookup g_lookup[] =
{	{"sa", &sa},
	{"sb", &sb},
	{"pa", &pa},
	{"pb", &pb},
	{"ra", &ra},
	{"rb", &rb},
	{"rra", &rra},
	{"rrb", &rrb},
	{"ss", &ss},
	{"rr", &rr},
	{"rrr", &rrr},
	{0, 0}
};

void	print_stacks_color(t_stacks *s)
{
	t_node		*t;
	t_node		*u;
	int			digits;
	int			w;

	digits = max_digit(*s);
	w = (s->l / 65 + 1) * (digits + 1) - 1;
	print_header(w);
	t = s->a;
	u = s->b;
	while (t || u)
	{
		write(1, "          ", 10);
		print_nums(*s, &t, digits, w);
		print_nums(*s, &u, digits, w);
		FPF("\n");
	}
	settext(234, 229, 211);
}

int		print_steps(int fd, t_stacks *s, int sw)
{
	char		*line;
	int			steps;
	t_fp		f;
	int			i;

	steps = 0;
	while (ft_gnl(fd, &line) == 1)
	{
		steps++;
		f = 0;
		i = -1;
		while (g_lookup[++i].str)
			if (!ft_strcmp(line, g_lookup[i].str))
				f = g_lookup[i].f;
		f(s);
		if (sw == 1)
		{
			print_stacks_color(s);
			write(1, "\e[0J\e[4;1H", 10);
		}
		free(line);
	}
	return (steps);
}

int		option_v(int ac, char **av)
{
	t_lookup	ins;
	t_stacks	s;
	int			i;

	av = split_arg(&ac, &av[2]);
	if (!(s = get_stacks(ac, av)).a)
		return (FPF("{Y}Error: Invalid Numbers\n"));
	write(1, "\e[2J\n\n\n\e[0J\e[4;1H", 17);
	print_stacks_color(&s);
	while (ft_gnl(0, &ins.str))
	{
		if (!ft_strcmp(ins.str, "\0"))
			return (verify(&s) ? FPF("{R}KO\n") : FPF("{G}OK\n"));
		i = -1;
		ins.f = NULL;
		while (g_lookup[++i].str)
			if (!ft_strcmp(ins.str, g_lookup[i].str))
				ins.f = g_lookup[i].f;
		(!ins.f ? 1 : ins.f(&s));
		write(1, "\e[4;1H\e[0J", 10);
		print_stacks_color(&s);
		(!ins.f ? FPF("{O}Invalid Operation\n") : 1);
		free(ins.str);
	}
	return (verify(&s) ? FPF("{R}KO\n") : FPF("{G}OK\n"));
}

int		options(int ac, char **av)
{
	t_stacks	s;
	t_stacks	o;
	int			fd;
	int			steps;

	if (!ft_strcmp(av[1], "-v"))
		return (option_v(ac, av));
	if ((fd = open(av[2], O_RDONLY)) == -1)
		return (FPF("{Y}Error: Invalid File\n"));
	ac--;
	av = split_arg(&ac, &av[3]);
	if (!(s = get_stacks(ac, av)).a)
		return (FPF("{Y}Error: Invalid Numbers\n"));
	o = get_stacks(ac, av);
	steps = print_steps(fd, &s, 0);
	write(1, "\n\n", 2);
	o.b = s.a;
	print_stacks_color(&o);
	(verify(&s) == 0 ? FPF("\n          Sorted %d numbers \
in %d steps\n\n", ac, steps) :
	FPF("{R}\n          List not sorted\n\n"));
	return (0);
}

int		main(int ac, char **av)
{
	t_stacks	s;
	int			fd;
	int			steps;

	if (ac < 3)
	{
		FPF("{O}Usage: cw_display [[-q] source_file | [-v]] ");
		return (FPF("{O}numbers_to_sort\n"));
	}
	ac -= 2;
	if (!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-q"))
		return (options(ac, av));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (FPF("{Y}Error: Invalid File\n"));
	av = split_arg(&ac, &av[2]);
	if (!(s = get_stacks(ac, av)).a)
		return (FPF("{Y}Error: Invalid Numbers\n"));
	write(1, "\e[2J\n\n\n", 7);
	steps = print_steps(fd, &s, 1);
	print_stacks_color(&s);
	(verify(&s) == 0 ? FPF("\n          Sorted %d numbers \
in %d steps\n\n", ac, steps) :
	FPF("{R}\n          List not sorted\n\n"));
	return (0);
}
