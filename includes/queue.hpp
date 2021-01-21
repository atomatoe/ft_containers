/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:02:42 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/22 00:22:42 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef QUEUE_HPP
# define QUEUE_HPP

#include <iostream>
#include "deque.hpp"

namespace ft
{
template <class T, class Container = ft::deque<T> >
class queue
{
public:
    typedef  T			value_type;
    typedef  size_t		size_type;
    typedef Container	container_type;
    explicit queue (const container_type& ctnr = container_type())
    {
        _container = ctnr;
    }
    ~queue() {} ;
    bool empty() const
    {
		return(_container.empty());
    }
    size_type size() const
    {
        return(_container.size());
    }
    const value_type& front() const
    {
        return(_container.front());
    }
    value_type& front()
    {
        return(_container.front());
    }
    value_type& back()
    {
		return(_container.back());
    }
    const value_type& back() const
    {
        return(_container.back());
    }
    void push (const value_type& val)
    {
        _container.push_back(val);
    }
    void pop()
    {
        _container.pop_back();
    }

protected:
    container_type _container;

};
template <class T, class Container>
  bool operator == (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  {
	  return(lhs.size() == rhs.size());
  }
template <class T, class Container>
  bool operator != (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  {
	  return(lhs.size() != rhs.size());
  }
template <class T, class Container>
  bool operator <  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  {
	  return(lhs.size() < rhs.size());
  }
template <class T, class Container>
  bool operator <= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  {
	  return(lhs.size() <= rhs.size());
  }
template <class T, class Container>
  bool operator >  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  {
	  return(lhs.size() > rhs.size());
  }
template <class T, class Container>
  bool operator >= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  {
	  return(lhs.size() >= rhs.size());
  }

};

#endif
