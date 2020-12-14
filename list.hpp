/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:45:17 by atomatoe          #+#    #+#             */
/*   Updated: 2020/12/14 23:43:08 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include <deque>

namespace ft
{
template < class T, class Alloc = std::allocator<T> >
class list
{
private:
    class Node
    {
    public:
        Node *next;
        T data;
        Node(T value = T(), Node *next2 = nullptr)
        {
            this->data = value;
            this->next = next2;
            // std::cout << data << std::endl;
        }
    };
    int len; // размер списка
    Node *head; // первый список

public:
    typedef T           value_type;
    typedef Alloc       allocator_type;
    typedef size_t		size_type;
    // typedef const T &reference;
    // typedef const T &const_reference;
    // typedef const T &pointer;
    // typedef const T &const_pointer;

    /*                  DELETED MY FUNK                  */
    void my_print()
    {
        std::cout << head->data << std::endl;
        std::cout << head->next->data << std::endl;
        std::cout << head->next->next->data << std::endl;
        // std::cout << head->next->next->next->data << std::endl;
    }

    explicit list (const allocator_type& alloc = allocator_type()) // Создает пустой контейнер без элементов.
    {
        len = 0;
        head = nullptr;
    };
    explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) // Создает контейнер из n элементов. Каждый элемент является копией val .
    {
        for(int i = 0; i < n; i++)
            push_back(val);
    }
    template <class InputIterator> list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); // Создает контейнер с таким количеством элементов, как диапазон [первый, последний) , причем каждый элемент создается из соответствующего ему элемента в этом диапазоне в том же порядке.
    list (const list& x) // Создает контейнер с копией каждого из элементов в x в том же порядке.
    {
        *this = x;
    }
    ~list() // деструктор
    {
        
    }
    list& operator= (const list& x) // оператор присваивания
    {
        if(x.head != nullptr)
        {
            head = x.head;
            len = x.len;
        }
        else
        {
            len = 0;
            head = nullptr;
        }
        return(*this);
    }
    bool empty() const // Возвращает true, если list пуст	
    {
        bool status = true;
		if(len > 0)
			status = false;
		return(status);
    }
    size_type size() const // Возвращает количество элементов в контейнере списка.
    {
        return(len);
    }
    size_type max_size() const; // Возвращает максимальное количество элементов, которое может содержать контейнер списка.
    void push_front (const value_type& val) // Вставляет новый элемент в начало списка , прямо перед его текущим первым элементом. Содержимое val копируется (или перемещается) во вставленный элемент.
    {
        Node *tmp = head;
        head = new Node(val);
        head->next = tmp;
        delete tmp;
        len++;
    }
    void pop_front() // Удаляет первый элемент в контейнере списка , эффективно уменьшая его размер на единицу.
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        len--;
    }
    void push_back (const value_type& val) // Добавляет новый элемент в конец контейнера списка после его текущего последнего элемента. Содержимое val копируется (или перемещается) в новый элемент.
    {
        if(head == nullptr)
            head = new Node(val);
        else
        {
            Node *current = head;
            while(current->next != nullptr)
                current = current->next;
            current->next = new Node(val);
        }
        len++;
    }
    void pop_back(); // Удаляет последний элемент в контейнере списка , эффективно уменьшая размер контейнера на единицу.
    void swap (list& x); // Меняет содержимое контейнера содержимым x , который является другим списком того же типа. Размеры могут отличаться.
    void resize (size_type n, value_type val = value_type()); // Изменяет размер контейнера, чтобы он содержал n элементов.
    void clear(); // Удаляет все элементы из списка контейнера (которые разрушены), и оставляя контейнер с размером от 0 .
    void remove (const value_type& val); // Удаляет из контейнера все элементы, равные val . Это вызывает деструктор этих объектов и уменьшает размер контейнера на количество удаленных элементов.
    void unique(); // Версия без параметров (1) удаляет все элементы, кроме первого, из каждой последующей группы равных элементов в контейнере.
    void merge (list& x); // Объединяет x в список , передавая все его элементы в соответствующие упорядоченные позиции в контейнер (оба контейнера уже должны быть упорядочены).
    void sort(); //  Сортирует элементы в списке , изменяя их положение в контейнере.
    void reverse(); // Изменяет порядок элементов в контейнере списка. Обратный порядок элементов.
    
    class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    public:
        iterator begin(); // Возвращает итератор, указывающий на первый элемент в контейнере списка .
        iterator end(); // Возвращает итератор, относящийся к последнему элементу в контейнере списка .
        iterator insert (iterator position, const value_type& val); // https://www.cplusplus.com/reference/list/list/insert/
        iterator erase (iterator position); // Удаляет из контейнера списка либо один элемент ( позицию ), либо диапазон элементов ( [первый, последний) ).
        iterator erase (iterator first, iterator last); // Удаляет из контейнера списка либо один элемент ( позицию ), либо диапазон элементов ( [первый, последний) ).
    };

    void insert (iterator position, size_type n, const value_type& val); // https://www.cplusplus.com/reference/list/list/insert/
    void splice (iterator position, list& x); // Переносит элементы из x в контейнер, вставляя их в позицию . Первая версия (1) передает все элементы й в контейнер.
    void splice (iterator position, list& x, iterator i); // Второй вариант (2) передает только элемент указываемого I от й в контейнер.
    void splice (iterator position, list& x, iterator first, iterator last); // Третий вариант (3) передает диапазон [первый, последний) из й в контейнер.  

    class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    public:
        const_iterator begin() const; // Возвращает итератор, указывающий на первый элемент в контейнере списка .
        const_iterator end() const; // Возвращает итератор, относящийся к последнему элементу в контейнере списка .
    };

    class reference : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    public:
        reference front(); // Возвращает ссылку на первый элемент в контейнере списка .
        reference back(); // Возвращает ссылку на последний элемент в контейнере списка .
    };

    class const_reference : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    public:
        const_reference front() const; // Возвращает ссылку на первый элемент в контейнере списка .
        const_reference back() const; // Возвращает ссылку на последний элемент в контейнере списка .
    };
    
    class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    public:
        reverse_iterator rbegin(); // Возвращает обратный итератор, указывающий на последний элемент в контейнере (т.е. его обратное начало ). Обратные итераторы выполняют итерацию в обратном направлении: при увеличении их числа они перемещаются к началу контейнера.
        reverse_iterator rend(); // Возвращает обратный итератор, указывающий на теоретический элемент, предшествующий первому элементу в контейнере списка (который считается его обратным концом ).
    };

    class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    public:
        const_reverse_iterator rbegin() const;  // Возвращает обратный итератор, указывающий на последний элемент в контейнере (т.е. его обратное начало ). Обратные итераторы выполняют итерацию в обратном направлении: при увеличении их числа они перемещаются к началу контейнера.
        const_reverse_iterator rend() const; // Возвращает обратный итератор, указывающий на теоретический элемент, предшествующий первому элементу в контейнере списка (который считается его обратным концом ).
    };

    void assign (size_type n, const value_type& val); // В версии заполнения (2) новое содержимое - это n элементов, каждый из которых инициализирован копией val.

    template <class InputIterator>
        void assign (InputIterator first, InputIterator last); // В версии диапазона (1) новое содержимое - это элементы, составленные из каждого из элементов в диапазоне от первого до последнего в том же порядке.

    template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last); // https://www.cplusplus.com/reference/list/list/insert/

    template <class Predicate>
        void remove_if (Predicate pred);


    /* unique       Вторая версия (2) принимает в качестве аргумента конкретную функцию сравнения, которая определяет «уникальность» элемента. 
    Фактически, можно реализовать любое поведение (и не только сравнение на равенство), но обратите внимание, 
    что функция вызовет binary_pred (* i, * (i-1)) для всех пар элементов (где i - итератор элемента , начиная со второго) и удалите i из списка, 
    если предикат возвращает истину . */
    template <class BinaryPredicate>
        void unique (BinaryPredicate binary_pred);
    

    template <class Compare>
        void merge (list &x, Compare comp); // Версии шаблона с двумя параметрами (2) имеют одинаковое поведение, но используют определенный предикат ( comp ) для выполнения операции сравнения между элементами. 

    template <class Compare>
        void sort (Compare comp); // Сортировка выполняется путем применения алгоритма, который использует оператор < (в версии (1) ) или comp (в версии (2) ) для сравнения элементов. 
};

    template <class T, class Alloc>
        bool operator==(const list<T,Alloc>& x, const list<T,Alloc>& y);

    template <class T, class Alloc>
        bool operator< (const list<T,Alloc>& x, const list<T,Alloc>& y);

    template <class T, class Alloc>
        bool operator!=(const list<T,Alloc>& x, const list<T,Alloc>& y);

    template <class T, class Alloc>
        bool operator> (const list<T,Alloc>& x, const list<T,Alloc>& y);

    template <class T, class Alloc>
        bool operator>=(const list<T,Alloc>& x, const list<T,Alloc>& y);

    template <class T, class Alloc>
        bool operator<=(const list<T,Alloc>& x, const list<T,Alloc>& y);

    template <class T, class Alloc>
        void swap (list<T,Alloc>& x, list<T,Alloc>& y); // Содержимое контейнера x обменивается с содержимым y . Оба объекта-контейнера должны быть одного типа (одинаковые параметры шаблона), хотя размеры могут отличаться.
};

#endif