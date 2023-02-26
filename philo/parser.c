/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:38:44 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/26 03:31:34 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static t_bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static t_bool is_numeric(char *s)
{
	int		i;
	char	c;

	i = 0;
	while (s[i])
	{
		c = s[i];
		if (!is_digit(c))
			return (false);
		i++;
	}
	return (true);
}

static int ft_atoi(char *s)
{
	int	i;
	int num;

	i = 0;
	num = 0;
	while (is_space(s[i]))
		i++;
	while (is_digit(s[i]))
		num = num * 10 + (s[(i)++] - '0');
	return (num);
}

t_bool	arg_parser(int argv, char **argc)
{
	uint8_t	i;
	
	if (argv < 5 || argv > 6)
		return (false);
	i = 1;
	while (i < argv)
	{
		if (!is_numeric(argc[i++]))
			return (false);
	}
	get_args()->nbr_of_philo = ft_atoi(argc[1]);
	get_args()->time_to_die = ft_atoi(argc[2]);
	get_args()->time_to_eat = ft_atoi(argc[3]);
	get_args()->time_to_sleep = ft_atoi(argc[4]);
	if (argv == 6)
		get_args()->eat_count = ft_atoi(argc[5]);
	return (true);
}
