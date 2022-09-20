/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_cases_extra.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:22:01 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/11 20:31:11 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_sort.h"

int	case_lll(t_stack_elmt *elm1, t_stack_elmt *elm2, t_stack_elmt *elm3)
{
	if (elm1->value < elm2->value
		&& elm2->value < elm3->value
		&& elm1->value < elm3->value)
		return (1);
	return (0);
}

unsigned int	ft_choose_case_(t_stack_elmt *elm1,
									t_stack_elmt *elm2,
									t_stack_elmt *elm3,
									unsigned int opt)
{
	if (((opt == STACK_A) && case_lgl(elm1, elm2, elm3))
		|| ((opt == STACK_B) && case_glg(elm1, elm2, elm3)))
		return (_SR_);
	if (((opt == STACK_A) && case_glg(elm1, elm2, elm3))
		|| ((opt == STACK_B) && case_lgl(elm1, elm2, elm3)))
		return (_R_);
	if (((opt == STACK_A) && case_lgg(elm1, elm2, elm3))
		|| ((opt == STACK_B) && case_gll(elm1, elm2, elm3)))
		return (_RR_);
	if (((opt == STACK_A) && case_gll(elm1, elm2, elm3))
		|| ((opt == STACK_B) && case_lgg(elm1, elm2, elm3)))
		return (_S_);
	if (((opt == STACK_A) && case_ggg(elm1, elm2, elm3))
		|| ((opt == STACK_B) && case_lll(elm1, elm2, elm3)))
		return (_SRR_);
	return (SORTED);
}

void	ft_choose_moves(t_stack ***stack, unsigned int action, unsigned int opt)
{
	if (!stack)
		return ;
	if (action == (_SRR_))
	{
		ft_ps_action(stack[0], stack[1], _S_, opt);
		ft_ps_action(stack[0], stack[1], _RR_, opt);
	}
	else if (action == (_SR_))
	{
		ft_ps_action(stack[0], stack[1], _S_, opt);
		ft_ps_action(stack[0], stack[1], _R_, opt);
	}
	else
		ft_ps_action(stack[0], stack[1], action, opt);
}

int	*ft_get_key_nums_tab(unsigned int size, int *num)
{
	int	*tab;

	if (!num || size < 1)
		return ((int *) NULL);
	tab = (int *) NULL;
	if (size <= MEDIUM_STACK)
	{
		tab = (int *)ft_oom_guard(malloc(MEDIUM_KEY_NUMS * sizeof(int)));
		*num = size / MEDIUM_KEY_NUMS;
	}
	else if (size > MEDIUM_STACK)
	{
		tab = (int *)ft_oom_guard(malloc(BIG_KEY_NUMS * sizeof(int)));
		*num = size / BIG_KEY_NUMS;
	}
	return (tab);
}
