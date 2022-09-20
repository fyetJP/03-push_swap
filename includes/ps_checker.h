/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:50:12 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/13 01:50:31 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
# define PS_CHECKER_H

# include	"push_swap.h"

/*
** checker_utils_bonus.c
*/

int	ft_exec_ps(t_stack **a, t_stack **b, char *action);

int	ft_exec_r(t_stack **a, t_stack **b, char *action);

int	ft_exec_rr(t_stack **a, t_stack **b, char *action);

#endif