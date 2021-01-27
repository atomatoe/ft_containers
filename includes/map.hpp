/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:29 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/27 04:47:24 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <iterator>
#include <unistd.h>

/*
Красно-черные деревья - один из способов балансировки деревьев.
Красно-черное дерево - это бинарное дерево с следующими свойствами:
1. Каждый узел покрашен либо в черный, либо в красный цвет.
2. Листьями объявляются nullptr-узлы (т.е. "виртуальные" узлы, наследники узлов, которые обычно называют листьями; на них "указывают" NULL указатели). Листья покрашены в черный цвет.
3. Если узел красный, то оба его потомка черны.
4. На всех ветвях дерева, ведущих от его корня к листьям, число черных узлов одинаково.
5. Cамая длинная ветвь от корня к листу не более чем вдвое длиннее любой другой ветви от корня к листу. (балансировка)
Количество черных узлов на ветви от корня до листа называется черной высотой дерева. 
*/
// https://habr.com/ru/post/330644/ - info красно-черные деревья
// http://algolist.ru/ds/rbtree.php - info, реализация алгоритма красно-черные деревья
// http://mech.math.msu.su/~vvb/2course/Borisenko/lecTree.html - info, реализация алгоритма красно-черные деревья

namespace ft
{
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
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
    size_type _size; // размер дерева
    key_compare _compare;
    allocator_type _alloc;
    class Node
    {
    public:
        value_type* _data; // значение
        Node *_parent; // указатель на родителя (предшественника)
        Node *_left; // указатель на левую часть дерева
        Node *_right; // указатель на правую часть дерева
        bool _color; // black/red статус, black = false, red = true
        Node(const value_type & value = 0, Node *parent = 0, bool color = 0, Node *left = 0, Node *right = 0)
        {
            this->_left = left;
            this->_right = right;
            this->_parent = parent;
            this->_color = color;
        }
    };
    Node *head; // корень дерева
    // ---------------------------------------------------------
    Node *insertNode(const value_type & data)
    {
        Node *parent, *x;
        Node *tmp = head;
		parent = 0;
        while(tmp != nullptr)
        {
            if(data.first == tmp->_data->first)
                return(tmp);
            parent = tmp;
            if(data.first < tmp->_data->first)
                tmp = tmp->_left;
            else
                tmp = tmp->_right;
        }
        // x = _alloc.allocate(1);
        x = new Node(data);
        x->_data = _alloc.allocate(1);
        _alloc.construct(x->_data, data);
        x->_parent = parent;
        x->_left = nullptr;
        x->_right = nullptr;
        x->_color = true; // red
        if(parent)
        {
            if(data.first < parent->_data->first)
                parent->_left = x;
            else
                parent->_right = x;
        }
        else
            head = x;
        // insertFixup(x); // чек балансировка
        _size++;
        return(x);
    }
    // ---------------------------------------------------------
    void deleteNode(Node *z)
	{
        Node *x, *y;
		if (!z || z == nullptr)
			return;
		if (z->_left == nullptr || z->_right == nullptr)
			y = z;
		else
		{
			y = z->_right;
			while (y->_left != nullptr)
                y = y->_left;
		}
		if (y->_left != nullptr)
			x = y->_left;
		else
            x = y->_right; // sega
		x->_parent = y->_parent;
		if (y->_parent)
			if (y == y->_parent->_left)
				y->_parent->_left = x;
			else
				y->_parent->_right = x;
		else
			head = x;
		if (y != z) 
            z->_data->second = y->_data->second;
		// if (y->_color == false)
		// 	deleteFixup (x);
        // _size--;
		delete y;
	}
    // ---------------------------------------------------------
    Node* find_max(Node *val)
    {
        Node *tmp = val;
        while(tmp->_right != nullptr)
            tmp = tmp->_right;
        return(tmp);
    }
    Node* find_min(Node *val)
    {
        Node *tmp = val;
        while(tmp->_left != nullptr)
            tmp = tmp->_left;
        return(tmp);
    }
    // ---------------------------------------------------------
public:
    explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) // Создает пустой контейнер без элементов.
    {
        _compare = comp;
        _alloc = alloc;
    }
    template <class InputIterator>
    map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) // Создает контейнер с таким количеством элементов, как диапазон [первый, последний), причем каждый элемент создается из соответствующего ему элемента в этом диапазоне.
    {
        _compare = comp;
        _alloc = alloc;
        insert(first, last);
    }
    map (const map& x); // copy construct
    ~map() {} // destructor
    map& operator= (const map& x); // оператор присваивания
    iterator begin() // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    { 
        iterator x(find_min(head));
        return(x);
    } 
    const_iterator begin() const // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    {
        iterator x(find_min(head));
        return(x);
    }
    reverse_iterator rbegin()  // Возвращает итератор, ссылающийся на последний элемент в контейнере карты
    {
        iterator x(find_max(head));
        return(x);
    }
    const_reverse_iterator rbegin() const // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    {
        iterator x(find_max(head));
        return(x);
    }
    iterator end() // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    {
        iterator x(find_max(head));
        return(x);
    }
    const_iterator end() const // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    {
        iterator x(find_max(head));
        return(x);
    }
    reverse_iterator rend() // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    {
        iterator x(find_min(head));
        return(x);
    }
    const_reverse_iterator rend() const //  Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    {
        iterator x(find_min(head));
        return(x);
    }
    bool empty() const; // Возвращает, пуст ли контейнер карты (т.е. равен ли его размер 0).
    size_type size() const { return(_size); } // Возвращает количество элементов в контейнере карты.
    size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(Node); } // Возвращает максимальное количество элементов, которое может содержать контейнер карты.
    mapped_type& operator[] (const key_type& k); // оператор индексации
    std::pair<iterator,bool> insert (const value_type& val) // Расширяет контейнер, вставляя новые элементы, эффективно увеличивая размер контейнера на количество вставленных элементов.
    {
        Node* tmp = insertNode(val);
        return (std::make_pair(tmp, true));
    }
    iterator insert (iterator position, const value_type& val); // Расширяет контейнер, вставляя новые элементы, эффективно увеличивая размер контейнера на количество вставленных элементов.
    template <class InputIterator>
    void insert (InputIterator first, InputIterator last) // Расширяет контейнер, вставляя новые элементы, эффективно увеличивая размер контейнера на количество вставленных элементов.
    {
        Node *tmp = first.getNode();
        while(first != last)
        {
            tmp = first.getNode();
            insertNode(*tmp->_data);
            first++;
        }
    }
    void erase (iterator position) // Удаляет из контейнера карты либо один элемент, либо ряд элементов ([первый, последний)).
    {
        Node *tmp = position.getNode();
        deleteNode(tmp);
    }
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
        private:
            Node *count;
        public:
            explicit iterator(Node *head = nullptr) { this->count = head; }
            ~iterator() { };
			iterator(const iterator &obj) { *this = obj; }
            iterator &operator=(const iterator &obj)
            {
                this->count = obj.count;
                return(*this);
            }
			iterator & operator++()
			{
                if(count->_right != nullptr)
                    count = count->_right;
                else
                    count = count->_parent;
                return(iterator(count));
			}
			iterator operator++(int)
			{
                if(count->_right != nullptr)
                    count = count->_right;
                else
                    count = count->_parent;
                return(iterator(count));
			}
			iterator & operator--()
			{
                if(count->_left != nullptr)
                    count = count->_left;
                else
                    count = count->_parent;
                return(iterator(count));
			}
			iterator operator--(int)
			{
                if(count->_left != nullptr)
                    count = count->_left;
                else
                    count = count->_parent;
                return(iterator(count));
			}
            T &operator*() const
            {
                return(this->count->_data->second);
            }
            T *operator&() const { return(*(this->count->_data->second)); }
            Node* getNode() const { return(count); }
            bool operator!= (iterator const &obj) const { return(count != obj.getNode()); };
            bool operator== (iterator const &obj) const { return(count == obj.getNode()); };
            bool operator<= (iterator const &obj) const { return(count <= obj.getNode()); };
            bool operator< (iterator const &obj) const { return(count < obj.getNode()); };
            bool operator> (iterator const &obj) const { return(count > obj.getNode()); };
            bool operator>= (iterator const &obj) const { return(count >= obj.getNode()); };
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