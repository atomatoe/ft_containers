/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:29 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/24 00:18:51 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <iterator>
#include <unistd.h>

namespace ft
{
template <class Key, class T, class Compare, class Alloc = std::allocator<T> >
class map
{
public:
	typedef Key											key_type;
	typedef T											mapped_type;
	typedef std::pair<const key_type, mapped_type>		value_type;
	typedef Compare										key_compare;
	typedef Alloc										allocator_type;
	typedef value_type &								reference;
	typedef const value_type &							const_reference;
	typedef value_type *								pointer;
	typedef const value_type *							const_pointer;
	typedef size_t 										size_type;
	typedef ptrdiff_t 									difference_type;
    class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;
    class value_compare;
private:
    class Node
    {
    public:
        Node *_left; // указатель на левую часть дерева
        Node *_right; // указатель на правую часть дерева
        T _data; // значение
        Node(T value = T(), Node *left = nullptr, Node *right = nullptr)
        {
            this->_data = value;
            this->_left = left;
            this->_right = right;
        }
    };
    Node *head; // родитель
    size_type _size; // размер дерева
    allocator_type _alloc;
public:
    explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()); // Создает пустой контейнер без элементов.
    template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()); // Создает контейнер с таким количеством элементов, как диапазон [первый, последний), причем каждый элемент создается из соответствующего ему элемента в этом диапазоне.
    map (const map& x); // copy construct
    ~map(); // destructor
    map& operator= (const map& x); // оператор присваивания
    iterator begin();  // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    const_iterator begin() const; // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    reverse_iterator rbegin();  // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    const_reverse_iterator rbegin() const; // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    iterator end(); // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    const_iterator end() const; // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    reverse_iterator rend(); // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    const_reverse_iterator rend() const;  //  Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    bool empty() const; // Возвращает, пуст ли контейнер карты (т.е. равен ли его размер 0).
    size_type size() const; // Возвращает количество элементов в контейнере карты.
    size_type max_size() const; // Возвращает максимальное количество элементов, которое может содержать контейнер карты.
    mapped_type& operator[] (const key_type& k); // оператор индексации
    std::pair<iterator,bool> insert (const value_type& val); // Расширяет контейнер, вставляя новые элементы, эффективно увеличивая размер контейнера на количество вставленных элементов.
    iterator insert (iterator position, const value_type& val); // Расширяет контейнер, вставляя новые элементы, эффективно увеличивая размер контейнера на количество вставленных элементов.
    template <class InputIterator>
        void insert (InputIterator first, InputIterator last); // Расширяет контейнер, вставляя новые элементы, эффективно увеличивая размер контейнера на количество вставленных элементов.
    void erase (iterator position); // Удаляет из контейнера карты либо один элемент, либо ряд элементов ([первый, последний)).
    size_type erase (const key_type& k); // Удаляет из контейнера карты либо один элемент, либо ряд элементов ([первый, последний)).
    void erase (iterator first, iterator last); // Удаляет из контейнера карты либо один элемент, либо ряд элементов ([первый, последний)).
    void swap (map& x); // Меняет содержимое контейнера на содержимое x, которое является другой картой того же типа. Размеры могут отличаться.
    void clear(); // Удаляет все элементы из контейнера карты (которые уничтожаются), оставляя контейнер с размером 0.
    key_compare key_comp() const; // Возвращает копию объекта сравнения, используемого контейнером для сравнения ключей.
    value_compare value_comp() const; // Возвращает объект сравнения, который можно использовать для сравнения двух элементов, чтобы узнать, идет ли ключ первого элемента раньше второго.
    iterator find (const key_type& k); // Ищет в контейнере элемент с ключом, эквивалентным k, и возвращает ему итератор, если он найден, в противном случае он возвращает итератор для map :: end.
    const_iterator find (const key_type& k) const; // Ищет в контейнере элемент с ключом, эквивалентным k, и возвращает ему итератор, если он найден, в противном случае он возвращает итератор для map :: end.
    size_type count (const key_type& k) const; // Ищет в контейнере элементы с ключом, эквивалентным k, и возвращает количество совпадений.
    iterator lower_bound (const key_type& k); // Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого не считается предшествующим k (то есть либо эквивалентным, либо идущим после).
    const_iterator lower_bound (const key_type& k) const; // Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого не считается предшествующим k (то есть либо эквивалентным, либо идущим после).
    iterator upper_bound (const key_type& k);   // Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого считается идущим после k.
    const_iterator upper_bound (const key_type& k) const; // Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого считается идущим после k.
    std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const; // Возвращает границы диапазона, который включает все элементы в контейнере с ключом, эквивалентным k.
    std::pair<iterator,iterator> equal_range (const key_type& k);  // Возвращает границы диапазона, который включает все элементы в контейнере с ключом, эквивалентным k.

    class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
        
    };
	class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {

    };
	class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {

    };
	class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {

    };
    class value_compare : public std::binary_function<value_type, value_type, bool>
    {

    };
};

};
#endif