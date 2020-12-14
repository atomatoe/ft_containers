/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:57:41 by atomatoe          #+#    #+#             */
/*   Updated: 2020/12/14 15:58:06 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"
#include "list.hpp"
#include <vector>
#include <stack>
#include <list>

int main()
{
     std::cout << std::endl;
     std::cout << "| MY STACK: |" << std::endl;
     ft::stack<int> my;
     my.push(10);
     my.pop();
     my.push(20);
     my.push(30);
     my.push(40);
     my.push(50);
     my.pop();
     std::cout << "my size: " << my.size() << std::endl;
     std::cout << "my top: " << my.top() << std::endl;
     ft::stack<int> my2;
     if(my > my2)
         std::cout << "TESTING" << std::endl;
     std::cout << std::endl;
     std::cout << "| STANDART STACK: |" << std::endl;
     std::stack<int> standart;
     standart.push(10);
     standart.pop();
     standart.push(20);
     standart.push(30);
     standart.push(40);
     standart.push(50);
     standart.pop();
     std::cout << "st size: " << standart.size() << std::endl;
     std::cout << "st top: " << standart.top() << std::endl;
     std::stack<int> standart2;
     if(standart > standart2)
         std::cout << "TESTING" << std::endl;
     std::cout << std::endl;


    std::cout << std::endl;


    // std::cout << "| MY LIST: |" << std::endl;
    // ft::List<int> my;
    // my.push(10);
    // my.pop();
    // my.push(20);
    // my.push(30);
    // my.push(40);
    // my.push(50);
    // my.pop();
    // std::cout << "my size: " << my.size() << std::endl;
    // std::cout << "my top: " << my.top() << std::endl;
    // ft::Stack<int> my2;
    // if(my < my2)
    //     std::cout << "TESTING" << std::endl;



    // std::cout << std::endl;



    // std::cout << "| STANDART LIST: |" << std::endl;
    // std::list<int> standart;
    // standart.push(10);
    // standart.pop();
    // standart.push(20);
    // standart.push(30);
    // standart.push(40);
    // standart.push(50);
    // standart.pop();
    // std::cout << "st size: " << standart.size() << std::endl;
    // std::cout << "st top: " << standart.top() << std::endl;
    // std::stack<int> standart2;
    // if(standart < standart2)
    //     std::cout << "TESTING" << std::endl;


    // std::cout << std::endl;
}




    // name.push_back(50);
    // name.push_back(60);
    // name.push_back(70);
    // name.pop_back();
    // name.assign(2, 52);
    // name.push_back(60);
    // name.push_back(70);
    // std::cout << "vector size: " << name.size() << std::endl;
    // // std::cout << "vector max size: " << name.max_size() << std::endl;
    // std::cout << "vector empty: " << name.empty() << std::endl;
    // // std::cout << "capacity: " << name.capacity() << std::endl;
    // std::cout << "standart vector: " << std::endl;
    // // name.clear();
    // for(std::vector<int>::iterator i = name.begin(); i != name.end(); i++)
    //     std::cout << *i << std::endl;
    // std::vector<int> name3(5);;