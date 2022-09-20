/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 01:36:16 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/12 00:54:12 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack			*a;
	t_stack			*b;
	char			**int_strs;
	int				*key_nums;
	unsigned int	*num_of_ints;

	if (ac < 2)
		return (-1);
	num_of_ints = ft_oom_guard(malloc(sizeof(unsigned int)));
	*num_of_ints = ac;
	int_strs = ft_check_errors(++av, num_of_ints);
	a = ft_init_stack_with_elements(int_strs, *num_of_ints);
	b = ft_alloc_stack();
	key_nums = ft_get_key_nums(int_strs, *num_of_ints);
	ft_clear_strs(int_strs);
	free(num_of_ints);
	num_of_ints = (unsigned int *) NULL;
	ft_sort(&a, &b, key_nums);
	free(key_nums);
	ft_clear_stack(&a);
	ft_clear_stack(&b);
	return (0);
}
