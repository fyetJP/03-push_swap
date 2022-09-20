/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:50:09 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/11 17:42:28 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

t_stack	*ft_alloc_stack(void)
{
	t_stack	*stack;

	stack = ((t_stack *) NULL);
	stack = (t_stack *)ft_oom_guard(malloc(sizeof(*stack)));
	if (!stack)
		return ((t_stack *) NULL);
	stack->biggest = INT_MIN;
	stack->shortest = INT_MAX;
	stack->is_sorted = false;
	stack->head = (t_stack_elmt *) NULL;
	stack->size = ft_stack_size;
	return (stack);
}

int	ft_set_elements(t_stack **stack, char **values, int count)
{
	int	index;
	int	value;

	index = count - 1;
	if ((*stack)->head == (t_stack_elmt *) NULL)
	{
		value = ft_atoi(values[index]);
		(*stack)->head = ft_new_stack_node(value);
		ft_set_short_great(stack, value);
		(*stack)->head->index = --index;
		while (index >= 0)
		{
			value = ft_atoi(values[index]);
			ft_push(&(*stack)->head, value);
			ft_set_short_great(stack, value);
			(*stack)->head->index = --index;
		}
	}
	return (index);
}

t_stack	*ft_init_stack_with_elements(char **values, int count)
{
	t_stack	*stack;

	stack = ft_alloc_stack();
	if (!stack)
		return ((t_stack *) NULL);
	ft_set_elements(&stack, values, count);
	return (stack);
}

unsigned int	ft_stack_size(t_stack_elmt **head)
{
	t_stack_elmt	*temp;
	unsigned int	count;

	temp = (t_stack_elmt *) NULL;
	if (ft_stack_is_empty(*head))
		return (0);
	count = 0;
	temp = *head;
	temp->index = count;
	if (temp)
		count++;
	while (temp->next)
	{
		temp = temp->next;
		temp->index = count;
		count++;
	}
	temp = (t_stack_elmt *) NULL;
	return (count);
}

void	ft_find_next_smallest_greatest(t_stack **stack)
{
	t_stack_elmt	*temp;
	unsigned int	count;

	if (!stack || !(*stack))
		return ;
	temp = (*stack)->head;
	count = 0;
	temp->index = count;
	(*stack)->biggest = INT_MIN;
	(*stack)->shortest = INT_MAX;
	ft_set_short_great(stack, temp->value);
	while (temp->next)
	{
		temp = temp->next;
		temp->index = ++count;
		ft_set_short_great(stack, temp->value);
	}
}
