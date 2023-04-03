/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:34:24 by dpotvin           #+#    #+#             */
/*   Updated: 2023/04/03 19:01:28 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// Part of the Main Loop, Get the timers
t_bool	thread_routine(long long int *timer, t_fork *t)
{
	static pthread_mutex_t	y;
	static t_bool			init;

	if (!init)
	{
		pthread_mutex_init(&y, 0);
		init = true;
	}
	t->timer = get_timestamp();
	*timer = t->timer - t->sub_timer;
	if (*timer >= get_args()->time_to_die || get_args()->nbr_of_philo == 1)
	{
		pthread_mutex_lock(&y);
		if (!death_watcher(GET))
			consolelog(DIED, t->print_number);
		death_watcher(SET);
		pthread_mutex_unlock(&y);
		return (false);
	}
	return (true);
}
