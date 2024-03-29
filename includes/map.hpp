/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:29 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/30 13:59:25 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <iterator>

/*
Красно-черные деревья - один из способов балансировки деревьев.
Красно-черное дерево - это бинарное дерево с следующими свойствами:
1. Каждый узел покрашен либо в черный, либо в красный цвет.
2. Листьями объявляются nullptr-узлы (т.е. "виртуальные" узлы, наследники узлов, которые обычно называют листьями; на них "указывают" NULL указатели). Листья покрашены в черный цвет.
3. Если узел красный, то оба его потомка черны.
4. На всех ветвях дерева, ведущих от его корня к листьям, число черных узлов одинаково.
5. Cамая длинная ветвь от корня к листу не более чем вдвое длиннее любой другой ветви от корня к листу. (балансировка)
Количество черных узлов на ветви от корня до листа называется черной высотой дерева. 
https://habr.com/ru/post/330644/
http://algolist.ru/ds/rbtree.php
http://mech.math.msu.su/~vvb/2course/Borisenko/lecTree.html
https://medium.com/@dimko1/%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D1%8B-%D0%BE%D0%B1%D1%85%D0%BE%D0%B4-%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%B0-ed54848c2d47 - обход дерева
*/

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
    allocator_type _alloc; // алокатор
    key_compare _compare;
    typedef struct Node_
    {
        struct Node_* _left;
        struct Node_* _right;
        struct Node_* _parent;
        bool _color;
        value_type* _data;
    } Node;
    Node* _leaves_left; // листок левый
    Node* _leaves_right; // листок правый
    Node* _head; // родитель
    // ---------------------------------------------------------
    void rotateLeft(Node *x)
    {
        Node *y = x->_right;
        x->_right = y->_left;
        if (y->_left != _leaves_left && y->_left != _leaves_right)
            y->_left->_parent = x;
        if (y != _leaves_left && y != _leaves_right)
            y->_parent = x->_parent;
        if (x->_parent)
        {
            if (x == x->_parent->_left)
                x->_parent->_left = y;
            else
                x->_parent->_right = y;
        } 
        else
        {
            _head = y;
        }
        y->_left = x;
        if (x != _leaves_left && x != _leaves_right)
            x->_parent = y;
    }
    // ---------------------------------------------------------
    void rotateRight(Node *x)
    {
        Node *y = x->_left;
        x->_left = y->_right;
        if (y->_right != _leaves_right && y->_right != _leaves_left)
            y->_right->_parent = x;
        if (y != _leaves_right && y != _leaves_left)
            y->_parent = x->_parent;
        if (x->_parent)
        {
            if (x == x->_parent->_right)
                x->_parent->_right = y;
            else
                x->_parent->_left = y;
        } 
        else
            _head = y;
        y->_right = x;
        if (x != _leaves_right && x != _leaves_left)
            x->_parent = y;
    }
    // ---------------------------------------------------------
    void insertFixup(Node *x)
    {
        while (x != _head && x->_parent->_color == true)
        {
            if (x->_parent == x->_parent->_parent->_left)
            {
                Node *y = x->_parent->_parent->_right;
                if (y->_color == true)
                {
                    x->_parent->_color = false;
                    y->_color = false;
                    x->_parent->_parent->_color = true;
                    x = x->_parent->_parent;
                } 
                else
                {
                    if (x == x->_parent->_right)
                    {
                        x = x->_parent;
                        rotateLeft(x);
                    }
                    x->_parent->_color = false;
                    x->_parent->_parent->_color = true;
                    rotateRight(x->_parent->_parent);
                }
            } 
            else
            {
                Node *y = x->_parent->_parent->_left;
                if (y->_color == true)
                {
                    x->_parent->_color = false;
                    y->_color = false;
                    x->_parent->_parent->_color = true;
                    x = x->_parent->_parent;
                } 
                else
                {
                    if (x == x->_parent->_left) {
                        x = x->_parent;
                        rotateRight(x);
                    }
                    x->_parent->_color = false;
                    x->_parent->_parent->_color = true;
                    rotateLeft(x->_parent->_parent);
                }
            }
        }
        _head->_color = false;
    }
    // ---------------------------------------------------------
    Node *insertNode(const value_type & data)
    {
        Node *parent, *x;
        Node *tmp = _head;
		parent = 0;
        while(tmp != _leaves_right && tmp != _leaves_left)
        {
            if(data.first == tmp->_data->first)
                return(tmp);
            parent = tmp;
            if(data.first < tmp->_data->first)
                tmp = tmp->_left;
            else
                tmp = tmp->_right;
        }
        x = new Node;
        x->_data = _alloc.allocate(1);
        _alloc.construct(x->_data, data);
        x->_parent = parent;
        x->_left = _leaves_left;
        x->_right = _leaves_right;
        x->_color = true; // red
        if(parent)
        {
            if(data.first < parent->_data->first)
                parent->_left = x;
            else
                parent->_right = x;
        }
        else
            _head = x;
        insertFixup(x); // чек балансировка
        _size++;
        return(x);
    }
    // ---------------------------------------------------------
    void deleteFixup(Node *x)
    {
        while (x != _head && x->_color == false)
        {
            if (x == x->_parent->_left)
            {
                Node *w = x->_parent->_right;
                if (w->_color == true)
                {
                    w->_color = false;
                    x->_parent->_color = true;
                    rotateLeft (x->_parent);
                    w = x->_parent->_right;
                }
                if (w->_left->_color == false && w->_right->_color == false)
                {
                    w->_color = true;
                    x = x->_parent;
                } 
                else
                {
                    if (w->_right->_color == false)
                    {
                        w->_left->_color = false;
                        w->_color = true;
                        rotateRight (w);
                        w = x->_parent->_right;
                    }
                    w->_color = x->_parent->_color;
                    x->_parent->_color = false;
                    w->_right->_color = false;
                    rotateLeft (x->_parent);
                    x = _head;
                }
            } 
            else
            {
                Node *w = x->_parent->_left;
                if (w->_color == true)
                {
                    w->_color = false;
                    x->_parent->_color = true;
                    rotateRight (x->_parent);
                    w = x->_parent->_left;
                }
                if (w->_right->_color == false && w->_left->_color == false)
                {
                    w->_color = true;
                    x = x->_parent;
                }
                else
                {
                    if (w->_left->_color == false)
                    {
                        w->_right->_color = false;
                        w->_color = true;
                        rotateLeft (w);
                        w = x->_parent->_left;
                    }
                    w->_color = x->_parent->_color;
                    x->_parent->_color = false;
                    w->_left->_color = false;
                    rotateRight (x->_parent);
                    x = _head;
                }
            }
        }
        x->_color = false;
    }
    // ---------------------------------------------------------
    void deleteNode(Node *z)
    {
        Node *x, *y;
        if (!z || (z == _leaves_right && z == _leaves_left))
            return;
        if (z->_left == _leaves_left || z->_right == _leaves_right)
            y = z;
        else
        {
            y = z->_right;
            while (y->_left != _leaves_left)
                y = y->_left;
        }
        if (y->_left != _leaves_left)
            x = y->_left;
        else
            x = y->_right;
        x->_parent = y->_parent;
        if (y->_parent)
            if (y == y->_parent->_left)
                y->_parent->_left = x;
            else
                y->_parent->_right = x;
        else
            _head = x;
        if (y != z)
            z->_data = y->_data;
        if (y->_color == false)
            deleteFixup (x);
        _alloc.destroy(y->_data);
		_alloc.deallocate(y->_data, 1);
        delete y;
        _size--;
    }
    // ---------------------------------------------------------
    Node *findNode(const key_type& data)
	{
		Node *current = _head;
    	while(current != _leaves_right && current != _leaves_left)
		{
			if(data == current->_data->first)
				return (current);
			else
			{
				if(data < current->_data->first)
					current = current->_left;
				else
					current = current->_right;
			}
		}
		return(current);
	}
    // ---------------------------------------------------------
    Node* find_max(Node *val) const
    {
        Node *tmp = val;
        while(tmp != _leaves_right)
            tmp = tmp->_right;
        return(tmp);
    }
    Node* find_min(Node *val) const
    {
        Node *tmp = val;
        while(tmp != _leaves_left)
            tmp = tmp->_left;
        return(tmp);
    }
    // ---------------------------------------------------------
public:
    explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) // Создает пустой контейнер без элементов.
    {
        _compare = comp;
        _alloc = alloc;
        _size = 0;
        _leaves_left = new Node;
        _leaves_left->_color = true;
        _leaves_left->_left = _leaves_left;
        _leaves_left->_right = _leaves_left;
        _leaves_left->_data = _alloc.allocate(1);
        //
        _leaves_right = new Node;
        _leaves_right->_color = true;
        _leaves_right->_left = _leaves_right;
        _leaves_right->_right = _leaves_right;
        _leaves_right->_data = _alloc.allocate(1);
        _head = _leaves_left;
    }
    template <class InputIterator>
    map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) // Создает контейнер с таким количеством элементов, как диапазон [первый, последний), причем каждый элемент создается из соответствующего ему элемента в этом диапазоне.
    {
        _compare = comp;
        _alloc = alloc;
        _size = 0;
        _leaves_left = new Node;
        _leaves_left->_color = true;
        _leaves_left->_left = _leaves_left;
        _leaves_left->_right = _leaves_left;
        _leaves_left->_data = _alloc.allocate(1);
        _alloc.construct(_leaves_left->_data, std::make_pair(0, 0));
        //
        _leaves_right = new Node;
        _leaves_right->_color = true;
        _leaves_right->_left = _leaves_right;
        _leaves_right->_right = _leaves_right;
        _leaves_right->_data = _alloc.allocate(1);
        _alloc.construct(_leaves_right->_data, std::make_pair(0, 0));
        _head = _leaves_right;
        insert(first, last);
    }
    map (const map& x) // copy construct
    {
        clear();
        *this = x;
    }
    ~map() // destructor
    {
        clear();
        _alloc.destroy(_leaves_left->_data);
		_alloc.deallocate(_leaves_left->_data, 1);
        _alloc.destroy(_leaves_right->_data);
		_alloc.deallocate(_leaves_right->_data, 1);
    }
    map& operator= (const map& x) // оператор присваивания
    {
        clear();

        this->_alloc = x._alloc;
        this->_compare = x._compare;
        _size = 0;
        _leaves_left = new Node;
        _leaves_left->_color = true;
        _leaves_left->_left = _leaves_left;
        _leaves_left->_right = _leaves_left;
        _leaves_left->_data = _alloc.allocate(1);
        _alloc.construct(_leaves_left->_data, std::make_pair(0, 0));
        //
        _leaves_right = new Node;
        _leaves_right->_color = true;
        _leaves_right->_left = _leaves_right;
        _leaves_right->_right = _leaves_right;
        _leaves_right->_data = _alloc.allocate(1);
        _alloc.construct(_leaves_right->_data, std::make_pair(0, 0));
        _head = _leaves_right;
        if(x._size != 0)
        {
            const_iterator first= x.begin();
            const_iterator last = x.end();
            insert(first, last);
        }
        return(*this);
    }
    iterator begin() // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    { 
        Node *tmp = _head;
        while(tmp->_left != _leaves_left)
            tmp = tmp->_left;
        _leaves_left->_parent = tmp;
        iterator x(find_min(_head), _leaves_right, _leaves_left);
        x++;
        return(x);
    } 
    const_iterator begin() const // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    {
        Node *tmp = _head;
        while(tmp->_left != _leaves_left)
            tmp = tmp->_left;
        _leaves_left->_parent = tmp;
        const_iterator x(find_min(_head), _leaves_right, _leaves_left);
        x++;
        return(x);
    }
    reverse_iterator rbegin()  // Возвращает итератор, ссылающийся на последний элемент в контейнере карты
    {
        Node *tmp = _head;
        while(tmp->_right != _leaves_right)
            tmp = tmp->_right;
        _leaves_right->_parent = tmp;
        reverse_iterator x(find_max(_head), _leaves_right, _leaves_left);
        x++;
        return(x);
    }
    const_reverse_iterator rbegin() const // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    {
        Node *tmp = _head;
        while(tmp->_right != _leaves_right)
            tmp = tmp->_right;
        _leaves_right->_parent = tmp;
        const_reverse_iterator x(find_max(_head), _leaves_right, _leaves_left);
        x++;
        return(x);
    }
    iterator end() // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    {
        Node *tmp = _head;
        while(tmp->_right != _leaves_right)
            tmp = tmp->_right;
        _leaves_right->_parent = tmp;
        iterator x(find_max(_head), _leaves_right, _leaves_left);
        return(x);
    }
    const_iterator end() const // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    {
        Node *tmp = _head;
        while(tmp->_right != _leaves_right)
            tmp = tmp->_right;
        _leaves_right->_parent = tmp;
        const_iterator x(find_max(_head), _leaves_right, _leaves_left);
        return(x);
    }
    reverse_iterator rend() // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    {
        Node *tmp = _head;
        while(tmp->_left != _leaves_left)
            tmp = tmp->_left;
        _leaves_left->_parent = tmp;
        reverse_iterator x(find_min(_head), _leaves_right, _leaves_left);
        return(x);
    }
    const_reverse_iterator rend() const //  Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    {
        Node *tmp = _head;
        while(tmp->_left != _leaves_left)
            tmp = tmp->_left;
        _leaves_left->_parent = tmp;
        const_reverse_iterator x(find_min(_head), _leaves_right, _leaves_left);
        return(x);
    }
    bool empty() const // Возвращает, пуст ли контейнер карты (т.е. равен ли его размер 0).
    {
        bool status = true;
		if(_size > 0)
			status = false;
		return(status);
    }
    size_type size() const { return(_size); } // Возвращает количество элементов в контейнере карты.
    size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(Node); } // Возвращает максимальное количество элементов, которое может содержать контейнер карты.
    mapped_type& operator[] (const key_type& k) // оператор индексации
    {
        Node *tmp = findNode(k);
        return(tmp->_data->second);
    }
    std::pair<iterator,bool> insert (const value_type& val) // Расширяет контейнер, вставляя новые элементы, эффективно увеличивая размер контейнера на количество вставленных элементов.
    {
        Node* tmp = insertNode(val);
        return (std::make_pair(tmp, true));
    }
    iterator insert (iterator position, const value_type& val) // Расширяет контейнер, вставляя новые элементы, эффективно увеличивая размер контейнера на количество вставленных элементов.
    {
        (void)position;
        insertNode(val);
        return(position);
    }
    template <class InputIterator>
    void insert (InputIterator first, InputIterator last) // Расширяет контейнер, вставляя новые элементы, эффективно увеличивая размер контейнера на количество вставленных элементов.
    {
        Node *tmp;
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
    size_type erase (const key_type& k) // Удаляет из контейнера карты либо один элемент, либо ряд элементов ([первый, последний)).
    {
        size_type index = _size;
        Node *tmp = findNode(k);
        deleteNode(tmp);
        if(index > _size)
            return(1);
        return(0);
    }
    void erase (iterator first, iterator last) // Удаляет из контейнера карты либо один элемент, либо ряд элементов ([первый, последний)).
    {
        while(first != last)
        {
            erase(first);
            first++;
        }
    }
    void swap (map& x) // Меняет содержимое контейнера на содержимое x, которое является другой картой того же типа. Размеры могут отличаться.
    {
        Node *tmp2 = this->_head;
        Node *leav_left = this->_leaves_left;
        Node *leav_right = this->_leaves_right;
        size_type size2 = this->_size;
        allocator_type alloc2 = this->_alloc;
        key_compare compare2 = this->_compare;
        
        this->_head = x._head;
        this->_leaves_left = x._leaves_left;
        this->_leaves_right = x._leaves_right;
        this->_size = x._size;
        this->_alloc = x._alloc;
        this->_compare = x._compare;

        x._head = tmp2;
        x._leaves_left = leav_left;
        x._leaves_right = leav_right;
        x._size = size2;
        x._alloc = alloc2;
        x._compare = compare2;
    }
    void clear() // Удаляет все элементы из контейнера карты (которые уничтожаются), оставляя контейнер с размером 0.
    {
        while(_size != 0)
            erase(begin());
    }
    value_compare value_comp() const { return value_compare(_compare); }; // Возвращает объект сравнения, который можно использовать для сравнения двух элементов, чтобы узнать, идет ли ключ первого элемента раньше второго.
    iterator find (const key_type& k) { return(iterator(findNode(k))); } // Ищет в контейнере элемент с ключом, эквивалентным k, и возвращает ему итератор, если он найден, в противном случае он возвращает итератор для map :: end.
    const_iterator find (const key_type& k) const { return(const_iterator(findNode(k))); } // Ищет в контейнере элемент с ключом, эквивалентным k, и возвращает ему итератор, если он найден, в противном случае он возвращает итератор для map :: end.
    size_type count (const key_type& k) const // Ищет в контейнере элементы с ключом, эквивалентным k, и возвращает количество совпадений.
    {
        Node *current = _head;
    	while(current != _leaves_right && current != _leaves_left)
		{
			if(k == current->_data->first)
				return (1);
			else
			{
				if(k < current->_data->first)
					current = current->_left;
				else
					current = current->_right;
			}
		}
		return(0);
    }
    iterator lower_bound (const key_type& k) // Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого не считается предшествующим k (то есть либо эквивалентным, либо идущим после).
    {
		iterator it = begin();
		iterator ite = end();
        iterator tmp = begin();
        while(it != ite)
        {
            tmp++;
            if(tmp->first > k)
                return(it);
            it++;
        }
		return (it);
    }
    const_iterator lower_bound (const key_type& k) const // Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого не считается предшествующим k (то есть либо эквивалентным, либо идущим после).
    {
        iterator it = begin();
		iterator ite = end();
        iterator tmp = begin();
        while(it != ite)
        {
            tmp++;
            if(tmp->first > k)
                return(it);
            it++;
        }
		return (it);
    }
    iterator upper_bound (const key_type& k)   // Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого считается идущим после k.
    {
        iterator it = begin();
		iterator ite = end();
        while(it != ite)
        {
            if(it->first > k)
                return(it);
            it++;
        }
		return (it);
    }
    const_iterator upper_bound (const key_type& k) const // Возвращает итератор, указывающий на первый элемент в контейнере, ключ которого считается идущим после k.
    {
        iterator it = begin();
		iterator ite = end();
        while(it != ite)
        {
            if(it->first > k)
                return(it);
            it++;
        }
		return (it);
    }
    std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return std::make_pair(lower_bound(k), upper_bound(k)); }; // Возвращает границы диапазона, который включает все элементы в контейнере с ключом, эквивалентным k.
    std::pair<iterator,iterator> equal_range (const key_type& k) { return std::make_pair(lower_bound(k), upper_bound(k)); };  // Возвращает границы диапазона, который включает все элементы в контейнере с ключом, эквивалентным k.

    class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
    {
        private:
            Node *count;
            Node *leaves_left;
            Node *leaves_right;
            Node* minimalNode(Node* val) // указатель на вершину поддерева
            {
                Node* x = val;
                while (x != leaves_left && x->_left != leaves_left && x != leaves_right && x->_left != leaves_right)
                {
                    x = x->_left;
                }
                return (x);
            }
            Node* nextNode(Node* val)
            {
                if(val->_right != leaves_left)
                {
                    return(minimalNode(val->_right));
                }
                else if(val == val->_parent->_left)
                {
                    return(val->_parent);
                }
                else
                {
                    Node *x = val->_parent;
                    while(x == x->_parent->_right)
                    {
                        x = x->_parent;
                    }
                    if(x == x->_parent->_left)
                        return(x->_parent);
                }
                return(val);
            }
            Node* maximalNode(Node* val) // указатель на вершину поддерева
            {
                Node* x = val;
                while (x != leaves_left && x != leaves_right && x->_right != leaves_right && x->_right != leaves_left)
                {
                    x = x->_right;
                }
                return (x);
            }
            Node* prevNode(Node* val)
            {
                if(val->_left != leaves_left && val->_left != leaves_right)
                {
                    return(maximalNode(val->_left));
                }
                else if(val == val->_parent->_right)
                {
                    return(val->_parent);
                }
                else
                {
                    Node *x = val->_parent;
                    while (x == x->_parent->_left)
                        x = x->_parent;
                    if (x->_parent != leaves_left && x->_parent != leaves_right)
                        return x->_parent;
                }
                return(val);
            }
        public:
            explicit iterator(Node *val = 0, Node *right = 0, Node *left = 0)
            {
                this->count = val;
                this->leaves_right = right;
                this->leaves_left = left;
            }
            ~iterator() { };
			iterator(const iterator &obj) { *this = obj; }
            iterator &operator=(const iterator &obj)
            {
                this->count = obj.count;
                this->leaves_right = obj.leaves_right;
                this->leaves_left = obj.leaves_left;
                return(*this);
            }
			iterator & operator++()
			{
                count = nextNode(count);
                return(*this);
			}
			iterator operator++(int)
			{
                count = nextNode(count);
                return(iterator(count));
			}
			iterator & operator--()
			{
                count = prevNode(count);
                return(*this);
			}
			iterator operator--(int)
			{
                count = prevNode(count);
                return(iterator(count));
			}
            value_type &operator*() const
            {
                return(*(this->count->_data));
            }
            value_type *operator->()
		    {
			    return (this->count->_data);
		    }
            Node* getNode() const { return(count); }
            bool operator!= (iterator const &obj) const { return(count != obj.count); };
            bool operator== (iterator const &obj) const { return(count == obj.count); };
            bool operator<= (iterator const &obj) const { return(count <= obj.count); };
            bool operator< (iterator const &obj) const { return(count < obj.count); };
            bool operator> (iterator const &obj) const { return(count > obj.count); };
            bool operator>= (iterator const &obj) const { return(count >= obj.count); };
    };
	class const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type const>
    {
        private:
            Node *count;
            Node *leaves_left;
            Node *leaves_right;
            Node* minimalNode(Node* val) // указатель на вершину поддерева
            {
                Node* x = val;
                while (x != leaves_left && x->_left != leaves_left && x != leaves_right && x->_left != leaves_right)
                {
                    x = x->_left;
                }
                return (x);
            }
            Node* nextNode(Node* val)
            {
                if(val->_right != leaves_left)
                {
                    return(minimalNode(val->_right));
                }
                else if(val == val->_parent->_left)
                {
                    return(val->_parent);
                }
                else
                {
                    Node *x = val->_parent;
                    while(x == x->_parent->_right)
                    {
                        x = x->_parent;
                    }
                    if(x == x->_parent->_left)
                        return(x->_parent);
                }
                return(val);
            }
            Node* maximalNode(Node* val) // указатель на вершину поддерева
            {
                Node* x = val;
                while (x != leaves_left && x != leaves_right && x->_right != leaves_right && x->_right != leaves_left)
                {
                    x = x->_right;
                }
                return (x);
            }
            Node* prevNode(Node* val)
            {
                if(val->_left != leaves_left && val->_left != leaves_right)
                {
                    return(maximalNode(val->_left));
                }
                else if(val == val->_parent->_right)
                {
                    return(val->_parent);
                }
                else
                {
                    Node *x = val->_parent;
                    while (x == x->_parent->_left)
                        x = x->_parent;
                    if (x->_parent != leaves_left && x->_parent != leaves_right)
                        return x->_parent;
                }
                return(val);
            }
        public:
            explicit const_iterator(Node *val = 0, Node *right = 0, Node *left = 0)
            {
                this->count = val;
                this->leaves_right = right;
                this->leaves_left = left;
            }
            ~const_iterator() { };
			const_iterator(const const_iterator &obj) { *this = obj; }
            const_iterator &operator=(const const_iterator &obj)
            {
                this->count = obj.count;
                this->leaves_right = obj.leaves_right;
                this->leaves_left = obj.leaves_left;
                return(*this);
            }
			const_iterator & operator++()
			{
                count = nextNode(count);
                return(*this);
			}
			const_iterator operator++(int)
			{
                count = nextNode(count);
                return(const_iterator(count));
			}
			const_iterator & operator--()
			{
                count = prevNode(count);
                return(*this);
			}
			const_iterator operator--(int)
			{
                count = prevNode(count);
                return(const_iterator(count));
			}
            value_type &operator*() const
            {
                return(*(this->count->_data));
            }
            value_type *operator->() const
		    {
			    return (this->count->_data);
		    }
            Node* getNode() const { return(count); }
            bool operator!= (const_iterator const &obj) const { return(count != obj.count); };
            bool operator== (const_iterator const &obj) const { return(count == obj.count); };
            bool operator<= (const_iterator const &obj) const { return(count <= obj.count); };
            bool operator< (const_iterator const &obj) const { return(count < obj.count); };
            bool operator> (const_iterator const &obj) const { return(count > obj.count); };
            bool operator>= (const_iterator const &obj) const { return(count >= obj.count); };
    };
	class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type>
    {
        private:
            Node *count;
            Node *leaves_left;
            Node *leaves_right;
            Node* minimalNode(Node* val) // указатель на вершину поддерева
            {
                Node* x = val;
                while (x != leaves_left && x->_left != leaves_left && x != leaves_right && x->_left != leaves_right)
                {
                    x = x->_left;
                }
                return (x);
            }
            Node* nextNode(Node* val)
            {
                if(val->_right != leaves_left)
                {
                    return(minimalNode(val->_right));
                }
                else if(val == val->_parent->_left)
                {
                    return(val->_parent);
                }
                else
                {
                    Node *x = val->_parent;
                    while(x == x->_parent->_right)
                    {
                        x = x->_parent;
                    }
                    if(x == x->_parent->_left)
                        return(x->_parent);
                }
                return(val);
            }
            Node* maximalNode(Node* val) // указатель на вершину поддерева
            {
                Node* x = val;
                while (x != leaves_left && x != leaves_right && x->_right != leaves_right && x->_right != leaves_left)
                {
                    x = x->_right;
                }
                return (x);
            }
            Node* prevNode(Node* val)
            {
                if(val->_left != leaves_left && val->_left != leaves_right)
                {
                    return(maximalNode(val->_left));
                }
                else if(val == val->_parent->_right)
                {
                    return(val->_parent);
                }
                else
                {
                    Node *x = val->_parent;
                    while (x == x->_parent->_left)
                        x = x->_parent;
                    if (x->_parent != leaves_left && x->_parent != leaves_right)
                        return x->_parent;
                }
                return(val);
            }
        public:
            explicit reverse_iterator(Node *val = 0, Node *right = 0, Node *left = 0)
            {
                this->count = val;
                this->leaves_right = right;
                this->leaves_left = left;
            }
            ~reverse_iterator() { };
			reverse_iterator(const reverse_iterator &obj) { *this = obj; }
            reverse_iterator &operator=(const reverse_iterator &obj)
            {
                this->count = obj.count;
                this->leaves_right = obj.leaves_right;
                this->leaves_left = obj.leaves_left;
                return(*this);
            }
			reverse_iterator & operator++()
			{
                count = prevNode(count);
                return(*this);
			}
			reverse_iterator operator++(int)
			{
                count = prevNode(count);
                return(reverse_iterator(count));
			}
			reverse_iterator & operator--()
			{
                count = nextNode(count);
                return(*this);
			}
			reverse_iterator operator--(int)
			{
                count = nextNode(count);
                return(reverse_iterator(count));
			}
            value_type &operator*() const
            {
                return(*(this->count->_data));
            }
            value_type *operator->()
		    {
			    return (this->count->_data);
		    }
            Node* getNode() const { return(count); }
            bool operator!= (reverse_iterator const &obj) const { return(count != obj.count); };
            bool operator== (reverse_iterator const &obj) const { return(count == obj.count); };
            bool operator<= (reverse_iterator const &obj) const { return(count <= obj.count); };
            bool operator< (reverse_iterator const &obj) const { return(count < obj.count); };
            bool operator> (reverse_iterator const &obj) const { return(count > obj.count); };
            bool operator>= (reverse_iterator const &obj) const { return(count >= obj.count); };
    };
	class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type const>
    {
    private:
            Node *count;
            Node *leaves_left;
            Node *leaves_right;
            Node* minimalNode(Node* val) // указатель на вершину поддерева
            {
                Node* x = val;
                while (x != leaves_left && x->_left != leaves_left && x != leaves_right && x->_left != leaves_right)
                {
                    x = x->_left;
                }
                return (x);
            }
            Node* nextNode(Node* val)
            {
                if(val->_right != leaves_left)
                {
                    return(minimalNode(val->_right));
                }
                else if(val == val->_parent->_left)
                {
                    return(val->_parent);
                }
                else
                {
                    Node *x = val->_parent;
                    while(x == x->_parent->_right)
                    {
                        x = x->_parent;
                    }
                    if(x == x->_parent->_left)
                        return(x->_parent);
                }
                return(val);
            }
            Node* maximalNode(Node* val) // указатель на вершину поддерева
            {
                Node* x = val;
                while (x != leaves_left && x != leaves_right && x->_right != leaves_right && x->_right != leaves_left)
                {
                    x = x->_right;
                }
                return (x);
            }
            Node* prevNode(Node* val)
            {
                if(val->_left != leaves_left && val->_left != leaves_right)
                {
                    return(maximalNode(val->_left));
                }
                else if(val == val->_parent->_right)
                {
                    return(val->_parent);
                }
                else
                {
                    Node *x = val->_parent;
                    while (x == x->_parent->_left)
                        x = x->_parent;
                    if (x->_parent != leaves_left && x->_parent != leaves_right)
                        return x->_parent;
                }
                return(val);
            }
        public:
            explicit const_reverse_iterator(Node *val = 0, Node *right = 0, Node *left = 0)
            {
                this->count = val;
                this->leaves_right = right;
                this->leaves_left = left;
            }
            ~const_reverse_iterator() { };
			const_reverse_iterator(const const_reverse_iterator &obj) { *this = obj; }
            const_reverse_iterator &operator=(const const_reverse_iterator &obj)
            {
                this->count = obj.count;
                this->leaves_right = obj.leaves_right;
                this->leaves_left = obj.leaves_left;
                return(*this);
            }
			const_reverse_iterator & operator++()
			{
                count = prevNode(count);
                return(*this);
			}
			const_reverse_iterator operator++(int)
			{
                count = prevNode(count);
                return(const_reverse_iterator(count));
			}
			const_reverse_iterator & operator--()
			{
                count = nextNode(count);
                return(*this);
			}
			const_reverse_iterator operator--(int)
			{
                count = nextNode(count);
                return(const_reverse_iterator(count));
			}
            value_type &operator*() const
            {
                return(*(this->count->_data));
            }
            value_type *operator->() const
		    {
			    return (this->count->_data);
		    }
            Node* getNode() const { return(count); }
            bool operator!= (const_reverse_iterator const &obj) const { return(count != obj.count); };
            bool operator== (const_reverse_iterator const &obj) const { return(count == obj.count); };
            bool operator<= (const_reverse_iterator const &obj) const { return(count <= obj.count); };
            bool operator< (const_reverse_iterator const &obj) const { return(count < obj.count); };
            bool operator> (const_reverse_iterator const &obj) const { return(count > obj.count); };
            bool operator>= (const_reverse_iterator const &obj) const { return(count >= obj.count); };
    };
    class value_compare : public std::binary_function<value_type, value_type, bool>
    {
        private:
            key_compare _compare;
        public:
            value_compare(key_compare n)
            {
                this->_compare = n;
            }
            bool operator()(const value_type &val1, const value_type &val2) const { return comp(val1.first, val2.first); };
    };
};

};
#endif