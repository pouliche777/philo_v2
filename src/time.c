/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:32:33 by slord             #+#    #+#             */
/*   Updated: 2022/09/20 18:23:43 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	goodnight_sweetprince(t_philo philo, time_t time_to_sleep)
{
	time_t	sleep_time;

	sleep_time = time_to_sleep + get_time() - philo.table->start_time;
	while (((get_time() - philo.table->start_time) < sleep_time))
	{
		usleep(40);
	}
}
