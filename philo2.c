/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:57:42 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/26 18:36:59 by ali-akouhar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     ft_create_forks(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->n_philo)
        if (pthread_mutex_init(&data->forks[i], NULL))
            return (1);
    i = -1;
    while (++i < data->n_philo)
    {
        //pthread_mutex_init(data->philo[i].left_fork, NULL);
        //pthread_mutex_init(data->philo[i].right_fork,NULL);
        data->philo[i].left_fork = &data->forks[i];
        data->philo[i].right_fork = &data->forks[(i + 1) % data->n_philo];
    }
    return (0);
}

void    ft_init_philo(t_data *data)
{ 
    int i;

    i = -1;
    while (++i < data->n_philo)
    {
        data->philo[i].data = data;
        data->philo[i].id = i + 1;
        data->philo[i].meals_counter = 0;
        //data->philo->left_fork = &data->forks[i];
        //data->philo->right_fork = &data->forks[(i + 1) % data->n_philo];
        data->philo[i].status = NTHG;
        pthread_mutex_init(&data->philo[i].time, NULL);
        pthread_mutex_init(&data->philo[i].time_lock, NULL);
        pthread_mutex_init(data->philo[i].left_fork, NULL);
        //printf("hello\n");
       // pthread_mutex_init(data->philo[i].right_fork, NULL);
        //pthread_mutex_init(&data->philo[i].eat_lock, NULL);
        pthread_mutex_init(&data->philo[i].think_lock, NULL);
        pthread_mutex_init(&data->philo[i].sleep_lock, NULL);
        pthread_mutex_init(&data->philo[i].get_status_lock, NULL);
        pthread_mutex_init(&data->philo[i].set_status_lock, NULL);
        pthread_mutex_init(&data->philo[i].write_lock, NULL);
        pthread_mutex_init(&data->philo[i].check_lock, NULL);
    }
}
