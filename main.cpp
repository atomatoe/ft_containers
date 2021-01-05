/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:57:41 by atomatoe          #+#    #+#             */
/*   Updated: 2020/12/18 19:53:16 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "vector.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "list.hpp"
#include <vector>
#include <stack>
#include <list>
#include <queue>
#include <unistd.h>

int main()
{
    std::cout << std::endl;
    std::cout << "| MY LIST: |" << std::endl;
    ft::list<int> my;
    ft::list<int> my2;
    my.push_back(1);
    my.push_back(2);
    my.push_back(3);
    my.push_back(4);
    my.push_back(5);
	my2.push_back(6);
	my2.push_back(7);
	my2.push_back(8);
	my2.push_back(9);
	ft::list<int>::iterator itT2 = my.begin();
    itT2++;
    itT2++;
	ft::list<int>::iterator itT3 = my2.begin();
    itT3++;
	my.insert(itT2, itT3, my2.end());
	my.my_print();
	std::cout << std::endl;
	my2.my_print();
 	// for(ft::list<int>::iterator it4 = my.begin(); it4 != my.end(); it4++)
	// 	std::cout << *it4 << std::endl;
	// std::cout << std::endl;
	// for(ft::list<int>::iterator it5 = my2.begin(); it5 != my2.end(); it5++)
	// 	std::cout << *it5 << std::endl;

    // my.my_print();
    std::list<int> test;
	std::list<int> test2;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
	test2.push_back(6);
	test2.push_back(7);
	test2.push_back(8);
	test2.push_back(9);
    std::cout << "TEST: " << std::endl;
	std::list<int>::iterator itTest = test.begin();
    itTest++;
    itTest++;
    std::list<int>::iterator itTest2 = test2.begin();
    itTest2++;
	test.insert(itTest, itTest2, test2.end());
	for(std::list<int>::iterator it2 = test.begin(); it2 != test.end(); it2++)
		std::cout << *it2 << std::endl;
	std::cout << std::endl;
	for(std::list<int>::iterator it3 = test2.begin(); it3 != test2.end(); it3++)
		std::cout << *it3 << std::endl;
    // std::cout << "orig: " << *itTest << std::endl;
	// sleep(100);
    // std::cout << test.size() << std::endl;
    //  my.push_back(30);
    //  my.push_back(40);
    //  my.push_back(50);
    //  my.pop_back();
    //  std::cout << "my size: " << my.size() << std::endl;
    //  ft::list<int> my2;
    //  if(my > my2)
    //      std::cout << "TESTING" << std::endl;



    // std::cout << std::endl;
    // std::cout << "| STANDART LIST: |" << std::endl;
    // std::list<int> standart;
    // my.push_back(20);
    // standart.push_back(10);
    // //  standart.pop_back();
    // standart.push_back(20);
    // standart.push_back(20);
    // std::cout << standart.size() << std::endl;
    // //  standart.push_back(30);
    // //  standart.push_back(40);
    // //  standart.push_back(50);
    // //  standart.pop_back();
    // //  std::cout << "st size: " << standart.size() << std::endl;
    // //  std::list<int> standart2;
    // //  if(standart > standart2)
    // //      std::cout << "TESTING" << std::endl;
    //  std::cout << std::endl;






}
