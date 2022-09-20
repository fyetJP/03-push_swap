/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:36:35 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/10 23:26:32 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_actions.h"

int	ft_swap_func(t_stack **stack)
{
	int	temp[4];

	if (ft_stack_is_empty((**stack).head))
		return (EMPTY_STACK);
	if ((**stack).size(&(**stack).head) < 2)
		return (0);
	temp[0] = (**stack).head->index;
	temp[1] = ft_pop(&(**stack).head);
	temp[2] = (**stack).head->index;
	temp[3] = ft_pop(&(**stack).head);
	ft_push(&(**stack).head, temp[1]);
	(**stack).head->index = temp[2];
	ft_push(&(**stack).head, temp[3]);
	(**stack).head->index = temp[0];
	return (1);
}

int	ft_swap_(t_stack **a, t_stack **b, const unsigned char opt)
{
	if (ft_tolower(opt) == STACK_A)
	{
		if (ft_swap_func(a) != true)
			return (0);
		ft_printf("sa\n");
	}
	if (ft_tolower(opt) == STACK_B)
	{
		if (ft_swap_func(b) != true)
			return (0);
		ft_printf("sb\n");
	}
	if (ft_tolower(opt) == (STACK_A + STACK_B)
		|| ft_tolower(opt) == ('A' + 'B'))
	{
		if (ft_swap_func(a) != true && ft_swap_func(b) != true)
			return (0);
		ft_printf("ss\n");
	}
	return (1);
}

int	ft_push_func(t_stack **pop_from, t_stack **push_to)
{
	if (!pop_from || !push_to)
		return (0);
	if (ft_stack_is_empty((**pop_from).head))
		return (EMPTY_STACK);
	ft_push(&(**push_to).head, ft_pop(&(**pop_from).head));
	(**push_to).head->index = 0;
	return (1);
}

int	ft_push_(t_stack **a, t_stack **b, const unsigned char opt)
{
	if (ft_tolower(opt) == STACK_A)
	{
		if (ft_push_func(b, a) != true)
			return (0);
		ft_printf("pa\n");
	}
	if (ft_tolower(opt) == STACK_B)
	{
		if (ft_push_func(a, b) != true)
			return (0);
		ft_printf("pb\n");
	}
	return (1);
}
