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
    my.push_back(5);
    my.push_back(6);
    my.push_back(7);
    my.push_back(8);
    my.push_back(9);
	my2.push_back(11);
	my2.push_back(12);
	my2.push_back(13);
	my2.push_back(14);
	ft::list<int>::iterator itT1 = my.begin();
	itT1++;
	itT1++;
	my.erase(itT1, my.end());
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
    test.push_back(5);
    test.push_back(6);
    test.push_back(7);
    test.push_back(8);
    test.push_back(9);
	test2.push_back(11);
	test2.push_back(12);
	test2.push_back(13);
	test2.push_back(14);
    std::cout << "TEST: " << std::endl;
	std::list<int>::iterator itT = test.begin();
	// itT2--;
	itT++;
	itT++;
	test.erase(itT, test.end());
	// std::list<int>::iterator itTest = test.begin();
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
