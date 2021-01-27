/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:30 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/27 03:10:42 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.hpp"
#include <map>
#include <unistd.h>
#include <iostream>

int main()
{
    ft::map<int, int>my;
    // std::map<int, int>test;

    // my.insertNode(10);
    // my.insertNode(9);
    // my.insertNode(11);
    // my.insertNode(12);
    // my.insertNode(8);
    // my.insertNode(13);
    // my.insertNode(5);
    // my.insertNode(2);
    // my.insertNode(141);


    // my.insertNode(50);
    // my.insertNode(100);
    // my.insertNode(150);
    my.insert(std::make_pair(10, 10));
    my.insert(std::make_pair(8, 8));
    my.insert(std::make_pair(6, 6));
    my.insert(std::make_pair(12, 12));
    my.insert(std::make_pair(2, 2));
    ft::map<int, int>::iterator my_i = my.end();
    my_i++;
    // my.erase(my_i);
    // my.insert(std::make_pair(8, 23));
    // my.insert(std::make_pair(12, 233));
    // my.insert(std::make_pair(6, 122));
    // my.insert(std::make_pair(16, 511));
    // test.insert(std::make_pair(1, 7));
    // test.insert(test.begin(), p1);
    // std::pair<const key_t, int> p3(1, 5);
    // std::cout << "first = " << p3.first << std::endl;
    // std::cout << "second = " << p3.second << std::endl;
    for(ft::map<int, int>::iterator my_i = my.begin(); my_i != my.end(); my_i++)
        std::cout << *my_i << std::endl;
    std::cout << *my.end() << std::endl;
    std::cout << "size = " << my.size() << std::endl;
    // for(std::map<int, int>::iterator test_i = test.begin(); test_i != test.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // sleep(100);
    return(0);
}
