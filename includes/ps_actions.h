/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:33:36 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/11 17:57:17 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_ACTIONS_H
# define PS_ACTIONS_H

# include	"ps_stack.h"

/*
** Main Caller
*/

int	ft_ps_action(t_stack **a, t_stack **b,
		const unsigned char action, const unsigned int stack_opt);

/*
** Action Callers 
*/

int	ft_swap_(t_stack **a, t_stack **b, const unsigned char opt);

int	ft_push_(t_stack **a, t_stack **b, const unsigned char opt);

int	ft_rotate_(t_stack **a, t_stack **b, const unsigned char opt);

int	ft_reverse_rotate_(t_stack **a, t_stack **b, const unsigned char opt);

/*
** Actions 
*/

int	ft_swap_func(t_stack **stack);

int	ft_push_func(t_stack **pop_from, t_stack **push_to);

int	ft_rotate_func(t_stack **stack);

int	ft_reverse_rotate_func(t_stack **stack);

#endif