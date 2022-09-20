/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:48:50 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/11 18:04:45 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORT_H
# define PS_SORT_H

# include "ps_actions.h"

# define SORTED 1
# define MEDIUM_STACK 100
# define BIG_STACK 500
# define MEDIUM_KEY_NUMS 4
# define BIG_KEY_NUMS 8

/*
** ps_sorting_cases.c 
*/

int				case_ggg(t_stack_elmt *elm1,
					t_stack_elmt *elm2,
					t_stack_elmt *elm3);

int				case_lgl(t_stack_elmt *elm1,
					t_stack_elmt *elm2,
					t_stack_elmt *elm3);

int				case_glg(t_stack_elmt *elm1,
					t_stack_elmt *elm2,
					t_stack_elmt *elm3);

int				case_lgg(t_stack_elmt *elm1,
					t_stack_elmt *elm2,
					t_stack_elmt *elm3);

int				case_gll(t_stack_elmt *elm1,
					t_stack_elmt *elm2,
					t_stack_elmt *elm3);

/*
** ps_sorting_cases_extra.c 
*/

int				case_lll(t_stack_elmt *elm1,
					t_stack_elmt *elm2,
					t_stack_elmt *elm3);

unsigned int	ft_choose_case_(t_stack_elmt *elm1,
					t_stack_elmt *elm2,
					t_stack_elmt *elm3,
					unsigned int opt);

void			ft_choose_moves(t_stack ***stack,
					unsigned int action,
					unsigned int opt);

int				*ft_get_key_nums_tab(unsigned int size, int *num);

/*
** ps_sorting_utils.c 
*/

int				ft_sort(t_stack **a, t_stack **b, int *key_nums);

/*
** ps_sorting_utils_extra.c 
*/

void			ft_get_stack_elmt_to_top(t_stack **stack,
					unsigned int size,
					unsigned int opt,
					int needle);

void			ft_push_under_key_to_b(t_stack **stack_a,
					t_stack **stack_b,
					int key_num);

int				ft_push_higher_num_to_a(t_stack **stack_a, t_stack **stack_b);

int				*ft_get_key_nums(char **nums_str, unsigned int size);

#endif