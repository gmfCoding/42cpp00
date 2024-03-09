/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:59:28 by clovell           #+#    #+#             */
/*   Updated: 2024/03/09 17:23:45 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

const std::string pass_fail(bool expect)
{
    return (expect ? "passed" : "failed");
}

const std::string in_out(bool expect)
{
    return (expect ? "in" : "out");
}

void testPoint(const Point a, const Point b, const Point c, const Point v, bool expect)
{
    std::cout << a << b << c << ":" << v << std::endl;
    std::cout << "[" << pass_fail(bsp(a, b, c, v) == expect);
    std::cout << "] expected: " << in_out(expect) << " got: " << in_out(bsp(a, b, c, v)) << std::endl;
}

int main( void ) {

    testPoint(Point(-1, -1), Point(-1, 1), Point(1,0), Point(0.99, 0), true);
    testPoint(Point(1.28, 1.03), Point(-0.95, 0.47), Point(-1.2, 1.8), Point(-0.42, 1.13), true);
    testPoint(Point(1.28, 1.03), Point(1.2, 3.4), Point(-1.2, 1.8), Point(-0.42, 1.13), false);
    testPoint(Point(1.28, 1.03), Point(1.2, 3.4), Point(-1.2, 1.8), Point(0.085, 1.54), true);
    testPoint(Point(2.07, -4.1), Point(-4.22, -3.91), Point(-4.73, -0.93), Point(5.05, 3.97), false);
    testPoint(Point(0, 0), Point(0, 10), Point(10, 0), Point(5, 0), false);
    testPoint(Point(0, 0), Point(0, 10), Point(10, 0), Point(5, 0.1), true);
    testPoint(Point(0, 0), Point(2, 0), Point(0, 4), Point(1, 2), false);
    testPoint(Point(0, 0), Point(2, 0), Point(0, 4), Point(1, 1.9), true);

    return 0;
}