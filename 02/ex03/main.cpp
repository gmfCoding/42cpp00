/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:59:28 by clovell           #+#    #+#             */
/*   Updated: 2024/03/02 19:21:11 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

void testPoint(const Point a, const Point b, const Point c, const Point v)
{
    std::cout << a << b << c << ":" << v;
    std::cout << " = " << bsp(a, b, c, v) << std::endl;
}

int main( void ) {

    testPoint( Point(-1, -1), Point(-1, 1), Point(1,1), Point(0, 0));
    return 0;
}