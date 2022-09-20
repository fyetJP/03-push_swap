/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:11:34 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/14 01:47:44 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "messages.h"

int	ft_print_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (-1);
}

int	ft_print_ko(void)
{
	ft_putstr_fd("KO\n", STDERR_FILENO);
	return (-1);
}

int	ft_print_ok(void)
{
	ft_putstr_fd("OK\n", STDOUT_FILENO);
	return (0);
}
