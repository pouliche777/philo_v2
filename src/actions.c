/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:32:15 by slord             #+#    #+#             */
/*   Updated: 2022/09/23 20:45:55 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo, int pos1, int pos2)
{
	philo->time_last_meal = get_time() - philo->table->start_time;
	philo->meals++;
	pthread_mutex_unlock(&philo->table->waiter);
	printf(" %lu  philosopher %d is eating\n",
		(get_time() - philo->table->start_time), philo->n_philo + 1);
	pthread_mutex_unlock(&philo->table->waiter);
	goodnight_sweetprince(*philo, philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->mutex[pos1]);
	pthread_mutex_unlock(&philo->table->mutex[pos2]);
}

void	sleeping(t_philo philo)
{
	pthread_mutex_lock(&philo.table->waiter);
	printf(" %lu  philosopher %d is sleeping\n",
		(get_time() - philo.table->start_time), philo.n_philo + 1);
	pthread_mutex_unlock(&philo.table->waiter);
	goodnight_sweetprince(philo, philo.table->time_to_sleep);
}

void	take_fork(int pos, t_philo philo)
{
	pthread_mutex_lock(&philo.table->mutex[pos]);
	pthread_mutex_lock(&philo.table->waiter);
	printf(" %lu  philosopher %d has taken a fork\n",
		(get_time() - philo.table->start_time), philo.n_philo + 1);
	pthread_mutex_unlock(&philo.table->waiter);
}

void	thinking(t_philo *philo)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->table->waiter);
	printf(" %lu  philosopher %d is thinking\n",
		(get_time() - philo->table->start_time), philo->n_philo + 1);
	philo->table->meals++;
	pthread_mutex_unlock(&philo->table->waiter);
	if (philo->meals == philo->table->nb_of_meals)
		pthread_detach(philo->thread);
	pthread_mutex_lock(&philo->table->waiter);
	time_to_think = (philo->table->time_without_meal - (get_time()
				- philo->time_last_meal) - philo->table->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->table->waiter);
	goodnight_sweetprince(*philo, time_to_think);
}
