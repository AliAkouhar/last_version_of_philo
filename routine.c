/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:10:56 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/27 16:59:27 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *p)
{
    t_philo *philo;

    philo = (t_philo *)p;
    pthread_mutex_lock(&philo->time);
    philo->start = get_time();
    philo->last_meal = get_time() ;
    pthread_mutex_unlock(&philo->time);
    philo = (t_philo *)p;
    if (philo->id % 2 == 0)
        ft_usleep((philo->data->t_eat - 20));
    while (philo->data->death_flag && get_status(philo) != DIED)
    {
        if (get_status(philo) == DIED)
            break ;
        if (ft_eating(philo))
            return ((void *)1);
        if (get_status(philo) == DIED)
            break ;
        ft_sleeping(philo);
        if (get_status(philo) == DIED)
            break ;
        ft_thinking(philo);
    }
    return (NULL);
}
