/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:10:00 by aakouhar          #+#    #+#             */
/*   Updated: 2024/06/27 17:00:32 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned long long get_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL))
        return (printf("error from get time of day\n"));
    return ((unsigned long long)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int    ft_usleep(size_t milliseconds)
{
    long long    start;

    start = get_time();
    while ((size_t)(get_time() - start) < milliseconds)
        usleep(100);
    return (0);
}
