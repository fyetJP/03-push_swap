/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:18:08 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/11 17:43:38 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

t_stack_elmt	*ft_new_stack_node(int value)
{
	t_stack_elmt	*new_node;

	new_node = (t_stack_elmt *)ft_oom_guard(malloc(sizeof(*new_node)));
	new_node->value = value;
	new_node->index = 0;
	new_node->next = ((t_stack_elmt *) NULL);
	return (new_node);
}

int	ft_stack_is_empty(t_stack_elmt *head)
{
	return (!head);
}

int	ft_peek(t_stack_elmt *head)
{
	if (ft_stack_is_empty(head))
		return (EMPTY_STACK);
	return (head->value);
}

void	ft_push(t_stack_elmt **head, int value)
{
	t_stack_elmt	*new_node;

	new_node = (t_stack_elmt *) NULL;
	new_node = ft_new_stack_node(value);
	if (!new_node)
		return ;
	new_node->next = *head;
	*head = new_node;
}

int	ft_pop(t_stack_elmt **head)
{
	int				popped;
	t_stack_elmt	*temp;

	if (ft_stack_is_empty(*head))
		return (EMPTY_STACK);
	popped = ft_peek(*head);
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (popped);
}
