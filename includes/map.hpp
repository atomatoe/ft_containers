/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:13:29 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/24 21:43:18 by atomatoe         ###   ########.fr       */
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

namespace ft
{
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<T> >
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
        Node *_parent; // указатель на родителя (предшественника)
        Node *_left; // указатель на левую часть дерева
        Node *_right; // указатель на правую часть дерева
        bool _color; // black/red статус, black = false, red = true
        T _data; // значение
        Node(T value = T(), Node *parent = nullptr, bool color = nullptr, Node *left = nullptr, Node *right = nullptr)
        {
            this->_left = left;
            this->_right = right;
            this->_parent = parent;
            this->_color = color;
            this->_data = value;
        }
    };
    Node *head; // родитель
    size_type _size; // размер дерева
    allocator_type _alloc;
public:
	// --------------------------------------------------------- // поворот влево дерева
    void rotateLeft(Node *x)
    {
        Node *y = x->_right;
		x->_right = y->_left;
		if(y->_left != nullptr)
			y->_left->_parent = x;
		if(y != nullptr)
			y->_parent = x->_parent;
		if(x->_parent)
		{
			if (x == x->_parent->_left)
            	x->_parent->_left = y;
        	else
            	x->_parent->_right = y;
		}
		else
			head = y;
		y->_left = x;
		if(x != nullptr)
			x->_parent = y;
    }
    // --------------------------------------------------------- // поворот вправо дерева
    void rotateRight(Node *x)
    {
        Node *y = x->_left;
        x->_left = y->_right;
        if(y->_right != nullptr)
            y->_right->_parent = x;
        if(y != nullptr)
			y->_parent = x->_parent;
		if(x->_parent)
		{
			if(x == x->_parent->_right)
				x->_parent->_right = y;
			else
				x->_parent->_left = y;
		}
		else
			head = y;
		y->_right = x;
		if(x != nullptr)
			x->_parent = y;
    }
    // --------------------------------------------------------- // фикс - балансировка дерева
    void insertFixup(Node *x)
    {
        while(x != head && x->_parent->_color == true)
        {
            if(x->_parent == x->_parent->_parent->_left)
            {
                Node *y = x->_parent->_parent->_right;
                if(y->_color == true)
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
                if(y->_color == true)
                {
                    x->_parent->_color = false;
                    y->_color = false;
                    x->_parent->_parent->_color = true;
                    x = x->_parent->_parent;
                }
                else
                {
                    if (x == x->_parent->_left)
                    {
                        x = x->_parent;
                        rotateRight(x);
                    }
                    x->_parent->_color = false;
                    x->_parent->_parent->_color = true;
                    rotateLeft(x->_parent->_parent);
                }
            }
        }
        head->_color = false;
    }
    // --------------------------------------------------------- // добавление элемента
    Node *insertNode(T data)
    {
        Node *parent, *x;
        Node *tmp = head;
		parent = 0;
        while(tmp != nullptr)
        {
            if(data == tmp->_data)
                return(tmp);
            parent = tmp;
            if(data < tmp->_data)
                tmp = tmp->_left;
            else
                tmp = tmp->_right;
        }
        x = new Node(data);
        x->_parent = parent;
        x->_left = nullptr;
        x->_right = nullptr;
        x->_color = true; // red
        if(parent)
        {
            if(data < parent->_data)
                parent->_left = x;
            else
                parent->_right = x;
        }
        else
            head = x;
        insertFixup(x);
        return(x);
    }
    // --------------------------------------------------------- // балансировка при удалении
	void deleteFixup(Node *x)
	{
		while(x != head && x->_color == false)
		{
			if(x == x->_parent->_left)
			{
				Node *w = x->_parent->_right;
				if(w->_color == true)
				{
					w->_color = false;
					x->_parent->_color = true;
					rotateLeft(x->_parent);
					w = w->_parent->_right;
				}
				if(w->_left->_color == false && w->_right->_color == false)
				{
					w->_color = true;
					x = x->_parent;
				}
				else
				{
					if(w->_right->_color == false)
					{
						w->_left->_color = false;
						w->_color = true;
						rotateRight(w);
						w = x->_parent->_right;
					}
					w->_color = x->_parent->_color;
					x->_parent->_color = false;
					w->_right->_color = false;
					rotateLeft(x->_parent);
					x = head;
				}
			}
			else
			{
				Node *w = x->_parent->_left;
				if(w->_color == true)
				{
					w->_color = false;
					x->_parent->_color = true;
					rotateRight(x->_parent);
					w = x->_parent->_left;
				}
				if(w->_right->_color == false && w->_left->_color == false)
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
					x = head;
				}
			}
		}
		x->_color = false;
	}
	// --------------------------------------------------------- // удаление элемента
	void deleteNode(Node *z)
	{
		Node *x, *y;
		if (!z || z == nullptr)
			return;
		if (z->l_eft == nullptr || z->_right == nullptr)
			y = z;
		else
		{
			y = z->_right;
			while (y->_left != nullptr) y = y->_left;
		}
		if (y->_left != nullptr)
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
			head = x;
		if (y != z) z->_data = y->_data;
		if (y->_color == false)
			deleteFixup (x);
		delete y;
	}
	// --------------------------------------------------------- // поиск элемента
	Node *findNode(T data)
	{
		Node *current = head;
    	while(current != nullptr)
			{
			if(data == current->_data)
				return (current);
			else
			{
				if(data < current->_data)
					current = current->_left;
				else
					current = current->_right;
			}
		}
		return(0);
	}
	// ---------------------------------------------------------
    void my_print()
    {
        std::cout << std::endl;
        Node *tmp = head;
        while(tmp != nullptr)
        {
            std::cout << "left = " << tmp->_data << std::endl;
            tmp = tmp->_left;
        }
        tmp = head;
        std::cout << std::endl;
        while(tmp != nullptr)
        {
            std::cout << "right = " << tmp->_data << std::endl;
            tmp = tmp->_right;
        }
        std::cout << std::endl;
        std::cout << "size = " << _size << std::endl;
    }
    explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) // Создает пустой контейнер без элементов.
    {
        _alloc = alloc;
        head = nullptr;
    }
    template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()); // Создает контейнер с таким количеством элементов, как диапазон [первый, последний), причем каждый элемент создается из соответствующего ему элемента в этом диапазоне.
    map (const map& x) // copy construct
    {
        *this = x;
    }
    ~map() // destructor
    {

    }
    map& operator= (const map& x) // оператор присваивания
    {
        this->head = x.head;
        this->_size = x._size;
        this->_alloc = x._alloc;
    }
    iterator begin() { return(&this->head->_data); }  // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    const_iterator begin() const { return(&this->head->_data); } // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    reverse_iterator rbegin();  // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    const_reverse_iterator rbegin() const; // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    iterator end(); // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    const_iterator end() const; // Возвращает итератор, ссылающийся на последний элемент в контейнере карты.
    reverse_iterator rend() { return(&this->head->_data); } // Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    const_reverse_iterator rend() const { return(&this->head->_data); }  //  Возвращает итератор, ссылающийся на первый элемент в контейнере карты.
    bool empty() const // Возвращает, пуст ли контейнер карты (т.е. равен ли его размер 0).
    {
        bool status = true;
		if(_size > 0)
			status = false;
		return(status);
    }
    size_type size() const { return(_size); } // Возвращает количество элементов в контейнере карты.
    size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(Node); } // Возвращает максимальное количество элементов, которое может содержать контейнер карты.
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
        private:
            Node *count;
			Node* find_max()
			{
				Node *tmp = count;
				while(tmp != nullptr)
					tmp = tmp->_right;
				return(tmp);
			}
			Node* find_min()
			{
				Node *tmp = count;
				while(tmp != nullptr)
					tmp = tmp->_left;
				return(tmp);
			}
        public:
            explicit iterator(Node *head = nullptr) { this->count = head; }
            ~iterator() { };
			iterator(const iterator &obj) { *this = obj; }
            iterator &operator=(const iterator &obj)
            {
                this->count = obj.count;
                return(*this);
            }
			iterator & operator++();
			iterator operator++(int);
			iterator & operator--();
			iterator operator--(int);
            T &operator*() const { return(this->count->data); }
            T *operator&() const { return(*(this->count->data)); }
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
        private:

        public:
        
    };
	class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
        private:

        public:
        
    };
	class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
        private:

        public:
        
    };
    class value_compare : public std::binary_function<value_type, value_type, bool>
    {
        private:

        public:
        
    };
};

};
#endif