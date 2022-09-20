/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:58:36 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/11 19:27:45 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

int	*ft_new_arr(char **int_strs, unsigned int size)
{
	int				*new_tab;
	unsigned int	i;

	if (!(*int_strs) || **int_strs == '\0')
		return ((int *) NULL);
	new_tab = (int *)ft_oom_guard(malloc(size * sizeof(int)));
	i = 0;
	while (i < size)
	{
		if (*int_strs[i] == '\0')
		{
			free (new_tab);
			exit(ft_print_error());
		}
		new_tab[i] = ft_atoi(int_strs[i]);
		i++;
	}
	return (new_tab);
}

void	ft_insertion_sort(int *tab, unsigned int size)
{
	unsigned int	i;
	int				j;
	int				temp;

	if (!tab)
		return ;
	i = 0;
	while (++i < size)
	{
		j = i;
		while (j > 0 && tab[j] < tab[j - 1])
		{
			temp = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = temp;
			j--;
		}
	}
}
