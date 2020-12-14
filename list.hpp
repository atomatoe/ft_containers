/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:40:07 by atomatoe          #+#    #+#             */
/*   Updated: 2020/12/14 15:51:34 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_HPP
# define FT_LIST_HPP

#include <iostream>
#include <list>
// #include <iterator>
// При создании пустого массива в стандартном list, max size = max_size()объем доступной оперативной памяти.
// Это значение обычно отражает теоретический предел размера контейнера, 
// не более станд :: numeric_limits < difference_type > :: макс ( ). 
// Во время выполнения размер контейнера может быть ограничен значением, меньшим, чем max_size()объем доступной оперативной памяти.

// throw Ft_list::error();


namespace ft
{
template < class T, class Alloc = std::allocator<T> >
class list
{
private:

public:
    // typedef T value_type;
    // typedef Alloc allocator_type;
    // typedef typename allocator_type::reference reference;
    // typedef typename allocator_type::const_reference const_reference;
    // typedef typename allocator_type::pointer pointer;
    // typedef typename allocator_type::const_pointer const_pointer;

    // explicit list (const allocator_type& alloc = allocator_type()); // Создает пустой контейнер без элементов.
    // explicit list (size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); // Создает контейнер из n элементов. Каждый элемент является копией val .
    // template <class InputIterator> list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
    // // Создает контейнер с таким количеством элементов, как диапазон [первый, последний) , причем каждый элемент создается из соответствующего ему элемента в этом диапазоне в том же порядке.
    // list (const list& x); // конструктор копирования
    // ~list(); // деструктор
    // list& operator= (const list& x);
    // bool empty() const;
    // size_t size() const;
    // size_t max_size() const;
    // void assign (size_t n, const value_type &val);
    // void push_front (const value_type& val);
    // void pop_front();
    // void push_back (const value_type& val);
    // void pop_back();
    // void insert (iterator position, size_t n, const value_type& val);
	// void swap (list& x);
	// void resize (size_t n, value_type val = value_type());
	// void clear();

    // // iterators:
    // const_iterator begin() const; //  Возвращает итератор, указывающий на первый элемент в контейнере списка .
    // iterator begin();
    // const_iterator end() const;  // Возвращает итератор, относящийся к последнему элементу в контейнере списка .
    // iterator end();
	// iterator erase (iterator position);
	// iterator erase (iterator first, iterator last);
    // iterator insert (iterator position, const value_type& val);
    // reverse_iterator rbegin() const;
    // const_reverse_iterator rbegin() const; // Возвращает обратный итератор, указывающий на последний элемент в контейнере (т.е. его обратное начало ).
    // reverse_iterator rend ();
    // const_reverse_iterator rend() const; // Возвращает обратный итератор, указывающий на теоретический элемент, предшествующий первому элементу в контейнере списка (который считается его обратным концом ).
    // const_reference front() const;
    // reference front();
    // reference back();
    // const_reference back() const;
    // template <class InputIterator>
    // void assign (InputIterator first, InputIterator last);

    // template <class InputIterator>
    // void insert (iterator position, InputIterator first, InputIterator last);
	

};

};


#endif