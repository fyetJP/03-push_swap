/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:30:22 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/14 01:51:05 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

static char	*ft_assert_action(char	*str);

static void	ft_read_instructions(t_stack **a, t_stack **b);

static void	ft_execute_action(t_stack **a, t_stack **b, char *action);

int	main(int ac, char **av)
{
	t_stack			*a;
	t_stack			*b;
	char			**int_strs;
	unsigned int	*num_of_ints;

	if (ac < 2)
		return (-1);
	num_of_ints = ft_oom_guard(malloc(sizeof(unsigned int)));
	*num_of_ints = ac;
	int_strs = ft_check_errors(++av, num_of_ints);
	a = ft_init_stack_with_elements(int_strs, *num_of_ints);
	b = ft_alloc_stack();
	ft_read_instructions(&a, &b);
	ft_clear_strs(int_strs);
	free(num_of_ints);
	num_of_ints = (unsigned int *) NULL;
	ft_clear_stack(&a);
	ft_clear_stack(&b);
	return (0);
}

static char	*ft_assert_action(char	*str)
{
	size_t	size;

	if (!str || *str == '\0')
		return ((char *) NULL);
	size = ft_strlen(str);
	if (size == ft_strlen("pa\n"))
	{
		if (ft_strncmp(str, "pa\n", size) || ft_strncmp(str, "pb\n", size)
			|| ft_strncmp(str, "sa\n", size) || ft_strncmp(str, "sb\n", size)
			|| ft_strncmp(str, "ss\n", size) || ft_strncmp(str, "rr\n", size)
			|| ft_strncmp(str, "ra\n", size) || ft_strncmp(str, "rb\n", size))
			return (str);
	}
	else if (size == ft_strlen("rra\n"))
	{
		if (ft_strncmp(str, "rra\n", size) || ft_strncmp(str, "rrb\n", size)
			|| ft_strncmp(str, "rrr\n", size))
			return (str);
	}
	else if (ft_strncmp(str, "Error\n", size))
	{
		ft_print_error();
		return ((char *) NULL);
	}
	return ((char *) NULL);
}

static void	ft_read_instructions(t_stack **a, t_stack **b)
{
	char	*action;
	bool	reading;

	if (!a || !(*a)->head || !b)
		return ;
	reading = true;
	while (reading)
	{
		action = ft_assert_action(get_next_line(STDIN_FILENO));
		if (!action || *action == '\n' || *action == '\0')
			reading = false;
		else
			ft_execute_action(a, b, action);
		free(action);
	}
	if (ft_stack_is_sorted(a, STACK_A) && ft_stack_is_empty((*b)->head))
		ft_print_ok();
	else
		ft_print_ko();
}

static void	ft_execute_action(t_stack **a, t_stack **b, char *action)
{
	if (*action == 'p' || *action == 's')
	{
		ft_exec_ps(a, b, action);
		return ;
	}
	if (*action == 'r')
	{
		if (action[1] == 'r')
		{
			ft_exec_rr(a, b, action);
			return ;
		}
		ft_exec_r(a, b, action);
		return ;
	}
}
