/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_utils_extra.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 00:36:17 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/19 23:55:36 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

void	ft_get_stack_elmt_to_top(t_stack **stack,
									unsigned int size,
									unsigned int opt,
									int needle)
{
	long	index;
	t_stack	***temp;

	if (!(*stack) || !(*stack)->head || size == 0)
		return ;
	temp = ft_get_right_stack(stack, opt);
	index = -1;
	while ((temp[0] && ((*temp[0])->head) && (*temp[0])->head->value != needle)
		|| (temp[1] && ((*temp[1])->head) && (*temp[1])->head->value != needle))
	{
		index = ft_get_index(stack, needle);
		if (index == -1)
			break ;
		if ((*stack)->head->next->value == needle)
			ft_ps_action(temp[0], temp[1], _S_, opt);
		else if ((size / 2) > index)
			ft_ps_action(temp[0], temp[1], _R_, opt);
		else
			ft_ps_action(temp[0], temp[1], _RR_, opt);
	}
	temp[0] = (t_stack **) NULL;
	temp[1] = (t_stack **) NULL;
	free(temp);
}

void	ft_push_under_key_to_b(t_stack **stack_a,
									t_stack **stack_b,
									int key_num)
{
	t_stack_elmt	*temp;

	if (!(*stack_a) || !(*stack_a)->head
		|| (*stack_a)->size(&(*stack_a)->head) == 0)
		return ;
	temp = (*stack_a)->head;
	while (temp->next)
	{
		if (temp->value <= key_num)
		{
			ft_get_stack_elmt_to_top(stack_a,
				(*stack_a)->size(&(*stack_a)->head), STACK_A, temp->value);
			ft_ps_action(stack_a, stack_b, _P_, STACK_B);
			temp = (*stack_a)->head;
		}
		else
			temp = temp->next;
	}
	if (temp->next && temp->value <= key_num)
	{
		ft_get_stack_elmt_to_top(stack_a,
			(*stack_a)->size(&(*stack_a)->head), STACK_A, temp->value);
		ft_ps_action(stack_a, stack_b, _P_, STACK_B);
	}
}

int	ft_push_higher_num_to_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_b) || !(*stack_b)->head
		|| (*stack_b)->size(&(*stack_b)->head) == 0)
		return (-1);
	ft_find_next_smallest_greatest(stack_b);
	while (!ft_stack_is_empty((*stack_b)->head))
	{
		ft_get_stack_elmt_to_top(stack_b,
			(*stack_b)->size(&(*stack_b)->head),
			STACK_B, ((*stack_b)->biggest));
		ft_ps_action(stack_a, stack_b, _P_, STACK_A);
		if (!ft_stack_is_empty((*stack_b)->head))
			ft_find_next_smallest_greatest(stack_b);
	}
	return (ft_stack_is_sorted(stack_a, STACK_A));
}

int	*ft_get_key_nums(char **nums_str, unsigned int size)
{
	int				*tab;
	int				*ord_stack;
	int				i[3];

	if (!(*nums_str) || size == 0)
		return ((int *) NULL);
	ord_stack = ft_new_ordered_stack(nums_str, size);
	tab = ft_get_key_nums_tab(size, &i[0]);
	if (!tab)
		return ((int *) NULL);
	i[1] = i[0];
	i[2] = 0;
	while (i[1] <= (int)size)
	{
		if (i[1] == (int)size)
			tab[i[2]] = ord_stack[--i[1]];
		else
			tab[i[2]] = ord_stack[i[1]];
		i[1] += i[0];
		i[2]++;
	}
	free(ord_stack);
	return (tab);
}
