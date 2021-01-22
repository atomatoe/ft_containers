/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:24:37 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/22 16:35:23 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

#include <iostream>
#include <iterator>
#include <unistd.h>

namespace ft
{
template < class T, class Alloc = std::allocator<T> >
class deque
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
        pointer _deq;
        size_type _size;
        size_type _capacity;
        allocator_type _alloc;

        void ft_realloc()
        {
            _capacity = _size * 2;
            pointer tmp = _alloc.allocate(_capacity);
            for(size_type i = 0; i < _size; ++i)
                _alloc.construct(_deq + i, *(_deq + i));
            for(size_type i = 0; i < _size; ++i)
                _alloc.destroy(_deq + i);
            if(_capacity)
                _alloc.deallocate(_deq, _capacity);
            _deq = tmp;
        }

    public:
        // ****************************************************
        /*                  DELETED MY FUNK                  */
        void my_print()
        {
            size_type i = 0;
            while(i != _size)
            {
                std::cout << _deq[i] << std::endl;
                i++;
            }
            std::cout << "size = " << size() << std::endl;
            std::cout << "capacity = " << _capacity << std::endl;
        }
        // ****************************************************
        explicit deque (const allocator_type& alloc = allocator_type()) // Создает пустой контейнер без элементов.
        {
            _deq = nullptr;
            _size = 0;
            _capacity = 0;
            _alloc = alloc;
        }
        explicit deque (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) // Создает контейнер из n элементов. Каждый элемент является копией, если val.
        {
            _alloc = alloc;
            _size = n;
            _capacity = _size;
            _deq = _alloc.allocate(_capacity);
            for(size_type i = 0; i < _size; ++i)
                _alloc.construct(_deq + i, val);
        }
        deque (const deque& x) // конструктор копирования
        {
            *this = x;
        }
        ~deque()
        {
            clear();
            if(_capacity != 0)
            {
                _alloc.deallocate(_deq, _capacity);
                _capacity = 0;
            }
        }
        deque& operator= (const deque& x)
        {
            _capacity = 0;
            _size = 0;
            for(size_type i = 0; i < x._size; i++)
                push_front(x._deq[i]);
            return(*this);
        }
        size_type size() const // возращает размер 
        {
            return(_size);
        }
        size_type 	max_size() const
        { 
            return std::numeric_limits<size_type>::max() / sizeof(_deq[0]); 
        }
        void resize (size_type n, value_type val = value_type())
        {
            if(n > _size)
		    {
                while(_size != n)
                    push_back(val);
		    }
            else if(n < _size)
            {
                while(_size != n)
                    pop_back();
            }
        }
        bool empty() const
        {
            bool status = true;
            if(_size > 0)
                status = false;
            return(status);
        }
        void assign (size_type n, const value_type& val) // В версии fill (2) новое содержимое - это n элементов, каждый из которых инициализирован копией val.
        {
            clear();
            if(_capacity != 0)
            {
                _alloc.deallocate(_deq, _capacity);
                _capacity = 0;
            }
            for(size_type i = 0; i < n; i++)
                push_back(val);
        }
        void push_back (const value_type& val) // Добавляет новый элемент в конец контейнера двухсторонней очереди после его текущего последнего элемента.
        {
            if(_capacity == 0)
            {
                _size = 1;
                _capacity = 1;
                _deq = new T[1];
                _deq[0] = val;
            }
            else if(_capacity == _size)
            {
                _capacity = _size * 2;
                T *tmp = new T[_capacity];
                for(size_type i = 0; i < _size; i++)
                    tmp[i] = _deq[i];
                tmp[_size] = val;
                _size++;
                delete _deq;
                _deq = tmp;
            }
            else
            {
                _deq[_size] = val;
                _size++;
            }
        }
        void push_front (const value_type& val) // Вставляет новый элемент в начало контейнера двухсторонней очереди, прямо перед его текущим первым элементом.
        {
            if(_size == 0)
            {
                if(_capacity == 0)
                {
                    _capacity = 1;
                    _deq = new T[_capacity];
                }
                _deq[0] = val;
                _size = 1;
            }
            else
            {
                _capacity = _size * 2;
                pointer tmp = _alloc.allocate(_capacity);
                tmp[0] = val;
                size_type count = 1;
                for(size_type i = 0; i < _size; i++)
                {
                    tmp[count] = _deq[i];
                    count++;
                }
                delete _deq;
                _size++;
                _deq = tmp;
            }
        }
        void pop_back() // Удаляет последний элемент в контейнере двухсторонней очереди, эффективно уменьшая размер контейнера на единицу.
        {
            T* tmp = new T[_size - 1];
            for(size_type i = 0; i < _size - 1; i++)
                tmp[i] = _deq[i];
            _size--;
            delete _deq;
            _deq = tmp;
        }
        void pop_front() // Удаляет первый элемент из контейнера двухсторонней очереди, эффективно уменьшая его размер на единицу.
        {
            _capacity = _size * 2;
            T *tmp = new T[_capacity];
            size_type ig = 1;
            for(size_type i = 0; i < _size - 1; i++)
            {
                tmp[i] = _deq[ig];
                ig++;
            }
            _size--;
            delete _deq;
            _deq = tmp;
        }
        void swap (deque& x) // Заменяет содержимое контейнера содержимым x, который является другим объектом двухсторонней очереди, содержащим элементы того же типа. Размеры могут отличаться.
        {
            ft::deque<T> tmp(x);
            x = *this;
            *this = tmp;
        }
        void clear() // Удаляет все элементы из двухсторонней очереди (которые уничтожаются), оставляя контейнер с размером 0.
        {
            for(size_type i = 0; i < _size; i++)
                _alloc.destroy(_deq + i);
            _size = 0;
        }
        iterator begin()
        {
            return(iterator(this->_deq));
        }
        const_iterator begin() const
        {
            return(const_iterator(this->_deq));
        }
        iterator end()
        {
            return(iterator(this->_deq + _size));
        }
        const_iterator end() const
        {
            return(const_iterator(this->_deq + _size));
        }
        reverse_iterator rbegin()
        {
            return(reverse_iterator(this->_deq + _size - 1));
        }
        const_reverse_iterator rbegin() const
        {
            return(const_reverse_iterator(this->_deq + _size - 1));
        }
        reverse_iterator rend()
        {
            return(reverse_iterator(this->_deq));
        }
        const_reverse_iterator rend() const
        {
            return(const_reverse_iterator(this->_deq));
        }
        reference operator[] (size_type n)
        {
            return(this->_deq[n]);
        }
        const_reference operator[] (size_type n) const
        {
            return(this->_deq[n]);
        }
        reference at (size_type n)
        {
            return(this->_deq[n]);
        }
        const_reference at (size_type n) const
        {
            return(this->_deq[n]);
        }
        reference front()
        {
            return(this->_deq[0]);
        }
        const_reference front() const
        {
            return(this->_deq[0]);
        }
        reference back()
        {
            return(this->_deq[_size - 1]);
        }
        const_reference back() const
        {
            return(this->_deq[_size - 1]);
        }
        iterator insert (iterator position, const value_type& val) // Контейнер двухсторонней очереди расширяется путем вставки новых элементов перед элементом в указанной позиции.
        {
            iterator it = begin();
            size_type i = 0;
            while(it++ != position)
                i++;
            _capacity = _size * 2;
            pointer tmp = _alloc.allocate(_capacity);
            size_type c = 0;
			while(c < i)
			{
				tmp[c] = _deq[c];
				c++;
			}
			tmp[c] = val;
			c++;
			while(c < _size + 1)
			{
				tmp[c] = _deq[i];
				c++;
				i++;
			}
			_size = c;
			delete _deq;
			_deq = tmp;
            return(iterator(_deq));
        }
        iterator erase (iterator position)
        {
            iterator it = begin();
            size_type i = 0;
            while(it++ != position)
                i++;
            size_type h = i;
			i++;
			while(h != _size)
			{
				_deq[h] = _deq[i];
				i++;
				h++;
			}
			_size--;
			return(iterator(_deq));
        }
        iterator erase (iterator first, iterator last)
        {
            iterator it = begin();
            size_type i = 0;
            while(it++ != first)
                i++;
            size_type t = i;
			size_type h = 0;
			while(_deq[t] != *last)
			{
				h++;
				t++;
			}
			_size -= h;
			while(i < _size)
			{
				_deq[i] = _deq[t];
				i++;
				t++;
			}
            return(iterator(_deq));
        }
        class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        {
            private:
                pointer count;
            public:
                explicit iterator(pointer value = nullptr)
                {
                    this->count = value;
                }
                ~iterator() {};
                iterator(const iterator &temp)
                {
                    *this = temp;
                }
                iterator &operator=(const iterator &obj)
                {
                    this->count = obj.get_count();
                    return(*this);
                }
                iterator operator++(int) // value++
                {
                    iterator buf(count);
                    this->count += 1;
                    return(buf);
                }
                iterator operator--(int) // value--
                {
                    iterator buf(count);
                    this->count -= 1;
                    return(buf);
                }
                iterator &operator++() // ++value
                {
                    iterator buf(count);
                    this->count += 1;
                    return(buf);
                }
                iterator &operator--() // --value
                {
                    iterator buf(count);
                    this->count -= 1;
                    return(buf);
                }
                T &operator*() const
                {
                    return(*this->count);
                }
                T *operator&() const
                {
                    return(*this->count);
                }
                T & operator[] (const unsigned int index)
                {
                    return(this->count[index]);
                }
                T* get_count() const
                {
                    return(this->count);
                }
                bool operator!= (iterator const &obj) const { return(count != obj.get_count()); };
                bool operator== (iterator const &obj) const { return(count == obj.get_count()); };
                bool operator<= (iterator const &obj) const { return(count <= obj.get_count()); };
                bool operator< (iterator const &obj) const { return(count < obj.get_count()); };
                bool operator> (iterator const &obj) const { return(count > obj.get_count()); };
                bool operator>= (iterator const &obj) const { return(count >= obj.get_count()); };
        };
        class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        {
            private:
                pointer count;
            public:
                explicit const_iterator(pointer value = nullptr)
                {
                    this->count = value;
                }
                ~const_iterator() {};
                const_iterator(const const_iterator &temp)
                {
                    *this = temp;
                }
                const_iterator &operator=(const const_iterator &obj)
                {
                    this->count = obj.get_count();
                    return(*this);
                }
                const_iterator operator++(int) // value++
                {
                    const_iterator buf(count);
                    this->count += 1;
                    return(buf);
                }
                const_iterator operator--(int) // value--
                {
                    const_iterator buf(count);
                    this->count -= 1;
                    return(buf);
                }
                const_iterator &operator++() // ++value
                {
                    const_iterator buf(count);
                    this->count += 1;
                    return(buf);
                }
                const_iterator &operator--() // --value
                {
                    const_iterator buf(count);
                    this->count -= 1;
                    return(buf);
                }
                T &operator*() const
                {
                    return(*this->count);
                }
                T *operator&() const
                {
                    return(*this->count);
                }
                T & operator[] (const unsigned int index)
                {
                    return(this->count[index]);
                }
                T* get_count() const
                {
                    return(this->count);
                }
                bool operator!= (const_iterator const &obj) const { return(count != obj.get_count()); };
                bool operator== (const_iterator const &obj) const { return(count == obj.get_count()); };
                bool operator<= (const_iterator const &obj) const { return(count <= obj.get_count()); };
                bool operator< (const_iterator const &obj) const { return(count < obj.get_count()); };
                bool operator> (const_iterator const &obj) const { return(count > obj.get_count()); };
                bool operator>= (const_iterator const &obj) const { return(count >= obj.get_count()); };
        };
        class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        {
            private:
                pointer count;
            public:
                explicit reverse_iterator(pointer value = nullptr)
                {
                    this->count = value;
                }
                ~reverse_iterator() {};
                reverse_iterator(const reverse_iterator &temp)
                {
                    *this = temp;
                }
                reverse_iterator &operator=(const reverse_iterator &obj)
                {
                    this->count = obj.get_count();
                    return(*this);
                }
                reverse_iterator operator--(int) // value++
                {
                    reverse_iterator buf(count);
                    this->count += 1;
                    return(buf);
                }
                reverse_iterator operator++(int) // value--
                {
                    reverse_iterator buf(count);
                    this->count -= 1;
                    return(buf);
                }
                reverse_iterator &operator--() // ++value
                {
                    iterator buf(count);
                    this->count += 1;
                    return(buf);
                }
                reverse_iterator &operator++() // --value
                {
                    reverse_iterator buf(count);
                    this->count -= 1;
                    return(buf);
                }
                T &operator*() const
                {
                    return(*this->count);
                }
                T *operator&() const
                {
                    return(*this->count);
                }
                T & operator[] (const unsigned int index)
                {
                    return(this->count[index]);
                }
                T* get_count() const
                {
                    return(this->count);
                }
                bool operator!= (reverse_iterator const &obj) const { return(count != obj.get_count()); };
                bool operator== (reverse_iterator const &obj) const { return(count == obj.get_count()); };
                bool operator<= (reverse_iterator const &obj) const { return(count <= obj.get_count()); };
                bool operator< (reverse_iterator const &obj) const { return(count < obj.get_count()); };
                bool operator> (reverse_iterator const &obj) const { return(count > obj.get_count()); };
                bool operator>= (reverse_iterator const &obj) const { return(count >= obj.get_count()); };
        };

};

    template <class T, class Alloc>
  		bool operator== (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) { return(lhs._size() == rhs._size()); };
	template <class T, class Alloc>
  		bool operator!= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) { return(lhs._size() != rhs._size()); };
	template <class T, class Alloc>
  		bool operator<  (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) { return(lhs._size() < rhs._size()); };
	template <class T, class Alloc>
  		bool operator<= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) { return(lhs._size() <= rhs._size()); };
	template <class T, class Alloc>
  		bool operator>  (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) { return(lhs._size() > rhs._size()); };
	template <class T, class Alloc>
  		bool operator>= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) { return(lhs._size() >= rhs._size()); };
	template <class T, class Alloc>
		void swap (ft::deque<T,Alloc>& x, ft::deque<T,Alloc>& y) // Содержимое контейнера x обменивается с содержимым y. Оба объекта-контейнера должны быть одного типа (одинаковые параметры шаблона), хотя размеры могут отличаться.
		{
			ft::deque<T> tmp(x);
            tmp = x;
            x = y;
            y = tmp;
		}

};
#endif