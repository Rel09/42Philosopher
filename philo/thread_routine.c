/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:34:24 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/30 02:50:17 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// Part of the Main Loop, Get the timers
t_bool	thread_routine(long long int *timer, t_fork *t)
{
	t->timer = get_timestamp();
	*timer = t->timer - t->sub_timer;
	if (*timer >= get_args()->time_to_die || get_args()->nbr_of_philo == 1)
	{
		consolelog(DIED, t->print_number, get_timestamp());
		death_watcher(SET);
		return (false);
	}
	return (true);
}
