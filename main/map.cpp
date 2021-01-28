/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:30 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/28 16:28:26 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.hpp"
#include <map>
#include <unistd.h>
#include <iostream>

int main()
{
    ft::map<int, int>my;
    std::map<int, int>test;

    my.insert(std::make_pair(10, 10));
    my.insert(std::make_pair(8, 8));
    my.insert(std::make_pair(6, 6));
    my.insert(std::make_pair(4, 4));
    my.insert(std::make_pair(2, 2));
    my.insert(std::make_pair(12, 12));
    my.insert(std::make_pair(14, 14));
    my.insert(std::make_pair(16, 16));
    my.insert(std::make_pair(18, 18));
    my.insert(std::make_pair(20, 20));
    my.insert(std::make_pair(1, 1));
    my.insert(std::make_pair(21, 21));
    my.insert(std::make_pair(22, 22));
    my.insert(std::make_pair(24, 24));
    my.insert(std::make_pair(26, 26));
    my.insert(std::make_pair(29, 29));
    my.insert(std::make_pair(30, 30));
    my.insert(std::make_pair(32, 32));

    ft::map<int, int>::iterator my_i = my.begin();
    my_i++;
    std::cout << *my_i << std::endl;
    ft::map<int, int>::iterator my_i2 = my.end();
    my_i2--;
    std::cout << *my_i2 << std::endl;
    // ---------  вывод
    // for(ft::map<int, int>::iterator my_i = my.begin(); my_i != my.end(); my_i++)
    //     std::cout << *my_i << std::endl;
    // std::cout << "size = " << my.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test.begin(); test_i != test.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test.size() << std::endl;
    return(0);
}
