/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:59:04 by jpires-p          #+#    #+#             */
/*   Updated: 2022/09/11 20:53:47 by jpires-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_repeats(char *str, char **strs)
{
	size_t	size_str;
	size_t	size_p_str;

	if (!str || !strs)
		return (-1);
	size_str = ft_strlen(str);
	while (*(++strs) != (char *) NULL)
	{
		size_p_str = ft_strlen(*strs);
		if (size_p_str >= size_str)
		{
			if (ft_strncmp(str, *strs, size_p_str) == 0)
				return (1);
		}
		else if (size_p_str < size_str)
		{
			if (ft_strncmp(*strs, str, size_str) == 0)
				return (1);
		}
	}
	return (0);
}

static unsigned int	ft_numof_ints_in_str(char *str)
{
	unsigned int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str != '\0')
	{
		while (ft_isspace(*str))
			str++;
		if ((*str != '-' && *str != '+')
			&& !ft_isdigit(*str))
			exit(ft_print_error());
		str++;
		while (ft_isdigit(*str))
			str++;
		count++;
	}
	if (count == 0)
		exit(ft_print_error());
	return (count);
}

static char	*ft_get_int_str(const char *str, unsigned int *begin)
{
	char			*temp_str;
	unsigned int	iter;

	if (!str)
		return ((char *) NULL);
	iter = *begin;
	while (ft_isspace(str[iter]))
		iter++;
	if (str[iter] == '-' && str[iter] == '+'
		&& !ft_isdigit(str[iter]))
		exit(ft_print_error());
	*begin = iter;
	iter++;
	while (ft_isdigit(str[iter]))
		iter++;
	temp_str = ft_substr(str, *begin, (iter - *begin));
	*begin = iter;
	return (temp_str);
}

static char	**ft_extract_ints(char **initial_args, unsigned int *n_args)
{
	char			**result;
	unsigned int	num_of_ints;
	unsigned int	i[4];

	i[0] = 0;
	num_of_ints = 0;
	while (initial_args[i[0]] != NULL && i[0] < *n_args)
		num_of_ints += ft_numof_ints_in_str(initial_args[(i[0]++)]);
	if (num_of_ints == 0)
		return ((char **) NULL);
	result = ft_oom_guard((char **)malloc((num_of_ints + 1) * sizeof(char *)));
	result[num_of_ints] = (char *) NULL;
	i[0] = 0;
	i[1] = 0;
	while (initial_args[i[1]] != NULL && i[0] < num_of_ints)
	{
		i[2] = 0;
		i[3] = ft_strlen(initial_args[i[1]]);
		while (i[2] < i[3] && i[0] < num_of_ints)
			result[(i[0]++)] = ft_get_int_str(initial_args[i[1]], &i[2]);
		i[1]++;
	}
	*n_args = num_of_ints;
	return (result);
}

char	**ft_check_errors(char **args, unsigned int *size)
{
	unsigned int	count;
	char			**temp_str;
	char			**result;

	if (!args || *size < 1)
		return ((char **) NULL);
	result = ft_extract_ints(args, size);
	if (!result)
		exit(ft_print_error());
	count = *size;
	temp_str = result;
	while (*temp_str != NULL && count > 0)
	{
		if (ft_isstr(*temp_str) == 1)
			exit(ft_print_error());
		if (ft_strisint(*temp_str) == 0)
			exit(ft_print_error());
		if (ft_check_repeats(*temp_str, temp_str) == 1)
			exit(ft_print_error());
		temp_str++;
		count--;
	}
	return (result);
}
