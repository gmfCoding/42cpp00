/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:00:04 by clovell           #+#    #+#             */
/*   Updated: 2024/03/09 17:20:45 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    const Point v1 = b - a;
    const Point v2 = c - b;
    const Point v3 = a - c;
    
    const float p1 = v1.Det(point - a);
    const float p2 = v2.Det(point - b);
    const float p3 = v3.Det(point - c);
    return (p1 * p2 > 0 && p1 * p3 > 0);
}