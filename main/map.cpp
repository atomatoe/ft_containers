/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:30 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/29 19:21:46 by atomatoe         ###   ########.fr       */
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

    for(int t = 1; t != 15; t++)
        my.insert(std::make_pair(t, t));

    for(int t = 1; t != 15; t++)
        test.insert(std::make_pair(t, t));

    my.erase(10);
    my.erase(7);
    ft::map<int, int>::iterator my_i = my.upper_bound(71);
    std::cout << "lower_bound = " << (*my_i).first << std::endl;
    // ft::map<int, int>::iterator my_i = my.end();
    // my_i--;
    // my_i--;
    // my.erase(my_i);
    // std::map<int, int>::iterator test_i = test.end();
    // test_i--;
    // test_i--;
    // test.erase(test_i);

    // // ft::map<int, int>::iterator my_i = my.end();
    // my.erase(5);
    // my.erase(7);
    // my.erase(8);
    // my.erase(9);
    // // std::map<int, int>::iterator test_i = test.end();
    // test.erase(5);
    // test.erase(7);
    // test.erase(8);
    // test.erase(9);

    // ---------  вывод
    for(ft::map<int, int>::iterator my_i = my.begin(); my_i != my.end(); my_i++)
        std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my.size() << std::endl;
    // for(ft::map<int, int>::iterator my_i = my2.begin(); my_i != my2.end(); my_i++)
    //     std::cout << (*my_i).second << std::endl;
    
    // std::cout << std::endl;

    // for(std::map<int, int>::iterator test_i = test.begin(); test_i != test.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // for(std::map<int, int>::iterator test_i = test2.begin(); test_i != test2.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test.size() << std::endl;
    return(0);
}
