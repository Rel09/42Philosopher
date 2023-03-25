/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:55:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/25 06:22:12 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// Timestamp in Milisecond
long long int	get_timestamp(void)
{
	static pthread_mutex_t	t;
	static t_bool	init_mutex;
	struct timeval	time;
	static t_bool	init;
	static long long int starttime;
	long long int ret;

	if (!init_mutex)
	{
		pthread_mutex_init(&t, 0);
		init_mutex = true;
	}
	pthread_mutex_lock(&t);
	gettimeofday(&time, NULL);
	if (!init)
	{
		starttime = time.tv_sec * 1000 + time.tv_usec / 1000; 
		init = true;
	}
	ret = time.tv_sec * 1000 + time.tv_usec / 1000 - starttime;
	pthread_mutex_unlock(&t);
	return (ret);
}
// Basic Console Logger
void	consolelog(uint8_t mode, int nbr, long long int timestamp)
{
	static pthread_mutex_t	t;
	static t_bool			init;
	
	if (!init)
	{
		pthread_mutex_init(&t, 0);
		init = true;
	}
	pthread_mutex_lock(&t);
	if (mode == EATING)
		printf("%lli %i is eating\n", timestamp, nbr);
	else if (mode == SLEEPING)
		printf("%lli %i is sleeping\n", timestamp, nbr);
	else if (mode == THINKING)
		printf("%lli %i is thinking\n", timestamp, nbr);
	else if (mode == DIED)
		printf("%lli %i died\n", timestamp, nbr);
	pthread_mutex_unlock(&t);
	if (mode == KILL_MUTEX)
		pthread_mutex_destroy(&t);
}
// Error Message + Return
int	errormsg(uint8_t mode)
{
	if (mode == ARGS)
		printf("Error with Arguments\n");
	else if (mode == THREAD)
		printf("Error while creating Thread\n");
	return (1);
}
