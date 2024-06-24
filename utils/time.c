/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:10:00 by aakouhar          #+#    #+#             */
/*   Updated: 2024/06/05 16:39:37 by ali-akouhar      ###   ########.fr       */
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
