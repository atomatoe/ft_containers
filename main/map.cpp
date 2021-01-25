/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:30 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/25 18:03:23 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.hpp"
#include <map>
#include <unistd.h>
#include <iostream>

int main()
{
    std::pair <int, int> p1 (1, 15);
    ft::map<int, int>my;
    std::map<int, int>test;

    my.insertNode(10);
    my.insertNode(9);
    my.insertNode(11);
    my.insertNode(12);
    my.insertNode(8);
    my.insertNode(13);
    my.insertNode(5);
    my.insertNode(2);
    my.insertNode(141);
    my.insertNode(232);

  
    for(ft::map<int, int>::iterator my_i = my.begin(); my_i != my.end(); my_i++)
        std::cout << *my_i << std::endl;
    for(std::map<int, int>::iterator test_i = test.begin(); test_i != test.end(); test_i++)
        std::cout << test_i->second << std::endl;
    return(0);
}