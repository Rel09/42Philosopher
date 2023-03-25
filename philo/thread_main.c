/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:19:53 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/25 04:59:30 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_struct(t_fork *t, int threadNum)
{
	t->thread_number = threadNum;
	t->print_number = threadNum + 1;
	t->sub_timer = 0;
	t->eat_count = 0;
	t->state = THINKING;
	t->fork_one_id = threadNum;
	if (threadNum == get_args()->nbr_of_philo - 1)
		t->fork_two_id = 0;
	else
		t->fork_two_id = threadNum + 1;
}

void		*thread_main(void* data)
{
	t_fork t;
	long long int current_timer;
	init_struct(&t, *(int*)data);
	
	while (true)
	{
		usleep(5);

		t.timer = get_timestamp();
		current_timer = t.timer - t.sub_timer;
		
		// THINK
		//		In the Thinking state, Philo are just waiting to eat
		if (t.state == THINKING)
		{
			// Thinking -> Eating
			if (get_fork(GET, t.fork_one_id, t.fork_two_id))
			{
				consolelog(EATING, t.print_number, t.timer);
				t.state = EATING;
				t.sub_timer = get_timestamp();
			}
		}

		// EAT
		//		While eating, the philo reset its last eaten cooldown
		else if (t.state == EATING)
		{
			// Eating -> Sleeping
			if (current_timer >= get_args()->time_to_eat)
			{
				consolelog(SLEEPING, t.print_number, t.timer);
				get_fork(SET, t.fork_one_id, t.fork_two_id);
				t.state = SLEEPING;
				t.sub_timer = get_timestamp();
				// Add +1 to eating count if has 5th argument
				if (get_args()->eat_count > 0)
					t.eat_count++;
			}
		}

		// SLEEP
		//		Wait until the sleep timer is over, and start thinking
		else if (t.state == SLEEPING)
		{
			
			// Sleeping -> Thinking
			if (current_timer >= get_args()->time_to_sleep)
			{
				consolelog(THINKING, t.print_number, t.timer);
				t.state = THINKING;
				t.sub_timer = get_timestamp();
			}
		}
		
		
		
	}


	return (0);
}
