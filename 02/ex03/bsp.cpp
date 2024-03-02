/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:00:04 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:00:04 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    const Point &v0 = a;
    const Point v1 = b - a;
    const Point v2 = c - a;

    const float A = (point.Det(v2) - v0.Det(v2)) / v1.Det(v2);
    const float B = (point.Det(v1) - v0.Det(v1)) / v1.Det(v2);
    return (A > 0 && B > 0 && A + B < 1);
}