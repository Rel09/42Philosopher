/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:31:24 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/06 17:00:34 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*get_args()
{
	static t_args t;
	return (&t);
}

pthread_t **get_thread(uint8_t mode)
{
	static pthread_t *t;

	if (mode == INIT) {
			t = malloc(get_args()->nbr_of_philo * sizeof(pthread_t));
	}
	else if (mode == FREE)
		free(t);
	return (&t);
}

int main(int argv, char **argc)
{
	if (!arg_parser(argv, argc))
		return (errormsg(ARGS));
	get_thread(INIT);
	
	printf("Base Address: %p\n", (void*)main);

	// Display Stuff
	for (int i = 0; i < get_args()->nbr_of_philo; i++)
		printf("[+] Thread [%d] @ Address: [%p] Initialized\n", i, &((*get_thread(NONE))[i]));


	get_thread(FREE);
	return (0);
}
