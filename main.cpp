/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:57:41 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/19 00:54:38 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "queue.hpp"
#include "list.hpp"
#include "vector.hpp"
#include <vector>
#include <stack>
#include <list>
#include <queue>
#include <unistd.h>

int main()
{
    std::cout << std::endl;
    std::cout << "| MY VECTOR: |" << std::endl;
    ft::vector<int> my;
    my.push_back(1);
    my.push_back(2);
    my.push_back(3);
    ft::vector<int>::iterator myIT = my.begin();
    myIT++;
    std::cout << "test = " << *myIT << std::endl;

    my.my_print();


	std::cout << std::endl;


    std::cout << "| ORIG VECTOR: |" << std::endl;

    std::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
  
	for(std::vector<int>::iterator it2 = test.begin(); it2 != test.end(); it2++)
		std::cout << *it2 << std::endl;
    std::cout << "orig size = " << test.size() << std::endl;
    std::cout << "orig capasity = " << test.capacity() << std::endl;

    // sleep(100);
    return(0);
}
