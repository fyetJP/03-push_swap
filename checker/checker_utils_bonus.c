/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 01:24:04 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/14 01:26:28 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

int	ft_exec_ps(t_stack **a, t_stack **b, char *action)
{
	if (!a || !b || !action || *action == '\0')
		return (0);
	if (action[0] == 'p' && action[1] == 'a' && action[2] == '\n')
		return (ft_push_func(b, a));
	if (action[0] == 'p' && action[1] == 'b' && action[2] == '\n')
		return (ft_push_func(a, b));
	if (action[0] == 's' && action[1] == 'a' && action[2] == '\n')
		return (ft_swap_func(a));
	if (action[0] == 's' && action[1] == 'b' && action[2] == '\n')
		return (ft_swap_func(b));
	if (action[0] == 's' && action[1] == 's' && action[2] == '\n')
	{
		ft_swap_func(a);
		ft_swap_func(b);
		return (1);
	}
	return (0);
}

int	ft_exec_r(t_stack **a, t_stack **b, char *action)
{
	if (!a || !b || !action || *action == '\0')
		return (0);
	if (action[0] == 'r' && action[1] == 'a' && action[2] == '\n')
		return (ft_rotate_func(a));
	if (action[0] == 'r' && action[1] == 'b' && action[2] == '\n')
		return (ft_rotate_func(b));
	return (0);
}

int	ft_exec_rr(t_stack **a, t_stack **b, char *action)
{
	if (!a || !b || !action || *action == '\0')
		return (0);
	if (action[0] == 'r' && action[1] == 'r' && action[2] == '\n')
	{
		ft_rotate_func(a);
		ft_rotate_func(b);
		return (1);
	}
	if (action[0] == 'r' && action[1] == 'r' && action[2] == 'a'
		&& action[3] == '\n')
		return (ft_reverse_rotate_func(a));
	if (action[0] == 'r' && action[1] == 'r' && action[2] == 'b'
		&& action[3] == '\n')
		return (ft_reverse_rotate_func(b));
	if (action[0] == 'r' && action[1] == 'r' && action[2] == 'r'
		&& action[3] == '\n')
	{
		ft_reverse_rotate_func(a);
		ft_reverse_rotate_func(b);
		return (1);
	}
	return (0);
}
