/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:56:03 by atomatoe          #+#    #+#             */
/*   Updated: 2020/12/14 16:02:44 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include <deque>

namespace ft
{
template <class T, class Container = std::deque<T> >
class stack
{
public:
	typedef Container	container_type;
    typedef  T			value_type;
    typedef  size_t		size_type;
	explicit stack (const container_type& ctnr = container_type())
	{
		_container = ctnr;
	}
	~stack() {};
	bool empty() const // Возвращает true, если стек пуст
	{
		return(_container.empty());
	}
	size_type size() const // Возвращает количество элементов в стеке
	{
		return(_container.size());
	}
    value_type& top() //Возвращает ссылку на верхний элемент стека
	{
		return(_container.back());
	}
	const value_type& top() const  //Возвращает ссылку на верхний элемент стека (const)
	{
		return(_container.back());
	}
	void push (const value_type& val) // Вставляет новый элемент вверху стек над текущим верхним элементом.
	{
		_container.push_back(val);
	}
	void pop() // Вставляет новый элемент вверху стек над текущим верхним элементом.
	{
		_container.pop_back();
	}
protected:
    container_type _container;
};


template <class T, class Container>
  bool operator == (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return(lhs.size() == rhs.size());
  }
template <class T, class Container>
  bool operator != (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return(lhs.size() != rhs.size());
  }
template <class T, class Container>
  bool operator <  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return(lhs.size() < rhs.size());
  }
template <class T, class Container>
  bool operator <= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return(lhs.size() <= rhs.size());
  }
template <class T, class Container>
  bool operator >  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return(lhs.size() > rhs.size());
  }
template <class T, class Container>
  bool operator >= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  {
	  return(lhs.size() >= rhs.size());
  }
};

#endif