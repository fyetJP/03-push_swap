/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 03:35:33 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/13 04:46:35 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

long	ft_get_index(t_stack **stack, int num)
{
	t_stack_elmt	*temp;
	long			index;

	if (!stack || !(*stack)->head
		|| (*stack)->size(&(*stack)->head) < 1)
		return (-1);
	temp = (*stack)->head;
	index = 0;
	while (temp->next)
	{
		if (temp->next->value == num)
		{
			temp = (t_stack_elmt *) NULL;
			return (++index);
		}
		index++;
		temp = temp->next;
	}
	return (-1);
}

t_stack	***ft_get_right_stack(t_stack **stack, unsigned int opt)
{
	t_stack	***temp;

	if (!stack || !(*stack))
		return ((t_stack ***) NULL);
	temp = (t_stack ***)ft_oom_guard(malloc(sizeof(t_stack **) * 2));
	if (opt == STACK_A)
	{
		temp[0] = stack;
		temp[1] = (t_stack **) NULL;
	}
	else if (opt == STACK_B)
	{
		temp[0] = (t_stack **) NULL;
		temp[1] = stack;
	}
	return (temp);
}

int	ft_stack_is_sorted(t_stack **stack, unsigned int opt)
{
	t_stack_elmt	*temp;

	if (!stack || !(*stack))
		return (-1);
	temp = (*stack)->head;
	while (temp->next)
	{
		if (opt == STACK_A)
		{
			if (!(temp->value < temp->next->value))
				return (0);
		}
		else if (opt == STACK_B)
		{
			if (!(temp->value > temp->next->value))
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	*ft_new_ordered_stack(char **stack, unsigned int size)
{
	int	*ord_stack;

	if (!(*stack) || **stack == '\0')
		return ((int *) NULL);
	ord_stack = ft_new_arr(stack, size);
	if (!ord_stack)
		return ((int *) NULL);
	ft_insertion_sort(ord_stack, size);
	return (ord_stack);
}
