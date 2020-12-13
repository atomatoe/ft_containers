/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:56:03 by atomatoe          #+#    #+#             */
/*   Updated: 2020/12/13 22:46:46 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>

namespace ft
{
template < class T, class Alloc = std::allocator<T> >
class Stack
{
private:
    size_t			count; // количество элементов на данный момент в массиве
    T				*pull; // массив
public:
	Stack (const T& ctnr = T())
	{
		pull = NULL;
		count = 0;
	}
	bool empty() const	// Возвращает true, если стек пуст
	{
		bool status = false;
		if(count == 0)
			status = true;
		return(status);
	}
	size_t size() const 	// Возвращает количество элементов в стеке.
	{
		return(count);
	}
	const T& top() const  //Возвращает ссылку на верхний элемент стека.
	{
		return(pull[count - 1]);
	}
	void push (const T& val) // Вставляет новый элемент вверху стек над текущим верхним элементом.
	{
		if(!val)
			return ;
		else
		{
			if(count == 0)
			{
				pull = new T[1];
				pull[0] = val;
				count++;
			}
			else
			{
				count += 1;
				T* newPull = pull;
				pull = new T[count];
				for (unsigned int i = 0; i < count - 1; ++i)
					pull[i] = newPull[i];
				delete [] newPull;
				pull[count - 1] = val;
			}
		}
	}
	void pop() // Удаляет верхний элемент стека, эффективно уменьшая его размер на единицу.
	{
		if(count != 0)
		{
			count--;
			T* newPull = pull;
			pull = new T[count];
			for(size_t i = 0; i < count; i++)
				pull[i] = newPull[i];
			delete [] newPull;
		}
	}
	bool operator == (const ft::Stack<T> &right) { return(count == right.count); }
	bool operator != (const ft::Stack<T> &right) { return(count != right.count); }
	bool operator < (const ft::Stack<T> &right) { return(count < right.count); }
	bool operator <= (const ft::Stack<T> &right) { return(count <= right.count); }
	bool operator > (const ft::Stack<T> &right) { return(count > right.count); }
	bool operator >= (const ft::Stack<T> &right) { return(count >= right.count); }
};

};

#endif