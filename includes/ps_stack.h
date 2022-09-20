/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:18:11 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/11 18:08:54 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include	"../libft/includes/libft.h"
# include	"../libft/includes/ft_printf.h"
# include	"../includes/messages.h"

# define EMPTY_STACK INT_MIN
# define SUCCESS  0
# define ERROR  -1
# define STACK_A  97
# define STACK_B  98
# define _P_	112
# define _R_	114
# define _S_	115
# define _RR_	228
# define _SR_	229
# define _SRR_	343

typedef struct s_stack_elmt
{
	int					value;
	unsigned int		index;
	unsigned int		group;
	struct s_stack_elmt	*next;
}	t_stack_elmt;

typedef unsigned int	(*t_s_size)(t_stack_elmt **stack_head);

typedef struct s_stack
{
	bool				is_sorted;
	int					biggest;
	int					shortest;
	t_s_size			size;
	t_stack_elmt		*head;

}	t_stack;

/*
** ps_stack_functions.c
*/

t_stack_elmt	*ft_new_stack_node(int value);

int				ft_stack_is_empty(t_stack_elmt *head);

int				ft_peek(t_stack_elmt *head);

void			ft_push(t_stack_elmt **head, int value);

int				ft_pop(t_stack_elmt **head);

/*
** ps_helper_utils.c 
*/

int				ft_greatest(int compare_a, int compare_b);

int				ft_smallest(int compare_a, int compare_b);

void			ft_set_short_great(t_stack **stack, int value);

void			ft_clear_stack(t_stack **stack);

void			ft_clear_strs(char **strs);

/*
** ps_stack.c 
*/

t_stack			*ft_alloc_stack(void);

int				ft_set_elements(t_stack **stack, char **values, int count);

t_stack			*ft_init_stack_with_elements(char **values, int count);

unsigned int	ft_stack_size(t_stack_elmt **head);

void			ft_find_next_smallest_greatest(t_stack **stack);

/*
** ps_stack_utils.c 
*/

long			ft_get_index(t_stack **stack, int num);

t_stack			***ft_get_right_stack(t_stack **stack, unsigned int opt);

int				ft_stack_is_sorted(t_stack **stack, unsigned int opt);

int				*ft_new_ordered_stack(char **stack, unsigned int size);

/*
** ps_stack_utils_extra.c 
*/

int				*ft_new_arr(char **int_strs, unsigned int size);

void			ft_insertion_sort(int *tab, unsigned int size);

#endif