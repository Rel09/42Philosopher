/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:55:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/16 01:35:25 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// Timestamp in Milisecond
static long long int	get_timestamp(void)
{
	static long long int starttime;
	static t_bool	init;
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (!init)
	{
		starttime = time.tv_sec * 1000 + time.tv_usec / 1000; 
		init = true;
	}
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - starttime);
}
// Basic Console Logger
void	consolelog(uint8_t mode, int nbr)
{

	if (mode == EATING)
		printf("%-19lli| %i is eating\n", get_timestamp(), nbr);
	else if (mode == SLEEPING)
		printf("%-19lli| %i is sleeping\n", get_timestamp(), nbr);
	else if (mode == THINKING)
		printf("%-19lli| %i is thinking\n", get_timestamp(), nbr);
	else if (mode == DIED)
		printf("%-19lli| %i died\n", get_timestamp(), nbr);
}
// Return Error Message - Return 1 in Main, 0 inside others Functions
int	errormsg(uint8_t mode)
{
	if (mode == ARGS)
		printf("Error with Arguments\n");
	else if (mode == THREAD)
		printf("Error while trying to create Thread\n");
	return (1);
}
