/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:52:21 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/10 23:32:00 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

int	case_ggg(t_stack_elmt *elm1, t_stack_elmt *elm2, t_stack_elmt *elm3)
{
	if (elm1->value > elm2->value
		&& elm2->value > elm3->value
		&& elm1->value > elm3->value)
		return (1);
	return (0);
}

int	case_lgl(t_stack_elmt *elm1, t_stack_elmt *elm2, t_stack_elmt *elm3)
{
	if (elm1->value < elm2->value
		&& elm2->value > elm3->value
		&& elm1->value < elm3->value)
		return (1);
	return (0);
}

int	case_glg(t_stack_elmt *elm1, t_stack_elmt *elm2, t_stack_elmt *elm3)
{
	if (elm1->value > elm2->value
		&& elm2->value < elm3->value
		&& elm1->value > elm3->value)
		return (1);
	return (0);
}

int	case_lgg(t_stack_elmt *elm1, t_stack_elmt *elm2, t_stack_elmt *elm3)
{
	if (elm1->value < elm2->value
		&& elm2->value > elm3->value
		&& elm1->value > elm3->value)
		return (1);
	return (0);
}

int	case_gll(t_stack_elmt *elm1, t_stack_elmt *elm2, t_stack_elmt *elm3)
{
	if (elm1->value > elm2->value
		&& elm2->value < elm3->value
		&& elm1->value < elm3->value)
		return (1);
	return (0);
}
