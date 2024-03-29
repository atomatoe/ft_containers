/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:26:12 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/23 22:22:49 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.hpp"
#include "../includes/queue.hpp"
#include "../includes/list.hpp"
#include "../includes/vector.hpp"
#include <vector>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <unistd.h>

int main()
{
    std::cout << std::endl;
	std::cout << "|___________________________|" << std::endl;
	std::cout << "|                           |" << std::endl;
	std::cout << "|     TEST VECTOR START!     |" << std::endl;
	std::cout << "|___________________________|" << std::endl;
	std::cout << "| func |           | result |" << std::endl;
	std::cout << "|______|___________|________|" << std::endl;
	std::cout << std::endl;
	//********************************************************
	//  Тест конструкторов
	//********************************************************
	ft::vector<int> my;
	std::vector<int> test;
	ft::vector<std::string> my_s;
	std::vector<std::string> test_s;
	ft::vector<double> my_s_d;
	std::vector<double> test_s_d;
	if(my.empty() == true && test.empty() == true && test.size() == 0 && my.size() == 0)
		std::cout << "Создание пустого контейнера - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Создание пустого контейнера - | \x1B[31mKO\x1B[0m |" << std::endl;
	if(my_s.empty() == true && test_s.empty() == true && test_s.size() == 0 && my_s.size() == 0)
		std::cout << "Создание пустого контейнера строк - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Создание пустого контейнера строк - | \x1B[31mKO\x1B[0m |" << std::endl;
	if(my_s_d.empty() == true && test_s_d.empty() == true && test_s_d.size() == 0 && my_s_d.size() == 0)
		std::cout << "Создание пустого контейнера double - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Создание пустого контейнера double - | \x1B[31mKO\x1B[0m |" << std::endl;
    //********************************************************
	ft::vector<int> my2(21, 777);
	std::vector<int> test2(21, 777);
	ft::vector<std::string> my2_s(5, "hello");
	std::vector<std::string> test2_s(5, "hello");
	ft::vector<double> my2_d(21, 17.22);
	std::vector<double> test2_d(21, 17.22);
	if(my2.empty() == false && test2.empty() == false && test2.size() == 21 && my2.size() == 21)
		std::cout << "Создание контейнера из 21 элемента содержащих 777 - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Создание контейнера из 21 элемента содержащих 777 - | \x1B[31mKO\x1B[0m |" << std::endl;
	if(my2_s.empty() == false && test2_s.empty() == false && test2_s.size() == my2_s.size())
		std::cout << "Создание контейнера из 5 элементов содержащих hello - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Создание контейнера из 5 элементов содержащих hello - | \x1B[31mKO\x1B[0m |" << std::endl;
	if(my2_d.empty() == false && test2_d.empty() == false && test2_d.size() == my2_d.size())
		std::cout << "Создание контейнера из 21 элемента содержащих 17.22 - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Создание контейнера из 21 элемента содержащих 17.22 - | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator iter = my2.begin(); iter != my2.end(); iter++)
	// 	std::cout << *iter << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator iter2 = test2.begin(); iter2 != test2.end(); iter2++)
	// 	std::cout << *iter2 << std::endl;
	//********************************************************
	ft::vector<int> my3(my2);
	std::vector<int> test3(test2);
	if(my3.empty() == false && test3.empty() == false && test3.size() == 21 && my3.size() == 21)
		std::cout << "Конструктор копирования прошлого результата - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Конструктор копирования прошлого результата - | \x1B[31mKO\x1B[0m |" << std::endl;
	ft::vector<double> my3_d(my2_d);
	std::vector<double> test3_d(test2_d);
	if(my3_d.empty() == false && test3_d.empty() == false && test3_d.size() == my3_d.size())
		std::cout << "Конструктор копирования прошлого результата - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Конструктор копирования прошлого результата - | \x1B[31mKO\x1B[0m |" << std::endl;
	ft::vector<long> long_test(12, 22);
	std::vector<long> long_test2(12, 22);
	ft::vector<long> my3_l(long_test);
	std::vector<long> test3_l(long_test2);
	if(my3_l.empty() == false && test3_l.empty() == false && test3_l.size() == my3_l.size())
		std::cout << "Конструктор копирования прошлого результата - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Конструктор копирования прошлого результата - | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator iter = my2.begin(); iter != my2.end(); iter++)
	// 	std::cout << *iter << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator iter2 = test2.begin(); iter2 != test2.end(); iter2++)
	// 	std::cout << *iter2 << std::endl;
	//********************************************************
	ft::vector<int> my4 = my3;
	std::vector<int> test4 = test3;
	if(my3.empty() == false && test3.empty() == false && test3.size() == my3.size())
		std::cout << "Операторы присваивания - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Операторы присваивания - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator iter = my2.begin(); iter != my2.end(); iter++)
	// 	std::cout << *iter << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator iter2 = test2.begin(); iter2 != test2.end(); iter2++)
	// 	std::cout << *iter2 << std::endl;
	// ********************************************************
	ft::vector<int> my5(1000, 5000);
	std::vector<int> test5(1000, 5000);
	ft::vector<double> my5_d(1000, 5.5);
	std::vector<double> test5_d(1000, 5.5);
	ft::vector<std::string> my5_s(1000, "hi");
	std::vector<std::string> test5_s(1000, "hi");
	if(my5.empty() == false && test5.empty() == false && test5.size() == 1000 && my5.size() == 1000)
		std::cout << "Создание контейнера из 1000 элементов содержащих 5000 - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Создание контейнера из 1000 элементов содержащих 5000 - | \x1B[31mKO\x1B[0m |" << std::endl;
	if(my5_d.empty() == false && test5_d.empty() == false && test5_d.size() == my5_d.size())
		std::cout << "Создание контейнера из 1000 элементов содержащих 5.5 - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Создание контейнера из 1000 элементов содержащих 5.5 - | \x1B[31mKO\x1B[0m |" << std::endl;
	if(my5_s.empty() == false && test5_s.empty() == false && test5_s.size() == my5_s.size())
		std::cout << "Создание контейнера из 1000 элементов содержащих hi - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Создание контейнера из 1000 элементов содержащих hi - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	ft::vector<int> my6(10000, 21);
	std::vector<int> test6(10000, 21);
	if(my6.empty() == false && test6.empty() == false && test6.size() == 10000 && my6.size() == 10000)
		std::cout << "Создание контейнера из 10000 элементов содержащих 21 - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Создание контейнера из 10000 элементов содержащих 21 - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	ft::vector<int> my7(100000, 42);
	std::vector<int> test7(100000, 42);
	if(my7.empty() == false && test7.empty() == false && test7.size() == 100000 && my7.size() == 100000)
		std::cout << "Создание контейнера из 100000 элементов содержащих 42 - | \x1B[32mOK\x1B[0m |" << std::endl;
	else
		std::cout << "Создание контейнера из 100000 элементов содержащих 42 - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	//  Тест добавление в конец - push back
	//********************************************************
	ft::vector<int> my8;
	std::vector<int> test8;
	my8.push_back(50);
	test8.push_back(50);
	if(my8.empty() == false && test8.empty() == false && test8.size() == 1 && my8.size() == 1)
		std::cout << "Создание контейнера и добавление туда 1 элемента - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Создание контейнера и добавление туда 1 элемента - | \x1B[31mKO\x1B[0m |" << std::endl;
	// //********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	// ********************************************************
	for(size_t i = 500; i != 0; i--)
		my8.push_back(i);
	for(size_t i = 500; i != 0; i--)
		test8.push_back(i);
	if(my8.empty() == false && test8.empty() == false && test8.size() == 501 && my8.size() == 501)
		std::cout << "Добавление в этот контейнер 500 элементов - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Добавление в этот контейнер 500 элементов - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	for(size_t i = 5000; i != 0; i--)
		my8.push_back(i);
	for(size_t i = 5000; i != 0; i--)
		test8.push_back(i);
	//********************************************************
	if(my8.empty() == false && test8.empty() == false && test8.size() == 5501 && my8.size() == 5501)
		std::cout << "Добавление в этот контейнер 5000 элементов - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Добавление в этот контейнер 5000 элементов - | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	//********************************************************
	//  Тест удаления pop back в конце
	//********************************************************
	for(size_t i = 500; i != 0; i--)
		my8.pop_back();
	for(size_t i = 500; i != 0; i--)
		test8.pop_back();
	//********************************************************
	if(my8.empty() == false && test8.empty() == false && test8.size() == 5001 && my8.size() == 5001)
		std::cout << "Удаление из контейнера 500 элементов - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Удаление из контейнера 500 элементов - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	//********************************************************
	for(size_t i = 4800; i != 0; i--)
		my8.pop_back();
	for(size_t i = 4800; i != 0; i--)
		test8.pop_back();
	// //********************************************************
	if(my8.empty() == false && test8.empty() == false && test8.size() == 201 && my8.size() == 201)
		std::cout << "Удаление из контейнера 4800 элементов - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Удаление из контейнера 4800 элементов - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	//********************************************************
	for(size_t i = 199; i != 0; i--)
		my8.pop_back();
	for(size_t i = 199; i != 0; i--)
		test8.pop_back();
	// //********************************************************
	if(my8.empty() == false && test8.empty() == false && test8.size() == 2 && my8.size() == 2)
		std::cout << "Удаление из контейнера 199 элементов - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Удаление из контейнера 199 элементов - | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	//********************************************************
	//  Тест добавление в начало - push front
	//********************************************************
	for(size_t i = 1; i != 0; i--)
		my8.push_back(21);
	for(size_t i = 1; i != 0; i--)
		test8.push_back(21);
	if(my8.empty() == false && test8.empty() == false && test8.size() == 3 && my8.size() == 3)
		std::cout << "Добавление в начало 1 элемент (21) - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Добавление в начало 1 элемент (21)  - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	//********************************************************
	for(size_t i = 5; i != 0; i--)
		my8.push_back(32);
	for(size_t i = 5; i != 0; i--)
		test8.push_back(32);
	if(my8.empty() == false && test8.empty() == false && test8.size() == 8 && my8.size() == 8)
		std::cout << "Добавление в начало 5 элементов (32) - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Добавление в начало 5 элементов (32)  - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	//********************************************************
	//  Тест удаления pop front в начале
	//********************************************************
	for(size_t i = 4; i != 0; i--)
		my8.pop_back();
	for(size_t i = 4; i != 0; i--)
		test8.pop_back();
	if(my8.empty() == false && test8.empty() == false && test8.size() == 4 && my8.size() == 4)
		std::cout << "Удаление с начала 4 элемента - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Удаление с начала 4 элемента  - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	//********************************************************
	//  Тест полное удаление clear
	//********************************************************
	my8.clear();
	test8.clear();
	if(my8.empty() == true && test8.empty() == true && test8.size() == 0 && my8.size() == 0)
		std::cout << "Полная очистка контейнера - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Полная очистка контейнера  - | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	// //********************************************************
	// //  Тест swap
	// //********************************************************
	for(size_t i = 0; i != 7; i++)
		my8.push_back(i);
	ft::vector<int> my9;
	my8.swap(my9);
	for(size_t i = 0; i != 7; i++)
		test8.push_back(i);
	std::vector<int> test9;
	test8.swap(test9);
	if(my8.empty() == true && test8.empty() == true && test8.size() == 0 && my8.size() == 0)
		std::cout << "swap с пустым контейнером - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "swap с пустым контейнером  - | \x1B[31mKO\x1B[0m |" << std::endl;
	if(my9.empty() == false && test9.empty() == false && test9.size() != 0 && my9.size() != 0)
		std::cout << "swap с полным контейнером - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "swap с полным контейнером  - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i9 = my9.begin(); i9 != my9.end(); i9++)
	// 	std::cout << *i9 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest9 = test9.begin(); itest9 != test9.end(); itest9++)
	// 	std::cout << *itest9 << std::endl;
	//********************************************************
	//  Тест assign
	//********************************************************
	my8.assign((size_t)5, 99);
	test8.assign((size_t)5, 99);
	if(my8.empty() == false && test8.empty() == false && test8.size() == 5 && my8.size() == 5)
		std::cout << "assign из 5 элементов равных 99 - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "assign из 5 элементов равных 99  - | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	//********************************************************
	my8.assign((size_t)4, 61);
	test8.assign((size_t)4, 61);
	if(my8.empty() == false && test8.empty() == false && test8.size() == 4 && my8.size() == 4)
		std::cout << "assign из 2 элементов равных 61 - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "assign из 5 элементов равных 61  - | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i8 = my8.begin(); i8 != my8.end(); i8++)
	// 	std::cout << *i8 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest8 = test8.begin(); itest8 != test8.end(); itest8++)
	// 	std::cout << *itest8 << std::endl;
	// ********************************************************
	//  Тест iterator добавление
	//********************************************************
	std::vector<int> iterator_test2;
	ft::vector<int> iterator_test;
	for(size_t i = 0; i < 9; i++)
		iterator_test.push_back(i);
	for(size_t i = 0; i < 9; i++)
		iterator_test2.push_back(i);
	ft::vector<int>::iterator i2 = iterator_test.begin();
	std::vector<int>::iterator itest2 = iterator_test2.begin();
	i2++;
	itest2++;
	iterator_test.insert(i2, 12);
	iterator_test2.insert(itest2, 12);
	// ********************************************************
	if(iterator_test.empty() == false && iterator_test2.empty() == false && iterator_test.size() == iterator_test2.size())
		std::cout << "Добавление элемента по итератору ++ и -- | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Добавление элемента по итератору ++ и -- | \x1B[31mKO\x1B[0m |" << std::endl;
	//********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i2 = iterator_test.begin(); i2 != iterator_test.end(); i2++)
	// 	std::cout << *i2 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest2 = iterator_test2.begin(); itest2 != iterator_test2.end(); itest2++)
	// 	std::cout << *itest2 << std::endl;
	//********************************************************
	my3.clear();
	test3.clear();
	for(size_t i = 0; i != 10; i++)
		my3.push_back(i);
	for(size_t i = 0; i != 10; i++)
		test3.push_back(i);	
	ft::vector<int> const my11(my3);
	std::vector<int> const test11(test3);
	ft::vector<int>::const_iterator const i3 = my11.begin();
	std::vector<int>::const_iterator const itest3 = test11.begin();
	// // //********************************************************
	if(*i3 != *itest3)
		std::cout << "const итератор - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "const итератор - | \x1B[31mKO\x1B[0m |" << std::endl;
	// // ********************************************************
	ft::vector<int>::reverse_iterator i4 = my3.rbegin();
	i4++;
	i4++;
	i4--;
	i4++;
	i4--;
	std::vector<int>::reverse_iterator itest4 = test3.rbegin();
	itest4++;
	itest4++;
	itest4--;
	itest4++;
	itest4--;
	if(*i4 == *itest4)
		std::cout << "reverse rbegin итератор +- | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "reverse rbegin итератор +- | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my reverse interator = " << *i4 << std::endl;
	// std::cout << "orig reverse interator = " <<*itest4 << std::endl;
	// ********************************************************
	my3.clear();
	test3.clear();
	for(size_t i = 0; i != 10; i++)
		my3.push_back(i);
	for(size_t i = 0; i != 10; i++)
		test3.push_back(i);	
	ft::vector<int>::reverse_iterator const i5 = my3.rbegin();
	std::vector<int>::reverse_iterator const itest5 = test3.rbegin();
	// // //********************************************************
	if(*i5 == *itest5)
		std::cout << "const reverse итератор | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "const reverse итератор | \x1B[31mKO\x1B[0m |" << std::endl;
	// //********************************************************
	my3.clear();
	test3.clear();
	for(size_t i = 0; i != 10; i++)
		my3.push_back(i);
	for(size_t i = 0; i != 10; i++)
		test3.push_back(i);	
	ft::vector<int>::reference i6 = my3.back();
	std::vector<int>::reference itest6 = test3.back();
	if(i6 == itest6)
		std::cout << "reference итератор back | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "reference итератор back  | \x1B[31mKO\x1B[0m |" << std::endl;
	i6 = my3.front();
	itest6 = test3.front();
	if(i6 == itest6)
		std::cout << "reference итератор front | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "reference итератор front  | \x1B[31mKO\x1B[0m |" << std::endl;
	i6 = my3.at(5);
	itest6 = test3.at(5);
	if(i6 == itest6)
		std::cout << "reference итератор at(5) | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "reference итератор at(5)  | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i3 = my3.begin(); i3 != my3.end(); i3++)
	// 	std::cout << *i3 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest3 = test3.begin(); itest3 != test3.end(); itest3++)
	// 	std::cout << *itest3 << std::endl;
	// ********************************************************
	//  Тест iterator erase
	// ********************************************************
	my3.clear();
	test3.clear();
	for(size_t i = 0; i != 10; i++)
		my3.push_back(i);
	for(size_t i = 0; i != 10; i++)
		test3.push_back(i);
	ft::vector<int>::iterator i7 = my3.begin();
	std::vector<int>::iterator itest7 = test3.begin();
	i7++;
	itest7++;
	my3.erase(i7);
	test3.erase(itest7);
	i7++;
	itest7++;
	i7++;
	itest7++;
	my3.erase(i7);
	test3.erase(itest7);
	if(my3.size() == test3.size())
		std::cout << "erase итератор | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "erase итератор | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i3 = my3.begin(); i3 != my3.end(); i3++)
	// 	std::cout << *i3 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest3 = test3.begin(); itest3 != test3.end(); itest3++)
	// 	std::cout << *itest3 << std::endl;
	// ********************************************************
	my3.clear();
	test3.clear();
	for(size_t i = 0; i != 10; i++)
		my3.push_back(i);
	for(size_t i = 0; i != 10; i++)
		test3.push_back(i);
	i7 = my3.begin();
	i7++;
	i7++;
	itest7 = test3.begin();
	itest7++;
	itest7++;
	my3.erase(i7, my3.end());
	test3.erase(itest7, test3.end());
	if(my3.size() == test3.size())
		std::cout << "erase итератор от first до last | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "erase итератор от first до last | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i3 = my3.begin(); i3 != my3.end(); i3++)
	// 	std::cout << *i3 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest3 = test3.begin(); itest3 != test3.end(); itest3++)
	// 	std::cout << *itest3 << std::endl;
	// ********************************************************
	ft::vector<int> my13;
	std::vector<int> test13;
	for(size_t i = 0; i != 9; i++)
		my13.push_back(i);
	for(size_t i = 0; i != 9; i++)
		test13.push_back(i);
	if(my13.size() == test13.size())
		std::cout << "проверка size | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "проверка size | \x1B[31mKO\x1B[0m |" << std::endl;
	my13.resize(5, 20);
	test13.resize(5, 20);
	if(my13.size() == test13.size())
		std::cout << "проверка resize > | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "проверка resize > | \x1B[31mKO\x1B[0m |" << std::endl;
	my13.resize(5, 2);
	test13.resize(5, 2);
	if(my13.size() == test13.size())
		std::cout << "проверка resize < | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "проверка resize < | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i13 = my13.begin(); i13 != my13.end(); i13++)
	// 	std::cout << *i13 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest13 = test13.begin(); itest13 != test13.end(); itest13++)
	// 	std::cout << *itest13 << std::endl;
	// ********************************************************
	if(my13.empty() == test13.empty())
		std::cout << "проверка empty < | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "проверка empty < | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	if(my13.max_size() == test13.max_size())
		std::cout << "проверка max_size | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "проверка max_size | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	ft::vector<int> test_it((size_t)4, 11);
	std::vector<int> test2_it((size_t)4, 11);
	if(test_it[2] == test2_it[2])
		std::cout << "Проверка индексации [] - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "Проверка индексации [] - | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "Проверка индексации []: " << "my = " << test_it[2] << " orig = " << test2_it[2] << std::endl;
	// ********************************************************
	ft::vector<int> my14(9, 9);
	std::vector<int> test14(9, 9);
	ft::vector<int>::iterator my15 = my14.begin();
	std::vector<int>::iterator test15 = test14.begin();
	ft::vector<int>::iterator my16 = my14.end();
	std::vector<int>::iterator test16 = test14.end();
	my15++;
	test15++;
	my16--;
	test16--;
	ft::vector<int> my17(my15, my16);
	std::vector<int> test17(test15, test16);
	// ********************************************************
	if(my17.size() == test17.size())
		std::cout << "проверка конструктора с итераторами - | \x1B[32mOK\x1B[0m | " << std::endl;
	else
		std::cout << "проверка конструктора с итераторами - | \x1B[31mKO\x1B[0m |" << std::endl;
	// ********************************************************
	// std::cout << "my vector: " << std::endl;
	// for(ft::vector<int>::iterator i19 = my17.begin(); i19 != my17.end(); i19++)
	// 	std::cout << *i19 << std::endl;
	// std::cout << "orig vector: " << std::endl;
	// for(std::vector<int>::iterator itest17 = test17.begin(); itest17 != test17.end(); itest17++)
	// 	std::cout << *itest17 << std::endl;
	// ********************************************************
    return(0);
}