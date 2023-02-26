/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:31:24 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/26 04:33:02 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*get_args()
{
	static t_args t;
	return (&t);
}

int main(int argv, char **argc)
{
	if (!arg_parser(argv, argc))
	return (errormsg(ARGS));

	return (0);
}
