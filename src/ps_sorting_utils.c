/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:44:48 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/19 23:56:07 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

static unsigned int	ft_choose_case(t_stack_elmt *elm1,
									t_stack_elmt *elm2,
									t_stack_elmt *elm3,
									unsigned int opt)
{
	if (elm1 == (t_stack_elmt *) NULL)
		return (0);
	if (elm2 == (t_stack_elmt *) NULL)
		return (SORTED);
	if (elm3 == (t_stack_elmt *) NULL)
	{
		if (elm1->value > elm2->value)
			return (_S_);
		return (SORTED);
	}
	return (ft_choose_case_(elm1, elm2, elm3, opt));
}

static int	ft_sort_less_three(t_stack **stack, unsigned int opt)
{
	unsigned int	action;
	t_stack			***temp;

	if (!stack || !(*stack)->head)
		return (-1);
	if (!(*stack)->head->next)
		return (1);
	temp = ft_get_right_stack(stack, opt);
	action = ft_choose_case((*stack)->head,
			(*stack)->head->next, (*stack)->head->next->next, opt);
	ft_choose_moves(temp, action, opt);
	temp[0] = (t_stack **) NULL;
	temp[1] = (t_stack **) NULL;
	free(temp);
	return (1);
}

static int	ft_sort_less_ten(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_a)->head)
		return (-1);
	while (!(ft_stack_is_sorted(stack_a, STACK_A))
		&& (*stack_a)->size(&(*stack_a)->head) > 3)
	{
		ft_get_stack_elmt_to_top(stack_a, (*stack_a)->size(&(*stack_a)->head),
			STACK_A, (*stack_a)->shortest);
		if ((*stack_a)->head->value == (*stack_a)->shortest)
			ft_ps_action(stack_a, stack_b, _P_, STACK_B);
		ft_find_next_smallest_greatest(stack_a);
	}
	if (!(ft_stack_is_sorted(stack_a, STACK_A))
		&& (*stack_a)->size(&(*stack_a)->head) <= 3)
		ft_sort_less_three(stack_a, STACK_A);
	return (ft_push_higher_num_to_a(stack_a, stack_b));
}

static int	ft_sort_medium_big_stack(t_stack **stack_a,
									t_stack **stack_b,
									int *key_nums)
{
	int				i;
	unsigned int	size;

	if (!(*stack_a) || !(*stack_a)->head || !key_nums)
		return (-1);
	i = -1;
	size = (*stack_a)->size(&(*stack_a)->head);
	while (!(ft_stack_is_sorted(stack_a, STACK_A))
		&& (*stack_a)->size(&(*stack_a)->head) > 10)
	{
		if (size <= MEDIUM_STACK)
		{
			if (++i < MEDIUM_KEY_NUMS)
				ft_push_under_key_to_b(stack_a, stack_b, key_nums[i]);
		}
		else if (size > MEDIUM_STACK)
		{
			if (++i < BIG_KEY_NUMS)
				ft_push_under_key_to_b(stack_a, stack_b, key_nums[i]);
		}
	}
	if (!(ft_stack_is_sorted(stack_a, STACK_A))
		&& (*stack_a)->size(&(*stack_a)->head) <= 10)
		ft_sort_less_ten(stack_a, stack_b);
	return (ft_push_higher_num_to_a(stack_a, stack_b));
}

int	ft_sort(t_stack **a, t_stack **b, int *key_nums)
{
	long	size_a;
	long	size_b;

	size_a = (*a)->size(&(*a)->head);
	size_b = (*b)->size(&(*b)->head);
	if (size_a > 0 && size_a <= 3)
		ft_sort_less_three(a, STACK_A);
	if (size_b > 0 && size_b <= 3)
		ft_sort_less_three(b, STACK_B);
	if (size_a > 0 && size_a <= 10)
		ft_sort_less_ten(a, b);
	if (size_a > 0 && size_a > 10)
		ft_sort_medium_big_stack(a, b, key_nums);
	return (1);
}
