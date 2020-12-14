/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:57:41 by atomatoe          #+#    #+#             */
/*   Updated: 2020/12/15 02:50:28 by atomatoe         ###   ########.fr       */
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
    //  std::cout << std::endl;
    //  std::cout << "| MY STACK: |" << std::endl;
    //  ft::stack<int> my;
    //  my.push(10);
    //  my.pop();
    //  my.push(20);
    //  my.push(30);
    //  my.push(40);
    //  my.push(50);
    //  my.pop();
    //  std::cout << "my size: " << my.size() << std::endl;
    //  std::cout << "my top: " << my.top() << std::endl;
    //  ft::stack<int> my2;
    //  if(my > my2)
    //      std::cout << "TESTING" << std::endl;
    //  std::cout << std::endl;
    //  std::cout << "| STANDART STACK: |" << std::endl;
    //  std::stack<int> standart;
    //  standart.push(10);
    //  standart.pop();
    //  standart.push(20);
    //  standart.push(30);
    //  standart.push(40);
    //  standart.push(50);
    //  standart.pop();
    //  std::cout << "st size: " << standart.size() << std::endl;
    //  std::cout << "st top: " << standart.top() << std::endl;
    //  std::stack<int> standart2;
    //  if(standart > standart2)
    //      std::cout << "TESTING" << std::endl;
    //  std::cout << std::endl;



    //  std::cout << std::endl;
    //  std::cout << "| MY QUEUE: |" << std::endl;
    //  ft::queue<int> my;
    //  my.push(10);
    //  my.pop();
    //  my.push(20);
    //  my.push(30);
    //  my.push(40);
    //  my.push(50);
    //  my.pop();
    //  std::cout << "my size: " << my.size() << std::endl;
    //  ft::queue<int> my2;
    //  if(my > my2)
    //      std::cout << "TESTING" << std::endl;
    //  std::cout << std::endl;
    //  std::cout << "| STANDART QUEUE: |" << std::endl;
    //  std::queue<int> standart;
    //  standart.push(10);
    //  standart.pop();
    //  standart.push(20);
    //  standart.push(30);
    //  standart.push(40);
    //  standart.push(50);
    //  standart.pop();
    //  std::cout << "st size: " << standart.size() << std::endl;
    //  std::queue<int> standart2;
    //  if(standart > standart2)
    //      std::cout << "TESTING" << std::endl;
    //  std::cout << std::endl;


    std::cout << std::endl;
    std::cout << "| MY LIST: |" << std::endl;
    ft::list<int> my;
    my.push_back(1);
    my.push_back(5);
    my.push_back(10);
    std::cout << "my: " << std::endl;
    my.my_print();
    std::cout << "size: " << my.size() << std::endl;

    std::list<int> test;
    test.push_back(12);
    std::list<int>::iterator myIter = test.begin();
    // std::cout << myIter << std::endl;

    // std::cout << "TEST: " << std::endl;
    // ft::list<int>test(my);
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
