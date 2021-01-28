/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:30 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/29 01:49:53 by atomatoe         ###   ########.fr       */
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


    ft::map<int, int>my2;
    for(int t = 16; t != 25; t++)
        my2.insert(std::make_pair(t, t));
    ft::map<int, int>::iterator my_i = my2.begin();
    ft::map<int, int>::iterator my_i2 = my2.begin();
    my_i++;
    my_i++;
    my_i2++;
    my_i2++;
    my_i2++;
    my_i2++;
    my_i2++;
    my_i2++;
    my.insert(my_i, my_i2); // бесконечный цикл

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
        std::cout << *my_i << std::endl;
    std::cout << "size = " << my.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test.begin(); test_i != test.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test.size() << std::endl;
    return(0);
}
