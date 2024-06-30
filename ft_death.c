/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:43:58 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/30 15:19:10 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_death(t_philo *philo)
{
    if (get_status(philo) == DIED)
    {
        // pthread_mutex_unlock(&philo->data->time_lock);
        // pthread_mutex_lock(&philo->data->death_lock);
        // philo->data->death_flag = 0;
        // pthread_mutex_unlock(&philo->data->death_lock);
        return (1);
    }  
    pthread_mutex_lock(&philo->data->time_lock);
    if (get_status(philo) != EATING && (get_time() - philo->last_meal > philo->data->t_die))
    {
        // printf("fark %llu\n", get_time() - philo->last_meal);
        set_status(philo, DIED);
        pthread_mutex_unlock(&philo->data->time_lock);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->time_lock);
    return (0);
}

void    go_kill_all(t_data *data)
{
    int i;

    i = -1;
    set_value(data, 0);
    while (++i < data->n_philo)
    {
        // if (pthread_mutex_lock(data->philo[i].left_fork))
        //     pthread_mutex_unlock(data->philo[i].left_fork);
        // else
        //     pthread_mutex_unlock(data->philo[i].left_fork);
        // if (pthread_mutex_lock(data->philo[i].right_fork))
        //     pthread_mutex_unlock(data->philo[i].right_fork);
        // else
        //     pthread_mutex_unlock(data->philo[i].right_fork);
        set_status(&data->philo[i], DIED);
    }
}

void    *check_death(void *p)
{
    t_data  *data;
    int     i;

    data = (t_data *)p;
    i = 0;
    while (i < data->n_philo && data->n_philo != 1)
    {
        if (is_death(&data->philo[i]))
        {
            ft_printf("died\n", &data->philo[i]);
            go_kill_all(data);
            break ;  
        }
        i++;
        if (i == data->n_philo)
            i = 0;
        usleep(1000);
    }    
    return (NULL);
}

void    *check_meals(void   *p)
{
    t_data  *data;
    int     i;
    int     count;
    
    data = (t_data *)p;
    i = 0;
    count = 0;
    while (i < data->n_philo)
    {
        pthread_mutex_lock(&data->eat_lock);
        if (data->philo[i].meals_counter >= (long)data->num_meals)
            count++;
        pthread_mutex_unlock(&data->eat_lock);    
        if (count == data->n_philo)
        {
            printf("compliting meals\n");
            set_finish(data, 1);
            go_kill_all(data);
            break ;
        }
        i++;
        if (i == data->n_philo)
        {
            i = 0;
            count = 0;
        }
        usleep(1000);
    }
    return (NULL);
}