/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:30:11 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/23 22:46:30 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <iterator>
#include <unistd.h>

namespace ft
{
template < class T, class Alloc = std::allocator<T> >
class vector
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
	pointer _elem;
	size_t _size; // количество элементов в массиве
	size_t _capacity; // длина по памяти массива
	allocator_type _alloc;

	void ft_realloc()
    {
        _capacity = _size * 2;
        pointer tmp = _alloc.allocate(_capacity);
        for(size_type i = 0; i < _size; ++i)
            _alloc.construct(_elem + i, *(_elem + i));
        for(size_type i = 0; i < _size; ++i)
            _alloc.destroy(_elem + i);
        if(_capacity)
            _alloc.deallocate(_elem, _capacity);
         _elem = tmp;
    }
	void push_front (const value_type& val) // Вставляет новый элемент в начало контейнера двухсторонней очереди, прямо перед его текущим первым элементом.
        {
            if(_size == 0)
            {
                if(_capacity == 0)
                {
                    _capacity = 1;
                    _elem = new T[_capacity];
                }
                _elem[0] = val;
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
                    tmp[count] = _elem[i];
                    count++;
                }
                _alloc.deallocate(_elem, _capacity);
                _size++;
                _elem = tmp;
            }
        }
public:
    explicit vector (const allocator_type& alloc = allocator_type()) // Создает пустой контейнер без элементов.
	{
		_elem = nullptr;
        _size = 0;
        _capacity = 0;
        _alloc = alloc;
	}
    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) // Создает контейнер из n элементов. Каждый элемент является копией val
	{
		_alloc = alloc;
        _size = n;
        _capacity = _size;
        _elem = _alloc.allocate(_capacity);
        for(size_type i = 0; i < _size; ++i)
            _alloc.construct(_elem + i, val);
	}
	template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0)
	{
		_alloc = alloc;
		_elem = _alloc.allocate(_capacity);
		InputIterator tmp = first;
		size_type i = 0;
		while(tmp != last)
		{
			i++;
			tmp++;
		}
		_size = i;
        _capacity = _size;
		_elem = _alloc.allocate(_capacity);
        for(size_type i = 0; i < _size; ++i)
            _alloc.construct(_elem + i, *first++);
	}
	vector (const vector& x) // конструктор копирования
	{
		*this = x;
	}
	~vector() // деструктор
	{
		clear();
        if(_capacity != 0)
        {
            _alloc.deallocate(_elem, _capacity);
            _capacity = 0;
        }
	}
	vector& operator= (const vector& x) // оператор присваивания
	{
        _capacity = 0;
        _size = 0;
        for(size_type i = 0; i < x._size; i++)
            push_front(x._elem[i]);
        return(*this);
	}
	size_type size() const // Возвращает количество элементов в векторе.
	{
		return(_size);
	}
	size_type max_size() const // Возвращает максимальное количество элементов, которое может содержать вектор.
	{
		return std::numeric_limits<size_type>::max() / sizeof(_elem[0]);
	}
	void resize (size_type n, value_type val = value_type()) // Изменяет размер контейнера, чтобы он содержал n элементов.
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
	size_type capacity() const // Возвращает размер дискового пространства, выделенного в данный момент для вектора, выраженный в элементах.
	{
		return(_capacity);
	}
	bool empty() const // Возвращает, является ли вектор пустым (то есть равен ли его размер 0).
	{
		bool status = true;
		if(_size > 0)
			status = false;
		return(status);
	}
	void reserve (size_type n) // Запрашивает, чтобы емкость вектора была как минимум достаточной для размещения n элементов.
	{
		if(n > _capacity)
		{
			_capacity = n;
			T *tmp = new T[_capacity];
			for(size_type i = 0; i < _size; i++)
				tmp[i] = _elem[i];
			delete _elem;
			_elem = tmp;
		}
	}
	void assign (size_type n, const value_type& val) // В версии диапазона (1) новое содержимое - это элементы, составленные из каждого из элементов в диапазоне от первого до последнего в том же порядке.
	{
		for(size_type i = 0; i < _size; i++)
            _alloc.destroy(_elem + i);
		_alloc.deallocate(_elem, _capacity);
        _size = 0;
		_capacity = 0;
		for(size_type i = 0; i < n; i++)
			push_back(val);
	}
	void push_back (const value_type& val) // Добавляет новый элемент в конец вектора после его текущего последнего элемента. Содержимое val копируется (или перемещается) в новый элемент.
	{
		if(_capacity == 0)
		{
			_size = 1;
			_capacity = 1;
			_elem = new T[1];
			_elem[0] = val;
		}
		else if(_capacity == _size)
		{
			_capacity = _size * 2;
			pointer tmp = _alloc.allocate(_capacity);
			for(size_type i = 0; i < _size; i++)
				tmp[i] = _elem[i];
			tmp[_size] = val;
			_size++;
			_alloc.deallocate(_elem, _capacity);
			_elem = tmp;
		}
		else
		{
			_elem[_size] = val;
			_size++;
		}
	}
	void pop_back() // Удаляет последний элемент в векторе, эффективно уменьшая размер контейнера на единицу.
	{
		if(_size > 0)
		{
			_alloc.destroy(_elem + _size);
			_size--;
		}
	}
	void swap (vector& x) // Меняет содержимое контейнера на содержимое x, который является другим векторным объектом того же типа. Размеры могут отличаться.
	{
		ft::vector<T> tmp(x);
		x = *this;
		*this = tmp;
	}
	void clear() // Удаляет все элементы из вектора (которые уничтожаются), оставляя контейнер с размером 0.
	{
        for(size_type i = 0; i < _size; i++)
            _alloc.destroy(_elem + i);
        _size = 0;
	}

	class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
		private:
			T* count;
		public:
			iterator(T* value = nullptr)
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
				this->count = obj.count;
				return(*this);
			}
			iterator operator++(int) // value++
			{
				iterator buf(count);
				this->count = count + 1;
				return(buf);
			}
			iterator operator--(int) // value--
			{
				iterator buf(count);
				this->count = count - 1;
				return(buf);
			}
			iterator &operator++() // ++value
			{
				iterator buf(count);
				this->count = count + 1;
				return(buf);
			}
			iterator &operator--() // --value
			{
				iterator buf(count);
				this->count = count - 1;
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
            bool operator!= (iterator const &obj) const { return(get_count() != obj.get_count()); };
            bool operator== (iterator const &obj) const { return(get_count() == obj.get_count()); };
            bool operator<= (iterator const &obj) const { return(get_count() <= obj.get_count()); };
            bool operator< (iterator const &obj) const { return(get_count() < obj.get_count()); };
            bool operator> (iterator const &obj) const { return(get_count() > obj.get_count()); };
            bool operator>= (iterator const &obj) const { return(get_count() >= obj.get_count()); };
	};

	class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
		private:
			T* count;
		public:
			const_iterator(T* value = nullptr)
			{
				this->count = value;
			}
			~const_iterator() {};
			const_iterator(const const_iterator &temp)
			{
				*this = temp;
			}
			const_iterator &operator=(const iterator &obj)
			{
				this->count = obj.count;
				return(*this);
			}
			const_iterator operator++(int) // value++
			{
				const_iterator buf(count);
				this->count = count + 1;
				return(buf);
			}
			const_iterator operator--(int) // value--
			{
				const_iterator buf(count);
				this->count = count - 1;
				return(buf);
			}
			const_iterator &operator++() // ++value
			{
				const_iterator buf(count);
				this->count = count + 1;
				return(buf);
			}
			const_iterator &operator--() // --value
			{
				const_iterator buf(count);
				this->count = count - 1;
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
	};

	class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
		private:
			T* count;
		public:
			reverse_iterator(T* value = nullptr)
			{
				this->count = value;
			}
			~reverse_iterator() {};
			reverse_iterator(const reverse_iterator &temp)
			{
				*this = temp;
			}
			reverse_iterator &operator=(const iterator &obj)
			{
				this->count = obj.count;
				return(*this);
			}
			reverse_iterator operator++(int) // value++
			{
				reverse_iterator buf(count);
				this->count = count - 1;
				return(buf);
			}
			reverse_iterator operator--(int) // value--
			{
				reverse_iterator buf(count);
				this->count = count + 1;
				return(buf);
			}
			reverse_iterator &operator++() // ++value
			{
				reverse_iterator buf(count);
				this->count = count - 1;
				return(buf);
			}
			reverse_iterator &operator--() // --value
			{
				reverse_iterator buf(count);
				this->count = count + 1;
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
	};

	class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
		private:
			T* count;
		public:
			const_reverse_iterator(T* value = nullptr)
			{
				this->count = value;
			}
			~const_reverse_iterator() {};
			const_reverse_iterator(const const_reverse_iterator &temp)
			{
				*this = temp;
			}
			const_reverse_iterator &operator=(const iterator &obj)
			{
				this->count = obj.count;
				return(*this);
			}
			const_reverse_iterator operator++(int) // value++
			{
				const_reverse_iterator buf(count);
				this->count = count - 1;
				return(buf);
			}
			const_reverse_iterator operator--(int) // value--
			{
				const_reverse_iterator buf(count);
				this->count = count + 1;
				return(buf);
			}
			const_reverse_iterator &operator++() // ++value
			{
				const_reverse_iterator buf(count);
				this->count = count - 1;
				return(buf);
			}
			const_reverse_iterator &operator--() // --value
			{
				const_reverse_iterator buf(count);
				this->count = count + 1;
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
	};
		void insert (iterator position, size_type n, const value_type& val) // Вектор расширяется путем вставки новых элементов перед элементом в указанной позиции, эффективно увеличивая размер контейнера на количество вставленных элементов.
		{
			ft::vector<T>tmp;
			size_type i = 0;
			while(_elem[i] != *position)
			{
				tmp.push_back(_elem[i]);
				i++;
			}
			while(n != 0)
			{
				tmp.push_back(val);
				n--;
			}
			while(i != _size)
			{
				tmp.push_back(_elem[i]);
				i++;
			}
			*this = tmp;
		}
		iterator insert (iterator position, const value_type& val) // Вектор расширяется путем вставки новых элементов перед элементом в указанной позиции, эффективно увеличивая размер контейнера на количество вставленных элементов.
		{
			size_type i = 0;
			while(_elem[i] != *position)
			{
				if(i > _size)
					return(0);
				i++;
			}
			T *tmp = new T[_capacity + 1];
			size_type c = 0;
			while(c < i)
			{
				tmp[c] = _elem[c];
				c++;
			}
			tmp[c] = val;
			c++;
			while(c < _size + 1)
			{
				tmp[c] = _elem[i];
				c++;
				i++;
			}
			_size = c;
			delete _elem;
			_elem = tmp;
			return(_elem);
		}
		iterator erase (iterator position)
		{
			size_type i = 0;
			while(_elem[i] != *position)
			{
				if(i > _size)
					return(0);
				i++;
			}
			size_type h = i;
			i++;
			while(h != _size)
			{
				_elem[h] = _elem[i];
				i++;
				h++;
			}
			_size--;
			return(iterator(_elem));
		}
		iterator erase (iterator first, iterator last)
		{
            iterator it = begin();
            size_type i = 0;
            while(it++ != first)
                i++;
            size_type t = i;
			size_type h = 0;
			while(_elem[t] != *last)
			{
				h++;
				t++;
			}
			_size -= h;
			while(i < _size)
			{
				_elem[i] = _elem[t];
				i++;
				t++;
			}
            return(iterator(_elem));
		}
        iterator begin()
        {
            return(iterator(this->_elem));
        }
        const_iterator begin() const
        {
            return(const_iterator(this->_elem));
        }
        iterator end()
        {
            return(iterator(this->_elem + _size));
        }
        const_iterator end() const
        {
            return(const_iterator(this->_elem + _size));
        }
        reverse_iterator rbegin()
        {
            return(reverse_iterator(this->_elem + _size - 1));
        }
        const_reverse_iterator rbegin() const
        {
            return(const_reverse_iterator(this->_elem + _size - 1));
        }
        reverse_iterator rend()
        {
            return(reverse_iterator(this->_elem));
        }
        const_reverse_iterator rend() const
        {
            return(const_reverse_iterator(this->_elem));
        }
        reference operator[] (size_type n)
        {
            return(this->_elem[n]);
        }
        const_reference operator[] (size_type n) const
        {
            return(this->_elem[n]);
        }
        reference at (size_type n)
        {
            return(this->_elem[n]);
        }
        const_reference at (size_type n) const
        {
            return(this->_elem[n]);
        }
        reference front()
        {
            return(this->_elem[0]);
        }
        const_reference front() const
        {
            return(this->_elem[0]);
        }
        reference back()
        {
            return(this->_elem[_size - 1]);
        }
        const_reference back() const
        {
            return(this->_elem[_size - 1]);
        }

};

	template <class T, class Alloc>
  		bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return(lhs._size() == rhs._size()); };
	template <class T, class Alloc>
  		bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return(lhs._size() != rhs._size()); };
	template <class T, class Alloc>
  		bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return(lhs._size() < rhs._size()); };
	template <class T, class Alloc>
  		bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return(lhs._size() <= rhs._size()); };
	template <class T, class Alloc>
  		bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return(lhs._size() > rhs._size()); };
	template <class T, class Alloc>
  		bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return(lhs._size() >= rhs._size()); };
	template <class T, class Alloc>
		void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) // Содержимое контейнера x обменивается с содержимым y. Оба объекта-контейнера должны быть одного типа (одинаковые параметры шаблона), хотя размеры могут отличаться.
		{
			ft::vector<T> tmp(x);
            tmp = x;
            x = y;
            y = tmp;
		}
};

#endif
