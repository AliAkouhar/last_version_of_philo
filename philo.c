/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:16:29 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/26 13:41:17 by ali-akouhar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_init_args(char **av, t_data *data)
{
    data->death_flag = 1;
    data->meal_finish = 0;
    data->n_philo = ft_atol(av[1]);
    data->t_die = ft_atol(av[2]);
    data->t_eat = ft_atol(av[3]);
    data->t_sleep = ft_atol(av[4]);
    if (av[5])
        data->num_meals = ft_atol(av[5]);
    else
        data->num_meals = -1;
}

int ft_create_philos(t_data *data)
{
    int i;
    
    i = -1;
    while (++i < data->n_philo)
    {
        if (pthread_create(&data->philo[i].th, NULL, routine, &data->philo[i]))
            return (1);
    }
    if (data->n_philo >= 0)
        if (pthread_create(&data->death_monitore, NULL, check_death, data))
            return (1);
    if (data->num_meals != -1)
        if (pthread_create(&data->meals_monitore, NULL, check_meals, data))
            return (1);
    if (check_all(data))
        return (1);
    return (0);
}

int ft_join(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->n_philo)
    {
        if (pthread_join(data->philo[i].th, NULL))
            return (1);
    }
    if (data->n_philo >= 0)
        if (pthread_join(data->death_monitore, NULL))
            return (1);
    if (data->num_meals >= 0)
    {
        if (pthread_join(data->meals_monitore, NULL))
            return (1);
    }
    return (0);
}

int ft_alloc(t_data *data)
{
    data->philo = malloc(sizeof(t_philo) * data->n_philo);
    if (!data->philo)
        return (1);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
    if (!data->forks)
        return (1);
    return (0);
}

int     ft_init(char **av, t_data *data)
{
    
    ft_init_args(av, data);
    if (ft_alloc(data))
        return (1);
    if (ft_create_forks(data))
        return (1);
    ft_init_philo(data);
    if (ft_create_philos(data))
        return (1);
    if (ft_join(data))
        return (1);
    return (0);
}