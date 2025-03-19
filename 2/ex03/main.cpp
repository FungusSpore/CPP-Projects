/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:57:48 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/20 01:30:04 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main(void){
    // Test Case 1: Point inside the triangle
    std::cout << "Test 1: " << bsp(Point(-10, 0), Point(10, 0), Point(0, 10), Point(0, 1)) << std::endl;

    // Test Case 2: Point outside the triangle (on the boundary)
    std::cout << "Test 2: " << bsp(Point(-10, 0), Point(10, 0), Point(0, 10), Point(0, 0)) << std::endl;

   // Test Case 3: Point inside the triangle
    std::cout << "Test 3: " << bsp(Point(-10, 0), Point(10, 0), Point(0, 10), Point(5, 2)) << std::endl;

    // Test Case 4: Point outside the triangle (left side)
    std::cout << "Test 4: " << bsp(Point(-10, 0), Point(10, 0), Point(0, 10), Point(-5, 5)) << std::endl;

    // Test Case 5: Point outside the triangle (right side)
    std::cout << "Test 5: " << bsp(Point(-10, 0), Point(10, 0), Point(0, 10), Point(6, 6)) << std::endl;

    // Test Case 6: Point inside a different triangle
    std::cout << "Test 6: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(1, 1)) << std::endl;

    // Test Case 7: Point outside a different triangle
    std::cout << "Test 7: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(6, 6)) << std::endl;

    // Test Case 8: Point exactly on the edge of the triangle
    std::cout << "Test 8: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(5, 0)) << std::endl;

    // Test Case 9: Point exactly on the vertex of the triangle
    std::cout << "Test 9: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(0, 0)) << std::endl;

}
