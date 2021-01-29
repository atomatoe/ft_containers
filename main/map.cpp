/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:30 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/30 02:30:25 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.hpp"
#include <map>
#include <unistd.h>
#include <iostream>

int main()
{
	std::cout << std::endl;
	std::cout << "|___________________________|" << std::endl;
	std::cout << "|                           |" << std::endl;
	std::cout << "|     TEST map START!      |" << std::endl;
	std::cout << "|___________________________|" << std::endl;
	std::cout << "| func |           | result |" << std::endl;
	std::cout << "|______|___________|________|" << std::endl;
	std::cout << std::endl;
	//********************************************************
    ft::map<int, int>my;
    std::map<int, int>test;
	if(my.size() == test.size())
		std::cout << "Создание пустого контейнера - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Создание пустого контейнера - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
    // for(ft::map<int, int>::iterator my_i = my.begin(); my_i != my.end(); my_i++)
        // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test.begin(); test_i != test.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test.size() << std::endl;
	//********************************************************
	for(int t = 1; t != 15; t++)
        my.insert(std::make_pair(t, t));
	for(int t = 1; t != 15; t++)
        test.insert(std::make_pair(t, t));
	ft::map<int, int>::iterator it = my.begin();
	ft::map<int, int>::iterator ite = my.end();
	std::map<int, int>::iterator its = test.begin();
	std::map<int, int>::iterator ites = test.end();
	ft::map<int, int>my2(it, ite);
    std::map<int, int>test2(its, ites);
	if(my2.size() == test2.size())
		std::cout << "Создание контейнера по итератору - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Создание контейнера по итератору - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
    // for(ft::map<int, int>::iterator my_i = my2.begin(); my_i != my2.end(); my_i++)
        // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my2.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test2.begin(); test_i != test2.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test2.size() << std::endl;
	//********************************************************
	ft::map<int, int>my3(my2);
    std::map<int, int>test3(test2);
	if(my3.size() == test3.size())
		std::cout << "Конструктор копирования - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Конструктор копирования - | \x1B[31mKO\x1B[0m |" << std::endl;
	ft::map<int, int>my15;
    std::map<int, int>test15;
	ft::map<int, int>my14(my15);
    std::map<int, int>test14(test15);
	if(my14.size() == test14.size())
		std::cout << "Конструктор копирования пустого контейнера - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Конструктор копирования пустого контейнера - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// for(ft::map<int, int>::iterator my_i = my3.begin(); my_i != my3.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my3.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test3.begin(); test_i != test3.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test3.size() << std::endl;
	//********************************************************
	ft::map<int, int>my4 = my3;
    std::map<int, int>test4 = test3;
	if(my3.size() == test3.size())
		std::cout << "Оператор присваивания - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Оператор присваивания - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// for(ft::map<int, int>::iterator my_i = my4.begin(); my_i != my4.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my4.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test4.begin(); test_i != test4.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test4.size() << std::endl;
	//********************************************************
	it = my4.begin();
	its = test4.begin();
	if(its->first == it->first)
		std::cout << "begin - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "begin - | \x1B[31mKO\x1B[0m |" << std::endl;
	it = my4.end();
	its = test4.end();
	if(its->first == it->first)
		std::cout << "end - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "end - | \x1B[31mKO\x1B[0m |" << std::endl;
	ft::map<int, int>::reverse_iterator it2 = my4.rbegin();
	std::map<int, int>::reverse_iterator its2 = test4.rbegin();
	if(its2->first == it2->first)
		std::cout << "reverse rbegin - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "reverse rbegin - | \x1B[31mKO\x1B[0m |" << std::endl;
    ft::map<int, int> const my11(my);
    std::map<int, int> const test11(test);
	ft::map<int, int>::const_iterator const it11 = my11.begin();
	std::map<int, int>::const_iterator const its11 = test11.begin();
	if(it11->first == its11->first)
		std::cout << "const iterator begin - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "const iterator begin - | \x1B[31mKO\x1B[0m |" << std::endl;
    ft::map<int, int> const my12(my);
    std::map<int, int> const test12(test);
	ft::map<int, int>::const_iterator const it12 = my11.end();
	std::map<int, int>::const_iterator const its12 = test11.end();
	if(it12->first == its12->first)
		std::cout << "const iterator end - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "const iterator end - | \x1B[31mKO\x1B[0m |" << std::endl;
    ft::map<int, int> const my13(my);
    std::map<int, int> const test13(test);
	ft::map<int, int>::const_reverse_iterator const it13 = my11.rbegin();
	std::map<int, int>::const_reverse_iterator const its13 = test11.rbegin();
	if(it13->first == its13->first)
		std::cout << "const reverse iterator - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "const reverse iterator - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// it2 = my4.rend();
	// std::cout << "reverse rend = " << it2->first << std::endl;
	// it2--;
	// std::cout << "reverse rend = " << it2->first << std::endl;
	//********************************************************
	// for(ft::map<int, int>::iterator my_i = my4.begin(); my_i != my4.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my4.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test4.begin(); test_i != test4.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test4.size() << std::endl;
	//********************************************************
	if(my.empty() == test.empty())
		std::cout << "empty() - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "empty() - | \x1B[31mKO\x1B[0m |" << std::endl;
	// //********************************************************
	if(my.size() == test.size())
		std::cout << "size() - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "size() - | \x1B[31mKO\x1B[0m |" << std::endl;
	// std::cout << "my size = " << my.size() << " orig size = " << test.size() << std::endl; 
	// //********************************************************
	if(my.max_size() == test.max_size())
		std::cout << "max_size() - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "max_size() - | \x1B[31mKO\x1B[0m |" << std::endl;	
	// //********************************************************
	if((my[3] == test[3]) && (my[7] == test[7]))
		std::cout << "оператор индексации - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "оператор индексации - | \x1B[31mKO\x1B[0m |" << std::endl;
	if((my[1] == test[1]) && (my[11] == test[11]))
		std::cout << "оператор индексации - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "оператор индексации - | \x1B[31mKO\x1B[0m |" << std::endl;	
	// //********************************************************
	my.insert(std::make_pair(17, 17));
	test.insert(std::make_pair(17, 17));
	if(my.size() == test.size())
		std::cout << "insert - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "insert - | \x1B[31mKO\x1B[0m |" << std::endl;
	// //********************************************************
	// for(ft::map<int, int>::iterator my_i = my.begin(); my_i != my.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test.begin(); test_i != test.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test.size() << std::endl;
	// //********************************************************
	ft::map<int, int>my6;
    std::map<int, int>test6;
	for(int t = 1; t != 100; t++)
        my6.insert(std::make_pair(t, t));
	for(int t = 1; t != 100; t++)
        test6.insert(std::make_pair(t, t));
	if(my6.size() == test6.size())
		std::cout << "добавление 100 элементов - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "добавление 100 элементов - | \x1B[31mKO\x1B[0m |" << std::endl;
	// //********************************************************	
	// for(ft::map<int, int>::iterator my_i = my6.begin(); my_i != my6.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my6.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test6.begin(); test_i != test6.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test6.size() << std::endl;
	// //********************************************************
	ft::map<int, int>my7;
    std::map<int, int>test7;
	for(int t = 1; t != 1000; t++)
        my7.insert(std::make_pair(t, t));
	for(int t = 1; t != 1000; t++)
        test7.insert(std::make_pair(t, t));
	if(my7.size() == test7.size())
		std::cout << "добавление 1000 элементов - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "добавление 1000 элементов - | \x1B[31mKO\x1B[0m |" << std::endl;
	// //********************************************************	
	// for(ft::map<int, int>::iterator my_i = my7.begin(); my_i != my7.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my7.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test7.begin(); test_i != test7.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test7.size() << std::endl;
	// //********************************************************
	ft::map<int, double>my8;
    std::map<int, double>test8;
	for(int t = 1; t != 1000; t++)
        my8.insert(std::make_pair(t, t));
	for(int t = 1; t != 1000; t++)
        test8.insert(std::make_pair(t, t));
	if(my8.size() == test8.size())
		std::cout << "добавление 1000 элементов - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "добавление 1000 элементов - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************	
	// for(ft::map<int, double>::iterator my_i = my8.begin(); my_i != my8.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my8.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, double>::iterator test_i = test8.begin(); test_i != test8.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test8.size() << std::endl;
	//********************************************************
	ft::map<int, char>my16;
    std::map<int, char>test16;
	for(int t = 1; t != 1000; t++)
        my16.insert(std::make_pair(t, 'a'));
	for(int t = 1; t != 1000; t++)
        test16.insert(std::make_pair(t, 'a'));
	if(my16.size() == test16.size())
		std::cout << "добавление 1000 элементов - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "добавление 1000 элементов - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// for(ft::map<int, char>::iterator my_i = my16.begin(); my_i != my16.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my16.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, char>::iterator test_i = test16.begin(); test_i != test16.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test8.size() << std::endl;
	//********************************************************
	it = my.begin();
	its = test.begin();
	my.insert(it, std::make_pair(19, 19));
	test.insert(its, std::make_pair(19, 19));
	if(my.size() == test.size())
		std::cout << "insert - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "insert - | \x1B[31mKO\x1B[0m |" << std::endl;
	ft::map<int, char>my17;
    std::map<int, char>test17;
	for(int t = 65; t != 76; t++)
        my17.insert(std::make_pair(t, t));
	for(int t = 65; t != 76; t++)
        test17.insert(std::make_pair(t, t));
	if(my17.size() == test17.size())
		std::cout << "insert - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "insert - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// for(ft::map<int, char>::iterator my_i = my17.begin(); my_i != my17.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my17.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, char>::iterator test_i = test17.begin(); test_i != test17.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test17.size() << std::endl;
	//********************************************************
	ft::map<int, int>my5;
    std::map<int, int>test5;
	ft::map<int, int>::iterator it3 = my.end();
	std::map<int, int>::iterator its3 = test.end();
	my5.insert(it, it3);
	test5.insert(its, its3);
	if(my5.size() == test5.size())
		std::cout << "insert - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "insert - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// for(ft::map<int, int>::iterator my_i = my.begin(); my_i != my.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test.begin(); test_i != test.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test.size() << std::endl;
	//********************************************************
	it3 = my5.begin();
	it3++;
	its3 = test5.begin();
	its3++;
	my5.erase(it3);
	test5.erase(its3);
	it3 = my5.begin();
	its3 = test5.begin();
	it3++; it3++;
	its3++; its3++;
	my5.erase(it3);
	test5.erase(its3);
	//********************************************************
	if(my5.size() == test5.size())
		std::cout << "erase - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "erase - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// for(ft::map<int, int>::iterator my_i = my5.begin(); my_i != my5.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my5.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test5.begin(); test_i != test5.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test5.size() << std::endl;
	//********************************************************
	if((my5.erase(8) == test5.erase(8)) && (my5.erase(12) == test5.erase(12)))
		std::cout << "erase - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "erase - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// for(ft::map<int, int>::iterator my_i = my5.begin(); my_i != my5.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my5.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test5.begin(); test_i != test5.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test5.size() << std::endl;
	//********************************************************
	my5.swap(my4);
	test5.swap(test4);
	if(my5.size() == test5.size())
		std::cout << "swap - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "swap - | \x1B[31mKO\x1B[0m |" << std::endl;
	ft::map<int, int>my9;
    std::map<int, int>test9;
	my9.swap(my4);
	test9.swap(test4);
	if(my9.size() == test9.size())
		std::cout << "swap c пустым контейнером - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "swap c пустым контейнером - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// for(ft::map<int, int>::iterator my_i = my5.begin(); my_i != my5.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my5.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test5.begin(); test_i != test5.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test5.size() << std::endl;
	//********************************************************
	my5.clear();
	test5.clear();
	if(my5.size() == test5.size())
		std::cout << "clear - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "clear - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
    // std::cout << "size = " << my5.size() << std::endl;
    // std::cout << "size = " << test5.size() << std::endl;
	//********************************************************
	for(int t = 1; t != 15; t++)
        my5.insert(std::make_pair(t, t));
	for(int t = 1; t != 15; t++)
        test5.insert(std::make_pair(t, t));
	if((my5.find(3)->first == test5.find(3)->first) && (my5.find(12)->first == test5.find(12)->first))
		std::cout << "find - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "find - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	if((my5.count(3) == test5.count(3)) && (my5.count(12) == test5.count(12)))
		std::cout << "count - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "count - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	if((my5.lower_bound(3)->first == test5.lower_bound(3)->first) && (my5.lower_bound(12)->first == test5.lower_bound(12)->first))
		std::cout << "lower_bound - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "lower_bound - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************	
	if((my5.upper_bound(3)->first == test5.upper_bound(3)->first) && (my5.upper_bound(12)->first == test5.upper_bound(12)->first))
		std::cout << "upper_bound - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "upper_bound - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************	
	// for(ft::map<int, int>::iterator my_i = my5.begin(); my_i != my5.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my5.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test5.begin(); test_i != test5.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test5.size() << std::endl;
	//********************************************************
	std::pair<ft::map<int, int>::iterator,ft::map<int, int>::iterator> abc = my5.equal_range(12);
	std::pair<std::map<int, int>::iterator,std::map<int, int>::iterator> abc2 = test5.equal_range(12);
	if((abc.second->first == abc2.second->first) && (abc.second->second == abc2.second->second))
		std::cout << "equal_range - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "equal_range - | \x1B[31mKO\x1B[0m |" << std::endl;
	std::pair<ft::map<int, int>::iterator,ft::map<int, int>::iterator> abc3 = my5.equal_range(4);
	std::pair<std::map<int, int>::iterator,std::map<int, int>::iterator> abc4 = test5.equal_range(4);
	if((abc3.second->first == abc4.second->first) && (abc3.second->second == abc4.second->second))
		std::cout << "equal_range - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "equal_range - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************



    // std::map<int, std::string> test_std;
	// ft::map<int, std::string> my_std;



	
	// 			wtf /////
	
	


    // std::map<std::string, int> test_std;
	// ft::map<std::string, int> my_std;
	// for(int t = 1; t != 15; t++)
    //     my_std.insert(std::make_pair(t, std::to_string(t)));
	// for(int t = 1; t != 15; t++)
    //     test_std.insert(std::make_pair(t, std::to_string(t)));
	// ********************************************************	
	// for(ft::map<int, int>::iterator my_i = my5.begin(); my_i != my5.end(); my_i++)
    // std::cout << (*my_i).second << std::endl;
    // std::cout << "size = " << my5.size() << std::endl;
    // std::cout << std::endl;
    // for(std::map<int, int>::iterator test_i = test5.begin(); test_i != test5.end(); test_i++)
    //     std::cout << test_i->second << std::endl;
    // std::cout << "size = " << test5.size() << std::endl;
	// ********************************************************	

    return(0);
}
