/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:38:24 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/10 23:28:01 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_actions.h"

int	ft_rotate_func(t_stack **stack)
{
	t_stack_elmt	*temp_head;

	if (ft_stack_is_empty((**stack).head))
		return (EMPTY_STACK);
	if ((**stack).size(&(**stack).head) < 2)
		return (0);
	temp_head = (**stack).head->next;
	while (temp_head->next != (t_stack_elmt *) NULL)
		temp_head = temp_head->next;
	temp_head->next = (**stack).head;
	(**stack).head = (**stack).head->next;
	temp_head->next->next = (t_stack_elmt *) NULL;
	temp_head = (t_stack_elmt *) NULL;
	return (1);
}

int	ft_rotate_(t_stack **a, t_stack **b, const unsigned char opt)
{
	if (ft_tolower(opt) == STACK_A)
	{
		if (ft_rotate_func(a) != true)
			return (0);
		ft_printf("ra\n");
	}
	if (ft_tolower(opt) == STACK_B)
	{
		if (ft_rotate_func(b) != true)
			return (0);
		ft_printf("rb\n");
	}
	if (ft_tolower(opt) == (STACK_A + STACK_B)
		|| ft_tolower(opt) == ('A' + 'B'))
	{
		if (ft_rotate_func(a) != true && ft_rotate_func(b) != true)
			return (0);
		ft_printf("rr\n");
	}
	return (1);
}

int	ft_reverse_rotate_func(t_stack **stack)
{
	t_stack_elmt	*temp_head[2];

	if (ft_stack_is_empty((**stack).head))
		return (EMPTY_STACK);
	if ((**stack).size(&(**stack).head) < 2)
		return (0);
	temp_head[0] = (**stack).head;
	while (temp_head[0]->next->next != (t_stack_elmt *) NULL)
		temp_head[0] = temp_head[0]->next;
	temp_head[1] = temp_head[0]->next;
	temp_head[0]->next = (t_stack_elmt *) NULL;
	temp_head[1]->next = (**stack).head;
	(**stack).head = temp_head[1];
	temp_head[0] = (t_stack_elmt *) NULL;
	temp_head[1] = (t_stack_elmt *) NULL;
	return (1);
}

int	ft_reverse_rotate_(t_stack **a, t_stack **b, const unsigned char opt)
{
	if (ft_tolower(opt) == STACK_A)
	{
		if (ft_reverse_rotate_func(a) != true)
			return (0);
		ft_printf("rra\n");
	}
	if (ft_tolower(opt) == STACK_B)
	{
		if (ft_reverse_rotate_func(b) != true)
			return (0);
		ft_printf("rrb\n");
	}
	if (ft_tolower(opt) == (STACK_A + STACK_B)
		|| ft_tolower(opt) == ('A' + 'B'))
	{
		if (ft_reverse_rotate_func(a) != true
			&& ft_reverse_rotate_func(b) != true)
			return (0);
		ft_printf("rrr\n");
	}
	return (1);
}
