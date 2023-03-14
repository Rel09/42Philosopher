/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:55:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/14 02:55:11 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long int	get_timestamp(void)
{
	static long long int starttime;
	static t_bool	init;
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (!init)
	{
		starttime = time.tv_sec*1000LL + time.tv_usec/1000; // calculate
		init = true;
	}
	return ((time.tv_sec*1000LL + time.tv_usec/1000) - starttime);
}

void	consolelog(uint8_t mode, int nbr, char *str)
{
	if (mode == EATING)
		printf("%-10lli %i is eating\n", get_timestamp(), nbr);
	else if (mode == SLEEPING)
		printf("%-10lli %i is sleeping\n", get_timestamp(), nbr);
	else if (mode == THINKING)
		printf("%-10lli %i is thinking\n", get_timestamp(), nbr);
	else if (mode == DIED)
		printf("%-10lli %i died\n", get_timestamp(), nbr);
	else
		printf("%-10lli %s\n", get_timestamp(), str);
}

int	errormsg(uint8_t mode)
{
	if (mode == ARGS)
		printf("Error with Arguments\n");
	return (1);
}
