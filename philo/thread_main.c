/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:19:53 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/18 05:08:44 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_struct(t_fork *t, int threadNum)
{
	t->thread_number = threadNum;
	t->print_number = threadNum + 1;
	t->timer = 0;
	t->sub_timer = 0;
	t->max_eat_count = get_args()->eat_count;
	t->state = THINKING;
}

void		*thread_main(void* data)
{
	t_fork t;
	init_struct(&t, *(int*)data);


	while (true)
	{
		usleep(100);
		t.timer++;
		t.sub_timer++;

		// THINK
		if (t.state == THINKING)
		{
			// Thinking -> Eating
			if	(get_fork(GET, t.thread_number))
			{
				consolelog(EATING, t.print_number);
				t.state = EATING;
				t.sub_timer = 0;
			}
		}

		// EAT
		else if (t.state == EATING)
		{
			// Eating -> Sleeping
			if (t.sub_timer >= get_args()->time_to_eat)
			{
				consolelog(SLEEPING, t.print_number);
				get_fork(SET, t.thread_number);
				t.state = SLEEPING;
				t.sub_timer = 0;
			}
		}

		// SLEEP
		else if (t.state == SLEEPING) {
			
			// Sleeping -> Thinking
			if (t.sub_timer >= get_args()->time_to_sleep)
			{
				consolelog(THINKING, t.print_number);
				t.state = THINKING;
				t.sub_timer = 0;
			}
		}
	}


	return (0);
}
