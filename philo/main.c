/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:31:24 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/14 02:56:18 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*nothing(void* data)
{
	t_fork thread_fork;
	uint8_t state;
	int timer;

	int	thread_number = *(int*)data;
	give_fork(&thread_fork, thread_number);

	// Mini Engine
	state = 0;
	timer = 0;
	while (timer < 20) {
		sleep(1);
		timer += 1;
		consolelog(SLEEPING, thread_number, "");
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
	if (!arg_parser(argv, argc))
		return (errormsg(ARGS));
	get_fork(INIT, 0);
	get_thread(JOIN);
	
	get_fork(FREE, 0);
	get_mutex(FREE);
	get_thread(FREE);
	return (0);
}
