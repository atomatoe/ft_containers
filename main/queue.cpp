/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:26:07 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/23 21:53:52 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.hpp"
#include "../includes/queue.hpp"
#include "../includes/list.hpp"
#include "../includes/vector.hpp"
#include <vector>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <unistd.h>

int main()
{
    std::cout << std::endl;
	std::cout << "|___________________________|" << std::endl;
	std::cout << "|                           |" << std::endl;
	std::cout << "|     TEST queue START!     |" << std::endl;
	std::cout << "|___________________________|" << std::endl;
	std::cout << "| func |           | result |" << std::endl;
	std::cout << "|______|___________|________|" << std::endl;
	std::cout << std::endl;
	//********************************************************
    ft::queue<int> my;
    std::queue<int> test;
	if(my.empty() == true && test.empty() == true && my.size() == test.size())
		std::cout << "empty and size - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "empty and size - | \x1B[31mKO\x1B[0m |" << std::endl;
    my.push(13);
    my.push(15);
    my.push(22);
    test.push(13);
    test.push(15);
    test.push(22);
    if(my.front() == test.front())
        std::cout << "front | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "front | \x1B[31mKO\x1B[0m |" << std::endl;
    if(my.back() == test.back())
        std::cout << "back | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "back | \x1B[31mKO\x1B[0m |" << std::endl;
	if(my.empty() == false && test.empty() == false && my.size() == test.size())
		std::cout << "push - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "push - | \x1B[31mKO\x1B[0m |" << std::endl;
    my.pop();
    my.pop();
    test.pop();
    test.pop();
	if(my.empty() == false && test.empty() == false && my.size() == test.size())
		std::cout << "pop - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "pop - | \x1B[31mKO\x1B[0m |" << std::endl;
    if(my.size() == test.size())
		std::cout << "size = | \x1B[32m" << my.size() << "\x1B[0m | " << std::endl;
	else
		std::cout << "size = | \x1B[31m" << my.size() << "\x1B[0m |" << std::endl;
    ft::queue<int> my2;
    std::queue<int> test2;
    my2.push(13);
    my2.push(15);
    my2.push(22);
    test2.push(13);
    test2.push(15);
    test2.push(22);
    if(my < my2)
        std::cout << "operator < | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "operator < | \x1B[31mKO\x1B[0m |" << std::endl;
    my.push(15);
    my.push(22);
    if(my == my2)
        std::cout << "operator == | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "operator == | \x1B[31mKO\x1B[0m |" << std::endl;
    return(0);
}