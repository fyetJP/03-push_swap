/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 01:36:19 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/12 20:57:38 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdarg.h>
# include	"../libft/includes/libft.h"
# include	"../libft/includes/ft_printf.h"
# include	"../libft/includes/get_next_line.h"
# include	"messages.h"
# include	"ps_stack.h"
# include	"ps_actions.h"
# include	"ps_sort.h"

/*
** Error Checking 
*/

char	**ft_check_errors(char **args, unsigned int *size);

#endif
