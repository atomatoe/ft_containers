/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:26:04 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/19 18:29:32 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.hpp"
#include "../includes/queue.hpp"
#include "../includes/deque.hpp"
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
    std::cout << "| MY DEQUE: |" << std::endl;
    ft::deque<int> my;
    my.push_back(5);
    my.push_back(7);
    my.push_back(8);
    my.assign((size_t)2, 12);

    my.my_print();



    //
    //
	std::cout << std::endl;
    //
    //



    std::cout << "| ORIG DEQUE: |" << std::endl;
    std::deque<int> test;
    test.push_back(5);
    test.push_back(7);
    test.push_back(8);
    test.assign((size_t)2, 12);

    for(std::deque<int>::iterator it2 = test.begin(); it2 != test.end(); it2++)
		std::cout << *it2 << std::endl;
    std::cout << "orig size = " << test.size() << std::endl;

    // sleep(100);
    return(0);
}