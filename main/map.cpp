/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:30 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/24 21:36:48 by atomatoe         ###   ########.fr       */
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
    my.insertNode(15);
    my.insertNode(22);
    my.my_print();
    return(0);
}