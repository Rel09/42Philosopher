/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:57:14 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/15 21:24:02 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Give the two correct fork to the Thread
void	give_fork(t_fork *t, int threadNum)
{
	t->thread_number = threadNum;
	t->timer = 0;
	t->state = SLEEPING;
	t->fork_one = get_fork(GET, threadNum);
	if (threadNum == get_args()->nbr_of_philo - 1)
		t->fork_two = get_fork(GET, 0);
	else 
		t->fork_two = get_fork(GET, threadNum + 1);
}
