/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:48:27 by aakouhar          #+#    #+#             */
/*   Updated: 2024/06/27 17:01:34 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>


long	ft_atol(char *str);
unsigned long long get_time(void);
int    ft_usleep(size_t milliseconds);

#endif