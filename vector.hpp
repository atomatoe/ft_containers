/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:30:11 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/19 00:56:34 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft
{
template < class T, class Alloc = std::allocator<T> >
class vector
{
private:
	T* _elem;
	size_t _size; // количество элементов в массиве
	size_t _capacity; // длина по памяти массива
public:
    class               iterator;
    class               const_iterator;
    class               reverse_iterator;
    class               const_reverse_iterator;
    class               reference;
	class               const_reference;
    typedef T           value_type;
    typedef Alloc       allocator_type;
    typedef size_t		size_type;


    // ****************************************************
    /*                  DELETED MY FUNK                  */
    void my_print()
    {
        size_type i = 0;
		while(i != _size)
        {
			std::cout << _elem[i] << std::endl;
			i++;
        }
		std::cout << "size = " << size() << std::endl;
		std::cout << "capacity = " << capacity() << std::endl;
    }
    // ****************************************************

    explicit vector (const allocator_type& alloc = allocator_type()) // Создает пустой контейнер без элементов.
	{
		_elem = nullptr;
		_size = 0;
		_capacity = 0;
	}
    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) // Создает контейнер из n элементов. Каждый элемент является копией val
	{
		_size = n;
		_capacity = _size * 2;
		_elem = new T[_capacity];
		for(size_type i = 0; i < n; i++)
			_elem[i] = val;
	}
	template <class InputIterator> 
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); // Создает контейнер с таким количеством элементов, как диапазон [первый, последний), причем каждый элемент создается из соответствующего ему элемента в этом диапазоне в том же порядке.
	vector (const vector& x) // конструктор копирования
	{
		*this = x;
	}
	~vector() // деструктор
	{
		clear();
		delete _elem;
	}
	vector& operator= (const vector& x) // оператор присваивания
	{
		if(_elem)
			clear();
		_size = x._size;
		_capacity = x._capacity;
		_elem = new T[x._capacity];
		for(size_type i = 0; i < x._size; i++)
			_elem[i] = x._elem[i];
		return(*this);
	}
	size_type size() const // Возвращает количество элементов в векторе.
	{
		return(_size);
	}
	size_type max_size() const; // Возвращает максимальное количество элементов, которое может содержать вектор.
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
		while(_size != 0)
			pop_back();
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
			T *tmp = new T[_capacity];
			for(size_type i = 0; i < _size; i++)
				tmp[i] = _elem[i];
			tmp[_size] = val;
			_size++;
			delete _elem;
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
			_elem[_size] = 0;
			_size--;
		}
	}
	void insert (iterator position, size_type n, const value_type& val); // Вектор расширяется путем вставки новых элементов перед элементом в указанной позиции, эффективно увеличивая размер контейнера на количество вставленных элементов.
	void swap (vector& x) // Меняет содержимое контейнера на содержимое x, который является другим векторным объектом того же типа. Размеры могут отличаться.
	{
		ft::vector<T> tmp(x);
		x = *this;
		*this = tmp;
	}
	void clear() // Удаляет все элементы из вектора (которые уничтожаются), оставляя контейнер с размером 0.
	{
		_elem = nullptr;
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
			iterator begin() // Возвращает итератор, указывающий на первый элемент вектора.
			{
				return(&this->count[0]);
			}
			iterator end(); // Возвращает итератор, указывающий на последний элемент вектора.
			iterator insert (iterator position, const value_type& val); // Вектор расширяется путем вставки новых элементов перед элементом в указанной позиции, эффективно увеличивая размер контейнера на количество вставленных элементов.
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
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
			iterator operator--(int); // value--
			iterator &operator++(); // ++value
			iterator &operator--(); // --value
			T &operator*() const
			{
				return(*this->count);
			}
			T *operator&() const;
			T & operator[] (const unsigned int index);
	};

	class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
		private:

		public:
			const_iterator begin() const; // Возвращает итератор, указывающий на первый элемент вектора.
			const_iterator end() const; // Возвращает итератор, указывающий на последний элемент вектора.
			const_iterator &operator=(const iterator &obj);
			const_iterator operator++(int); // value++
			const_iterator operator--(int); // value--
			const_iterator &operator++(); // ++value
			const_iterator &operator--(); // --value
			T &operator*() const;
			T *operator&() const;
			T & operator[] (const unsigned int index);	
	};

	class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
		private:

		public:
			reverse_iterator rbegin(); //  Возвращает обратный итератор, указывающий на последний элемент вектора (т.е. его обратное начало).
			reverse_iterator rend(); // Возвращает обратный итератор, указывающий на первый элемент вектора (т.е. его обратное начало).
			reverse_iterator &operator=(const iterator &obj);
			reverse_iterator operator++(int); // value++
			reverse_iterator operator--(int); // value--
			reverse_iterator &operator++(); // ++value
			reverse_iterator &operator--(); // --value
			T &operator*() const;
			T *operator&() const;
			T & operator[] (const unsigned int index);	
	};

	class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
		private:

		public:
			const_reverse_iterator rbegin() const; //  Возвращает обратный итератор, указывающий на последний элемент вектора (т.е. его обратное начало).
			const_reverse_iterator rend() const; // Возвращает обратный итератор, указывающий на первый элемент вектора (т.е. его обратное начало).
			const_reverse_iterator &operator=(const iterator &obj);
			const_reverse_iterator operator++(int); // value++
			const_reverse_iterator operator--(int); // value--
			const_reverse_iterator &operator++(); // ++value
			const_reverse_iterator &operator--(); // --value
			T &operator*() const;
			T *operator&() const;
			T & operator[] (const unsigned int index);	
	};

	class reference : public std::iterator<std::bidirectional_iterator_tag, T>
    {
		private:

		public:
			reference operator[] (size_type n); // Возвращает ссылку на элемент в позиции n в контейнере вектора
			reference at (size_type n); // Возвращает ссылку на элемент в позиции n в векторе.
			reference front(); // Возвращает ссылку на первый элемент вектора.
			reference back(); // Возвращает ссылку на последний элемент вектора.
			reference &operator=(const iterator &obj);
			reference operator++(int); // value++
			reference operator--(int); // value--
			reference &operator++(); // ++value
			reference &operator--(); // --value
			T &operator*() const;
			T *operator&() const;
			T & operator[] (const unsigned int index);
	};

	class const_reference : public std::iterator<std::bidirectional_iterator_tag, T>
    {
		private:

		public:
			const_reference operator[] (size_type n) const; // Возвращает ссылку на элемент в позиции n в контейнере вектора
			const_reference at (size_type n) const; // Возвращает ссылку на элемент в позиции n в векторе.
			const_reference front() const; // Возвращает ссылку на первый элемент вектора.
			const_reference back() const; // Возвращает ссылку на последний элемент вектора.
			const_reference &operator=(const iterator &obj);
			const_reference operator++(int); // value++
			const_reference operator--(int); // value--
			const_reference &operator++(); // ++value
			const_reference &operator--(); // --value
			T &operator*() const;
			T *operator&() const;
			T & operator[] (const unsigned int index);
	};

	iterator begin()
    {
        iterator name(_elem);
        return(name.begin());
    }
    iterator end()
    {
        iterator name(_elem);
        return(name.end());
    }
    const_iterator front()
    {
        const_iterator name(_elem);
        return(name.front());
    }
    const_iterator back()
    {
        const_iterator name(_elem);
        return(name.back());
    }

	template <class InputIterator>
  		void assign (InputIterator first, InputIterator last); // В версии fill (2) новое содержимое - это n элементов, каждый из которых инициализирован копией val.
	template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last); //  Вектор расширяется путем вставки новых элементов перед элементом в указанной позиции, эффективно увеличивая размер контейнера на количество вставленных элементов.

};

	template <class T, class Alloc>
  		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
  		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
  		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
  		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
  		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
  		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y); // Содержимое контейнера x обменивается с содержимым y. Оба объекта-контейнера должны быть одного типа (одинаковые параметры шаблона), хотя размеры могут отличаться.
};

#endif

