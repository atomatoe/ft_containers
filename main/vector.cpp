/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:26:12 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/19 17:26:12 by atomatoe         ###   ########.fr       */
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
    my.push_back(4);
    my.push_back(5);
    my.push_back(6);

    ft::vector<int>::iterator myIT = my.begin();
    ft::vector<int>::iterator myIT2 = my.begin();
    myIT++;
    myIT++;
    myIT2++;
    myIT2++;
    myIT2++;
    myIT2++;
    my.insert(myIT, (size_t)5, 43);
    // std::cout << "test = " << *myIT << std::endl;

    my.my_print();


	std::cout << std::endl;


    std::cout << "| ORIG VECTOR: |" << std::endl;

    std::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);

    std::vector<int>::iterator tt = test.begin();
    std::vector<int>::iterator tt2 = test.begin();
    tt++;
    tt++;
    tt2++;
    tt2++;
    tt2++;
    tt2++;
    test.insert(tt, (size_t)5, 43);
	for(std::vector<int>::iterator it2 = test.begin(); it2 != test.end(); it2++)
		std::cout << *it2 << std::endl;
    std::cout << "orig size = " << test.size() << std::endl;
    std::cout << "orig capasity = " << test.capacity() << std::endl;

    // sleep(100);
    return(0);
}