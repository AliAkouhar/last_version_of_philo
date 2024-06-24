/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:43:58 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/24 17:55:32 by ali-akouhar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_death(t_philo *philo)
{
    pthread_mutex_lock(&philo->check_lock);
    if (philo->status == DIED)
    {
        pthread_mutex_unlock(&philo->check_lock);
        return (1);
    }
    else if (philo->status != EATING && (get_time() - philo->expected_time) >= philo->data->t_die)
    {
        set_status(philo, DIED);
        pthread_mutex_unlock(&philo->check_lock);
        return (1)
    }
    pthread_mutex_unlock(&philo->check_lock);
    return (0);
}

void    go_kill_all(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->n_philo)
        set_satus(&data->philo[i], DIED);
}

void    *check_death(void *p)
{
    t_data  *data;
    int     i;

    data = (t_data *)p;
    while (data->death_flag)
    {
        i = -1;
        while (++i < data->n_philo && data->philo[++i].status != DIED)
        {
            if (is_death(&data->philo[i]))
            {
                ft_printf("is died\n", &data->philo[i]);
                go_kill_all(data);
                data->death_flag = 0;
                break ;
            }
        }
    }
    return (NULL);
}

void    *check_meals(void   *p)
{
    t_data  *data;
    int     i;
    int     count;
    
    data = (t_data *)p;
    i = -1;
    count = 0;
    while (++i < data->n_philo && data->death_flag)
    {
        if (data->philo[i].meals_counter = data->num_meals)
            count++;
        if (count == data->n_philo)
        {
            go_kill_all(data);
            data->death_flag = 0;
            break ;
        }
        if (i == data->n_philo)
        {
            i = -1;
            count = 0;
        }
        usleep(1000);
    }
    return (NULL);
}