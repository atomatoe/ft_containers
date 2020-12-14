/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:56:03 by atomatoe          #+#    #+#             */
/*   Updated: 2020/12/14 15:58:29 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <iterator>
// При создании пустого массива в стандартном vector, max size = max_size()объем доступной оперативной памяти.
// Это значение обычно отражает теоретический предел размера контейнера, 
// не более станд :: numeric_limits < difference_type > :: макс ( ). 
// Во время выполнения размер контейнера может быть ограничен значением, меньшим, чем max_size()объем доступной оперативной памяти.

// namespace ft
// {
// template < class T, class Alloc = std::allocator<T> >
// class vector
// {
// private:
// 	size_t			max_len; // максимальное количество возможных элементов в массиве
//     size_t			count; // количество элементов на данный момент в массиве
//     T				*pull; // массив
// public:
//     vector();    // Вектор c неопределенным размером
//     vector(size_t value, T value2); // Вектор, состоящий из value элементов типа T. По умолчанию все элементы заполняются value2.
//     vector(size_t value); // Вектор из value элементов типа T.
//     ~vector(); // деструктор
//     vector(const vector &name); // конструктор копирования 
//     size_t size(void); // Возвращает количество элементов в векторе	
//     size_t max_size(void); // Возвращает максимально возможное количество элементов в векторе	
//     void resize(size_t value); // Изменяет размер вектора на заданную величину	
//     bool empty(void); // Возвращает true, если вектор пуст	
//     void reserve(size_t value); // Устанавливает минимально возможное количество элементов в векторе	
//     size_t capacity(); // Возвращает количество элементов, которое может содержать вектор до того, как ему потребуется выделить больше места.
//     void clear(void); // удаляет все элементы вектора
//     void insert(); // Вставка элементов в вектор. Вставка в конец, при условии, что память не будет перераспределяться — O(1), в произвольное место — O(n)
//     void erase(); // Удаляет указанные элементы вектора (один или несколько)	
// 	void assign(size_t value, const T &value2);
//     void push_back(T name); // Вставка элемента в конец вектора
//     void pop_back(void); // Удалить последний элемент vector
//     void swap(vector &name); // Обменять содержимое двух векторов

//     vector & operator=(const vector &name) // оператор присваивания
// 	{
		
// 	}
//     T & operator[] (const unsigned int index) // оператор индексации
// 	{
// 		return pull[index];
// 	}
// 	vector& operator ++()
//    	{
//        	++pull;
//        	return *this;
//   	}
// 	vector& operator --()
//   	{
//   	    --pull;
//        	return *this;
//    	}
// 	vector operator --(int)
//   	{
//   	    vector name = pull;
// 		--pull;
//        	return (name);
//    	}
// 	vector operator ++(int)
//   	{
//   	    vector name = pull;
// 		++pull;
//        	return (name);
//    	}
// 	T& operator *()
//    	{
//       	return *pull;
//    	}
// 	bool operator ==(const vector& other)
//    	{
//       	return (pull == other.pull);
//    	}
// 	bool operator !=(const vector& other)
//    	{
//       	return !(*this == other);
//    	}
	
// 	vector begin()
// 	{
//     	return vector(*pull);
// 	}

// 	vector end()
// 	{
// 		return vector(*(pull + count));
// 	}
};

};


#endif