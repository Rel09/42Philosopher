/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:31:24 by dpotvin           #+#    #+#             */
/*   Updated: 2023/04/03 16:58:33 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*get_args(void)
{
	static t_args	t;

	return (&t);
}

int	main(int argv, char **argc)
{
	int	var;

	var = 0;
	if (!arg_parser(argv, argc))
		return (errormsg(ARGS));
	consolelog(100, 0);
	death_watcher(100);
	get_timestamp();
	if (!get_fork(INIT, 0, 0) || !get_thread(JOIN))
		var = errormsg(THREAD);
	consolelog(KILL_MUTEX, 0);
	get_fork(FREE, 0, 0);
	get_thread(FREE);
	return (var);
}
