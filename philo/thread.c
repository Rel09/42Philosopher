/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:57:14 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/14 02:20:19 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	give_fork(t_fork *t, int threadNum)
{
	t->fork_one = get_fork(GET, threadNum);
	if (threadNum == get_args()->nbr_of_philo - 1)
		t->fork_two = get_fork(GET, 0);
	else 
		t->fork_two = get_fork(GET, threadNum + 1);
}
