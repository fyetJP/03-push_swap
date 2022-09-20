/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:39:33 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/10 23:25:55 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_actions.h"

int	ft_ps_action(t_stack **a, t_stack **b,
	const unsigned char action, const unsigned int stack_opt)
{
	if (ft_tolower(action) == _P_)
	{
		if (ft_push_(a, b, stack_opt) == true)
			return (1);
	}
	if (ft_tolower(action) == _S_)
	{
		if (ft_swap_(a, b, stack_opt) == true)
			return (1);
	}
	if (ft_tolower(action) == _R_)
	{
		if (ft_rotate_(a, b, stack_opt) == true)
			return (1);
	}
	if (ft_tolower(action) == _RR_ || ft_tolower(action) == ('R' + 'R'))
	{
		if (ft_reverse_rotate_(a, b, stack_opt) == true)
			return (1);
	}
	return (0);
}
