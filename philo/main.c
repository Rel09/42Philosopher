/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:31:24 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/16 01:36:54 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*nothing(void* data)
{
	t_fork t;
	
	give_fork(&t, *(int*)data);


	// Mini Engine
	while (t.state == SLEEPING)
	{
		sleep(1);
		t.timer += 1;
		consolelog(SLEEPING, t.thread_number + 1);
	}
	
	return (0);
}

t_args		*get_args(void)
{
	static t_args	t;
	return (&t);
}

int			main(int argv, char **argc)
{
	int	var;

	var = 0;
	if (!arg_parser(argv, argc))
		return (errormsg(ARGS));
	if (!get_fork(INIT, 0) || !get_thread(JOIN))
		var = errormsg(THREAD);
	get_fork(FREE, 0);
	get_thread(FREE);
	return (var);
}
