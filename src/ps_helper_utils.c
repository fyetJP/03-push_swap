/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:56:16 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/10 23:28:45 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

int	ft_greatest(int compare_a, int compare_b)
{
	if (compare_a >= compare_b)
		return (compare_a);
	else
		return (compare_b);
}

int	ft_smallest(int compare_a, int compare_b)
{
	if (compare_a < compare_b)
		return (compare_a);
	else
		return (compare_b);
}

void	ft_set_short_great(t_stack **stack, int value)
{
	(*stack)->shortest = ft_smallest(value, (*stack)->shortest);
	(*stack)->biggest = ft_greatest(value, (*stack)->biggest);
}

void	ft_clear_stack(t_stack **stack)
{
	if (ft_stack_size(&((*stack)->head)) > 0)
	{
		while ((*stack)->head)
			ft_pop(&(*stack)->head);
	}
	free(*stack);
	*stack = (t_stack *) NULL;
	stack = (t_stack **) NULL;
}

void	ft_clear_strs(char **strs)
{
	unsigned int	i;

	i = 0;
	if (strs)
	{
		while (strs[i] != (char *) NULL)
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		strs = (char **) NULL;
	}
}
