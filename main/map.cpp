/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:30 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/27 22:45:47 by atomatoe         ###   ########.fr       */
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
    test.insert(std::make_pair(10, 10));
    test.insert(std::make_pair(8, 8));
    test.insert(std::make_pair(6, 6));
    test.insert(std::make_pair(4, 4));
    test.insert(std::make_pair(2, 2));
    test.insert(std::make_pair(12, 12));
    test.insert(std::make_pair(14, 14));
    test.insert(std::make_pair(16, 16));
    test.insert(std::make_pair(18, 18));
    // my.insert(std::make_pair(50, 50));
    // for(int t = 49; t != 45; t--)
    //     my.insert(std::make_pair(t, t));
    // for(int t = 51; t != 55; t++)
    //     my.insert(std::make_pair(t, t));
    // test.insert(std::make_pair(50, 50));
    // for(int t = 49; t != 45; t--)
    //     test.insert(std::make_pair(t, t));
    // for(int t = 51; t != 55; t++)
    //     test.insert(std::make_pair(t, t));
    std::cout << "my: " << *my.end() << std::endl;
    std::map<int, int>::iterator test_i = test.end();
    test_i--;
    std::cout << "orig: " << test_i->second << std::endl;
    // std::map<int, int>::iterator test_i = test.upper_bound(49);
    //     std::cout << "test orig : " << test_i->second << std::endl;
    // ft::map<int, int>::iterator my_i = my.upper_bound(49);
    //     std::cout << "test my : " << *my_i << std::endl;

    // ---------  вывод
    // for(ft::map<int, int>::iterator my_i = my.begin(); my_i != my.end(); my_i++)
    //     std::cout << *my_i << std::endl;
    // std::cout << *my.end() << std::endl;
    // std::cout << "size = " << my.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test.begin(); test_i != test.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test.size() << std::endl;
    return(0);
}
