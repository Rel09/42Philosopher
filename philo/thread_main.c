/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:19:53 by dpotvin           #+#    #+#             */
/*   Updated: 2023/04/03 18:50:15 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// Thinking Function
static void	thinking(long long int timer, t_fork *t)
{
	if (timer > get_args()->time_to_eat
		&& get_fork(GET, t->fork_one_id, t->fork_two_id))
	{
		t->sub_timer = get_timestamp();
		t->state = EATING;
		consolelog(TOOKFORK, t->print_number);
		consolelog(TOOKFORK, t->print_number);
		consolelog(EATING, t->print_number);
	}
}

// Eating Function
static void	eating(long long int current_timer, t_fork *t)
{
	if (current_timer >= get_args()->time_to_eat)
	{
		t->sub_timer = get_timestamp();
		t->state = SLEEPING;
		consolelog(SLEEPING, t->print_number);
		get_fork(SET, t->fork_one_id, t->fork_two_id);
		if (t->fivearg)
			t->eat_count++;
	}
}

// Sleeping Function
static void	sleeping(long long int current_timer, t_fork *t)
{
	if (current_timer >= get_args()->time_to_sleep)
	{
		t->sub_timer = get_timestamp();
		t->state = THINKING;
		consolelog(THINKING, t->print_number);
	}
}

// Init Thread Struct
static void	init_struct(t_fork *t, int threadNum)
{
	t->thread_number = threadNum;
	t->print_number = threadNum + 1;
	t->sub_timer = 0;
	t->eat_count = 0;
	t->state = THINKING;
	t->fork_one_id = threadNum;
	t->fork_two_id = (threadNum + 1) % get_args()->nbr_of_philo;
	t->fivearg = get_args()->eat_count > 0;
}

// Main Loop of each thread
void	*thread_main(void *data)
{
	t_fork			t;
	long long int	current_timer;

	init_struct(&t, *(int *)data);
	while (!death_watcher(GET)
		&& thread_routine(&current_timer, &t)
		&& !(t.fivearg && t.eat_count >= get_args()->eat_count))
	{
		usleep(2);
		if (t.state == THINKING)
			thinking(current_timer, &t);
		else if (t.state == EATING)
			eating(current_timer, &t);
		else if (t.state == SLEEPING)
			sleeping(current_timer, &t);
	}
	return (0);
}
