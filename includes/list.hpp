/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:45:17 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/23 23:11:20 by atomatoe         ###   ########.fr       */
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
public:
    class               iterator;
    class               const_iterator;
    class               reverse_iterator;
    class               const_reverse_iterator;
    typedef size_t		size_type;
    typedef ptrdiff_t 	difference_type;
    typedef T           value_type;
    typedef Alloc       allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
private:
    class Node
    {
    public:
        Node *next;
        Node *prev;
        T data;
        Node(T value = T(), Node *next2 = nullptr, Node *prev2 = nullptr)
        {
            this->data = value;
            this->next = next2;
            this->prev = prev2;
        }
    };
    size_type len; // размер списка
    allocator_type _alloc;
    Node *head; // первый список

public:
    explicit list (const allocator_type& alloc = allocator_type()) // Создает пустой контейнер без элементов.
    {
        len = 0;
        head = nullptr;
        _alloc = alloc;
    };
    explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) // Создает контейнер из n элементов. Каждый элемент является копией val .
    {
        _alloc = alloc;
        for(size_type i = 0; i < n; i++)
            push_front(val);
    }
    template <class InputIterator>
    list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) // Создает контейнер с таким количеством элементов, как диапазон [первый, последний) , причем каждый элемент создается из соответствующего ему элемента в этом диапазоне в том же порядке.
    {
        _alloc = alloc;
		InputIterator tmp = first;
		size_type i = 0;
		while(tmp != last)
		{
			i++;
			tmp++;
		}
        for(size_type t = 0; t < i; ++i)
            push_front(*first++);
    }
    list (const list& x) // Создает контейнер с копией каждого из элементов в x в том же порядке.
    {
        _alloc = x._alloc;
        for(size_type i = 0; i < x.len; i++)
            push_front(x.head->data);
    }
    ~list() // деструктор
    {
        clear();
    }
    list& operator= (const list& x) // оператор присваивания
    {
        if(head != nullptr)
            clear();
        Node *tmp = x.head;
        while(tmp != nullptr)
        {
            push_front(tmp->data);
            tmp = tmp->next;
        }
        len = x.len;
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
    size_type max_size() const // Возвращает максимальное количество элементов, которое может содержать контейнер списка.
    {
        return std::numeric_limits<size_type>::max() / sizeof(Node);
    }
    void push_front (const value_type& val) // Вставляет новый элемент в начало списка , прямо перед его текущим первым элементом. Содержимое val копируется (или перемещается) во вставленный элемент.
    {
        Node *tmp = head;
        head = new Node(val);
        head->next = tmp;
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
            {
                current = current->next;
            }
            current->next = new Node(val);
            current->next->prev = current;
        }
        len++;
    }
    void pop_back() // Удаляет последний элемент в контейнере списка , эффективно уменьшая размер контейнера на единицу.
    {
        if (head == NULL)
            return;
        Node *tmp;
        tmp = head;
        while(tmp->next->next)
            tmp = tmp->next;
        delete tmp->next;
        tmp->next = NULL;
        len--;
    }
    void swap (list& x) // Меняет содержимое контейнера содержимым x , который является другим списком того же типа. Размеры могут отличаться.
    {
        Node *tmp = this->head;
		this->head = x.head;
		x.head = tmp;

		size_type len = this->len;
		this->len = x.size();
		x.len = len;
    }
    void resize (size_type n, value_type val = value_type()) // Изменяет размер контейнера, чтобы он содержал n элементов.
    {
        if(n > len)
		{
            while(len != n)
                push_back(val);
		}
        else if(n < len)
        {
            while(len != n)
                pop_back();
        }
    }
    void clear() // Удаляет все элементы из списка контейнера (которые разрушены), и оставляя контейнер с размером от 0.
    {
        while(len != 0)
            pop_front();
    }
    void remove (const value_type& val) // Удаляет из контейнера все элементы, равные val.
    {
        Node *tmp;
        Node *count = head;
        while(count->next != nullptr)
        {
            tmp = head;
            while(tmp->next != nullptr && tmp->data != val)
                tmp = tmp->next;
            if(tmp == head)
                pop_front();
            else if(tmp->data == val)
            {
                if(tmp->next == nullptr) // проверка на последний элемент
                    pop_back();
                else
                {
                    Node *buf = tmp->next;
                    tmp->data = tmp->next->data;
                    tmp->prev = tmp->next->prev;
                    tmp->next = tmp->next->next;
                    delete buf;
                    len--;
                }
            }
            count = count->next;
        }
    }
    void unique() // Версия без параметров (1) удаляет все элементы, кроме первого, из каждой последующей группы равных элементов в контейнере.
    {
		Node *tmp = head;
		while(tmp != nullptr)
		{
			Node *buf = tmp;
			while(buf != nullptr)
			{
				buf = buf->next;
				if(buf != nullptr && tmp->data == buf->data)
				{
					Node *bufs = buf->next;  
                	buf->data = buf->next->data;
                	buf->prev = buf->next->prev;
                	buf->next = buf->next->next;
                	delete bufs;
                	len--;
				}
			}
			tmp = tmp->next;
		}
	}
	void merge (list& x) // Объединяет x в список , передавая все его элементы в соответствующие упорядоченные позиции в контейнер (оба контейнера уже должны быть упорядочены).
    {
        while(x.head != nullptr)
        {
            push_back(x.head->data);
            x.len--;
            x.head = x.head->next;
        }
        sort();
    }

    void sort() //  Сортирует элементы в списке , изменяя их положение в контейнере.
    {
        Node *tmp = head;
        while(tmp != nullptr)
        {
            Node *buf = tmp;
			while(buf != nullptr)
			{
				buf = buf->next;
				if(buf != nullptr && tmp->data > buf->data)
				{
                    T temp = tmp->data;
                    tmp->data = buf->data;
                    buf->data = temp;
				}
			}
            tmp = tmp->next;
        }
    }
    void reverse() // Изменяет порядок элементов в контейнере списка. Обратный порядок элементов.
    {
        if(head->data < head->next->data)
        {
            Node *tmp = head;
            while(tmp != nullptr)
            {
                Node *buf = tmp;
                while(buf != nullptr)
                {
                    buf = buf->next;
                    if(buf != nullptr && tmp->data < buf->data)
                    {
                        T temp = tmp->data;
                        tmp->data = buf->data;
                        buf->data = temp;
                    }
                }
                tmp = tmp->next;
            }
        }
        else
            sort();
    }
    class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    private:
        Node *count;
    public:
        iterator(Node *head = nullptr)
        {
            this->count = head;
        }
        ~iterator() { };
        iterator begin() // Возвращает итератор, указывающий на первый элемент в контейнере списка.
        {
            return(count);
        }
        iterator end() // Возвращает итератор, относящийся к последнему элементу в контейнере списка.
        {
            Node *tmp;
            tmp = count;
            while(tmp->next != nullptr)
                tmp = tmp->next;
            return(tmp);
        }
        iterator &operator=(const iterator &obj)
        {
            this->count = obj.count;
            return(*this);
        }
        iterator operator++(int) // value++
        {
            this->count = count->next;
            return(*this);
        }
        iterator operator--(int) // value--
        {
            this->count = count->prev;
            return(*this);
        }
        iterator &operator++() // ++value
        {
            this->count = count->next;
            return(*this);
        }
        iterator &operator--() // --value
        {
            this->count = count->prev;
            return(*this);
        }
        T &operator*() const
        {
            return(this->count->data);
        }
        T *operator&() const
        {
            return(*(this->count->data));
        }
		bool operator!=(iterator const &val) const
		{
			return(count != val.count);
		}
        Node* getNode() const
        {
            return(count);
        }
    };


    iterator erase (iterator position) // Удаляет из контейнера списка либо один элемент ( позицию ), либо диапазон элементов ( [первый, последний) ).
    {
		Node *tmp = head;
        while(tmp != nullptr)
        {
            if(tmp->next->data == *position)
            {
                tmp = tmp->next;
                Node *buf = tmp->next;  
                tmp->data = tmp->next->data;
                tmp->prev = tmp->next->prev;
                tmp->next = tmp->next->next;
                delete buf;
                len--;
                break ;
            }
            tmp = tmp->next;
        }
        return(iterator(tmp));
    }
    iterator erase (iterator first, iterator last) // Удаляет из контейнера списка либо один элемент ( позицию ), либо диапазон элементов ( [первый, последний) ).
    {
		Node *tmp = head;
        while(tmp != nullptr)
        {
            if(tmp->data == *first)
            {
				while(tmp->data != *last)
				{
					Node *buf = tmp->next;  
					tmp->data = tmp->next->data;
					tmp->prev = tmp->next->prev;
					tmp->next = tmp->next->next;
					delete buf;
					len--;
				}
				if(tmp->next)
				{
					Node *buf2 = tmp->next;
					tmp->data = tmp->next->data;
					tmp->prev = tmp->next->prev;
					tmp->next = tmp->next->next;
					delete buf2;
					len--;
				}
				else
					pop_back();
                break ;
            }
            tmp = tmp->next;
        }
        return(iterator(tmp));
    }
    void insert (iterator position, size_type n, const value_type& val) // https://www.cplusplus.com/reference/list/list/insert/
    {
        Node *tmp = head;
        while(tmp->next->data != *position && tmp != nullptr)
        {
            tmp = tmp->next;
        }
        if(tmp->next->data == *position)
        {
            for(size_type i = 0; i < n; i++)
            {
                Node *buf = new Node(val);
                buf->next = tmp->next;
                buf->prev = tmp->next->prev;
                tmp->next->prev = buf;
                tmp->next = buf;
                len++;
            }
        }
    }
    iterator insert (iterator position, const value_type& val) // https://www.cplusplus.com/reference/list/list/insert/
    {
        Node *tmp = head;
        while(tmp->next->data != *position && tmp != nullptr)
        {
            tmp = tmp->next;
        }
        if(tmp->next->data == *position)
        {
            Node *buf = new Node(val);
            buf->next = tmp->next;
            buf->prev = tmp->next->prev;
            tmp->next->prev = buf;
            tmp->next = buf;
            len++;
            return(buf);
        }
        return(iterator(tmp));
    }
    void splice (iterator position, list& x) // Переносит элементы из x в контейнер, вставляя их в позицию . Первая версия (1) передает все элементы й в контейнер.
    {   
        Node *tmp = head;
        len = 0;
        while(tmp != nullptr)
        {
            if(tmp->next->data == *position)
            {
                Node *buf = new Node(tmp->next->data);
                buf->next = tmp->next->next;
                tmp->next = nullptr;
                while(x.head != nullptr)
                {
                    push_back(x.head->data);
                    delete x.head;
                    x.head = x.head->next;
                }
                while(buf != nullptr)
                {
                    push_back(buf->data);
                    delete buf;
                    buf = buf->next;
                }
                x.len = 0;
                break ;
            }
            tmp = tmp->next;
            len++;
        }
    }
    void splice (iterator position, list& x, iterator i) // Второй вариант (2) передает только элемент указываемого I от й в контейнер.
    {
        Node *tmp = head;
        len = 0;
        while(tmp != nullptr)
        {
            if(tmp->next->data == *position)
            {
                Node *buf = new Node(tmp->next->data);
                buf->next = tmp->next->next;
                tmp->next = nullptr;
                while(x.head->data != *i)
                    x.head = x.head->next;
                push_back(x.head->data);
                Node *tmp2 = x.head;
                x.head = x.head->next;
                delete tmp2;
                while(buf != nullptr)
                {
                    push_back(buf->data);
                    delete buf;
                    buf = buf->next;
                }
                x.len--;
                break ;
            }
            tmp = tmp->next;
            len++;
        }
    }
    void splice (iterator position, list& x, iterator first, iterator last) // Третий вариант (3) передает диапазон [первый, последний) из й в контейнер.  
    {
        Node *tmp = head;
        len = 0;
        while(tmp != nullptr)
        {
            if(tmp->next->data == *position)
            {
                Node *buf = new Node(tmp->next->data);
                buf->next = tmp->next->next;
                tmp->next = nullptr;
                while(x.head->data != *first)
                    x.head = x.head->next;
                while(x.head->data != *last)
                {
                    push_back(x.head->data);
                    x.len--;
                    delete x.head;
                    x.head = x.head->next;
                }
                push_back(x.head->data);
                x.len--;
                if(x.head->next)
                    x.head = x.head->next;
                else
                {
                    delete x.head;
                    x.head = NULL;
                }
                while(buf != nullptr)
                {
                    push_back(buf->data);
                    delete buf;
                    buf = buf->next;
                }
                break ;
            }
            tmp = tmp->next;
            len++;
        }
    }

    class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    private:
        Node *count;
    public:
        const_iterator(Node *head = nullptr)
        {
            this->count = head;
        }
        ~const_iterator() {};
        const_iterator begin() const // Возвращает итератор, указывающий на первый элемент в контейнере списка .
        {
            return(count);
        }
        const_iterator end() const // Возвращает итератор, относящийся к последнему элементу в контейнере списка .
        {
            Node *tmp;
            tmp = count;
            while(tmp->next)
                tmp = tmp->next;
            return(tmp);
        }
        const_iterator &operator=(const iterator &obj)
        {
            this->count = obj.count;
            return(*this);
        }
        const_iterator operator++(int) // value++
        {
            this->count = count->next;
            return(*this);
        }
        const_iterator operator--(int) // value--
        {
            this->count = count->prev;
            return(*this);
        }
        const_iterator &operator++() // ++value
        {
            this->count = count->next;
            return(*this);
        }
        const_iterator &operator--() // --value
        {
            this->count = count->prev;
            return(*this);
        }
        T &operator*() const
        {
            return(count->data);
        }
        T *operator&() const
        {
            return(count->data);
        }
    };
    
    class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    private:
        Node *count;
    public:
        reverse_iterator(Node *head = nullptr)
        {
            this->count = head;
        }
        reverse_iterator() {}
        reverse_iterator rbegin() // Возвращает обратный итератор, указывающий на последний элемент в контейнере (т.е. его обратное начало ). Обратные итераторы выполняют итерацию в обратном направлении: при увеличении их числа они перемещаются к началу контейнера.
        {
            Node *tmp = count;
            while(tmp->next)
                tmp = tmp->next;
            return(tmp);
        }
        reverse_iterator rend() // Возвращает обратный итератор, указывающий на теоретический элемент, предшествующий первому элементу в контейнере списка (который считается его обратным концом ).
        {
            return(count);
        }
        reverse_iterator &operator=(const iterator &obj)
        {
            this->count = obj.count;
            return(*this);
        }
        reverse_iterator operator--(int) // value++ (наоборот)
        {
            this->count = count->next;
            return(*this);
        }
        reverse_iterator operator++(int) // value-- (наоборот)
        {
            this->count = count->prev;
            return(*this);
        }
        reverse_iterator &operator--() // ++value (наоборот)
        {
            this->count = count->next;
            return(*this);
        }
        reverse_iterator &operator++() // --value (наоборот)
        {
            this->count = count->prev;
            return(*this);
        }
        T &operator*() const
        {
            return(count->data);
        }
        T *operator&() const
        {
            return(*(this->count->data));
        }
    };

    class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    private:
        Node *count;
    public:
        const_reverse_iterator(Node *head = nullptr)
        {
            this->count = head;
        }
        const_reverse_iterator() {}
        const_reverse_iterator rbegin() const // Возвращает обратный итератор, указывающий на последний элемент в контейнере (т.е. его обратное начало ). Обратные итераторы выполняют итерацию в обратном направлении: при увеличении их числа они перемещаются к началу контейнера.
        {
            Node *tmp = count;
            while(tmp->next)
                tmp = tmp->next;
            return(tmp);
        }
        const_reverse_iterator rend() const // Возвращает обратный итератор, указывающий на теоретический элемент, предшествующий первому элементу в контейнере списка (который считается его обратным концом ).
        {
            return(count);
        }
        const_reverse_iterator &operator=(const iterator &obj)
        {
            this->count = obj.count;
            return(*this);
        }
        const_reverse_iterator operator--(int) // value++ (наоборот)
        {
            this->count = count->next;
            return(*this);
        }
        const_reverse_iterator operator++(int) // value-- (наоборот)
        {
            this->count = count->prev;
            return(*this);
        }
        const_reverse_iterator &operator--() // ++value (наоборот)
        {
            this->count = count->next;
            return(*this);
        }
        const_reverse_iterator &operator++() // --value (наоборот)
        {
            this->count = count->prev;
            return(*this);
        }
        T &operator*() const
        {
            return(count->data);
        }
        T *operator&() const
        {
            return(*(this->count->data));
        }
    };

    void assign (size_type n, const value_type& val) // В версии заполнения (2) новое содержимое - это n элементов, каждый из которых инициализирован копией val.
    {
        clear();
        for(size_type i = 0; i < n; i++)
        {
            push_back(val);
        }
    }

    template <class InputIterator>
        void assign (InputIterator first, InputIterator last) // В версии диапазона (1) новое содержимое - это элементы, составленные из каждого из элементов в диапазоне от первого до последнего в том же порядке.
        {
            Node *tmp = head;
            while(tmp->data != *first)
            {
                Node *buf = tmp->next;  
                tmp->data = tmp->next->data;
                tmp->prev = tmp->next->prev;
                tmp->next = tmp->next->next;
                delete buf;
                len--;
            }
            while(tmp->data != *last)
                tmp = tmp->next;
            while(tmp->next != nullptr)
                pop_back();
        }

    template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last) // https://www.cplusplus.com/reference/list/list/insert/
        {
            Node *tmp = head;
            while(tmp->next->data != *position && tmp != nullptr)
                tmp = tmp->next;
            while(first != last)
            {
                Node *buf = new Node(*first);
                buf->next = tmp->next;
                buf->prev = tmp;
                tmp->next = buf;
                tmp = tmp->next;
                first++;
            }
                Node *buf = new Node(*first);
                buf->next = tmp->next;
                buf->prev = tmp;
                tmp->next = buf;
                tmp = tmp->next;
        }

    iterator begin()
    {
        iterator name(head);
        return(name.begin());
    }
    iterator end()
    {
        iterator name(head);
        return(name.end());
    }
    const_iterator begin() const
    {
        const_iterator name(head);
        return(name.begin());
    }
    const_iterator end() const
    {
        const_iterator name(head);
        return(name.end());
    }
    reverse_iterator rbegin()
    {
        reverse_iterator name(head);
        return(name.rbegin());
    }
    reverse_iterator rend()
    {
        reverse_iterator name(head);
        return(name.rend());
    }
    const_reverse_iterator rbegin() const
    {
        const_reverse_iterator name(head);
        return(name.rbegin());
    }
    const_reverse_iterator rend() const
    {
        const_reverse_iterator name(head);
        return(name.rend());
    }
    reference front()
    {
        return(head->data);
    }
    reference back()
    {
        Node *tmp;
        tmp = head;
        while(tmp->next)
            tmp = tmp->next;
        return(tmp->data);
    }
    const_reference front() const
    {
        return(head->data);
    }
    const_reference back() const
    {
        Node *tmp;
        tmp = head;
        while(tmp->next)
            tmp = tmp->next;
        return(tmp->data);
    }
};

    template <class T, class Alloc>
        bool operator==(const list<T,Alloc>& x, const list<T,Alloc>& y) { return(x.size() == y.size()); }

    template <class T, class Alloc>
        bool operator< (const list<T,Alloc>& x, const list<T,Alloc>& y) { return(x.size() < y.size()); }

    template <class T, class Alloc>
        bool operator!=(const list<T,Alloc>& x, const list<T,Alloc>& y) { return(x.size() != y.size()); }

    template <class T, class Alloc>
        bool operator> (const list<T,Alloc>& x, const list<T,Alloc>& y) { return(x.size() > y.size()); }

    template <class T, class Alloc>
        bool operator>=(const list<T,Alloc>& x, const list<T,Alloc>& y) { return(x.size() >= y.size()); }

    template <class T, class Alloc>
        bool operator<=(const list<T,Alloc>& x, const list<T,Alloc>& y) { return(x.size() <= y.size()); }

    template <class T, class Alloc>
        void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y) // Содержимое контейнера x обменивается с содержимым y . Оба объекта-контейнера должны быть одного типа (одинаковые параметры шаблона), хотя размеры могут отличаться.
        {
            ft::list<T, Alloc> tmp;
            tmp = x;
            x = y;
            y = tmp;
        }
};

#endif