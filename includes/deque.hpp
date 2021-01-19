/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:24:37 by atomatoe          #+#    #+#             */
/*   Updated: 2021/01/19 18:45:39 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

#include <iostream>

namespace ft
{
template < class T, class Alloc = std::allocator<T> >
class deque
{
    private:
        T* _deq;
        size_t _size;
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
                std::cout << _deq[i] << std::endl;
                i++;
            }
            std::cout << "size = " << _size << std::endl;
        }
        // ****************************************************
        explicit deque (const allocator_type& alloc = allocator_type()) // Создает пустой контейнер без элементов.
        {
            this->_deq = nullptr;
            _size = 0;
        }
        explicit deque (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) // Создает контейнер из n элементов. Каждый элемент является копией, если val.
        {
            _deq = new T[n];
            for(size_type i = 0; i < n; i++)
                _deq[i] = val;
            _size = n;
        }
        deque (const deque& x) // конструктор копирования
        {
            *this = x;
        }
        ~deque()
        {
            clear();
		    delete _deq;
        }
        deque& operator= (const deque& x)
        {
            if(_deq)
			    clear();
            _size = x._size;
            _deq = new T[x._size];
            for(size_type i = 0; i < x._size; i++)
                _deq[i] = x._deq[i];
            return(*this);
        }
        size_type size() const // возращает размер 
        {
            return(_size);
        }
        size_type max_size() const;
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
            while(_size != 0)
                pop_back();
            for(size_type i = 0; i < n; i++)
                push_back(val);
        }
        void push_back (const value_type& val) // Добавляет новый элемент в конец контейнера двухсторонней очереди после его текущего последнего элемента.
        {
            T* tmp = new T[_size + 1];
            for(size_type i = 0; i < _size; i++)
                tmp[i] = _deq[i];
            tmp[_size] = val;
            _size++;
            delete _deq;
            _deq = tmp;
        }
        void push_front (const value_type& val) // Вставляет новый элемент в начало контейнера двухсторонней очереди, прямо перед его текущим первым элементом.
        {
            if(_size == 0)
            {
                _deq = new T[1];
                _deq[0] = val;
                _size++;
            }
            else
            {
                T* tmp = new T[_size + 1];
                tmp[0] = val;
                size_type count = 1;
                for(size_type i = 0; i < _size; i++)
                {
                    tmp[count] = _deq[i];
                    count++;
                }
                _size++;
                delete _deq;
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
            T* tmp = new T[_size - 1];
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
            _deq = nullptr;
            _size = 0;
        }
        iterator begin() // Возвращает итератор, указывающий на первый элемент в контейнере двухсторонней очереди.
        {
            return(&this->_deq[0]);
        }
        const_iterator begin() const
        {
            return(&this->_deq[0]);
        }
        iterator end() // Возвращает итератор, ссылающийся на последний элемент в контейнере двухсторонней очереди.
        {
            return(&this->_deq[_size - 1]);
        }
        const_iterator end() const
        {
            return(&this->_deq[_size - 1]);
        }
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reference operator[] (size_type n)
        {
            return(*this->_deq[n]);
        }
        const_reference operator[] (size_type n) const
        {
            return(*this->_deq[n]);
        }
        reference at (size_type n) // Возвращает ссылку на элемент в позиции n в объекте контейнера двухсторонней очереди.
        {
            return(&this->_deq[n]);
        }
        const_reference at (size_type n) const // Возвращает ссылку на элемент в позиции n в объекте контейнера двухсторонней очереди.
        {
            return(&this->_deq[n]);
        }
        reference front() // Возвращает ссылку на первый элемент в контейнере двухсторонней очереди.
        {
            return(&this->_deq[0]);
        }
        const_reference front() const // Возвращает ссылку на первый элемент в контейнере двухсторонней очереди.
        {
            return(&this->_deq[0]);
        }
        reference back() // Возвращает ссылку на последний элемент в контейнере.
        {
            return(&this->_deq[_size - 1]);
        }
        const_reference back() const // Возвращает ссылку на последний элемент в контейнере.
        {
            return(&this->_deq[_size - 1]);
        }
        iterator insert (iterator position, const value_type& val) // Контейнер двухсторонней очереди расширяется путем вставки новых элементов перед элементом в указанной позиции.
        {
            size_type i = 0;
			while(_deq[i] != *position)
			{
				if(i > _size)
					return(0);
				i++;
			}
			T *tmp = new T[_size + 1];
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
			return(_deq);
        }
        void insert (iterator position, size_type n, const value_type& val)
        {
            ft::deque<T>tmp;
			size_type i = 0;
			while(_deq[i] != *position)
			{
				tmp.push_back(_deq[i]);
				i++;
			}
			while(n != 0)
			{
				tmp.push_back(val);
				n--;
			}
			while(i != _size)
			{
				tmp.push_back(_deq[i]);
				i++;
			}
			*this = tmp;
        }
        iterator erase (iterator position) // Удаляет из контейнера двухсторонней очереди либо один элемент (позицию), либо диапазон элементов ([первый, последний)).
        {
            size_type i = 0;
			while(_deq[i] != *position)
			{
				if(i > _size)
					return(0);
				i++;
			}
			size_type h = i;
			i++;
			while(h != _size)
			{
				_deq[h] = _deq[i];
				i++;
				h++;
			}
			_size--;
			return(_deq);
        }
        iterator erase (iterator first, iterator last)
        {
            size_type i = 0;
			while(_deq[i] != *first)
			{
				if(i > _size)
					return(0);
				i++;
			}
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
			return(_deq);
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
                T get_count() const
                {
                    return(this->count);
                }
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
        class reference : public std::iterator<std::bidirectional_iterator_tag, T>
        {
            private:
                T* count;
            public:
                reference(T* value = nullptr)
                {
                    this->count = value;
                }
                ~reference() {};
                reference(const reference &temp)
                {
                    *this = temp;
                }
                reference &operator=(const iterator &obj)
                {
                    this->count = obj.count;
                    return(*this);
                }
                reference operator++(int) // value++
                {
                    reference buf(count);
                    this->count = count + 1;
                    return(buf);
                }
                reference operator--(int) // value--
                {
                    reference buf(count);
                    this->count = count - 1;
                    return(buf);
                }
                reference &operator++() // ++value
                {
                    reference buf(count);
                    this->count = count + 1;
                    return(buf);
                }
                reference &operator--() // --value
                {
                    reference buf(count);
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
        class const_reference : public std::iterator<std::bidirectional_iterator_tag, T>
        {
            private:
                T* count;
            public:
                const_reference(T* value = nullptr)
                {
                    this->count = value;
                }
                ~const_reference() {};
                const_reference(const reference &temp)
                {
                    *this = temp;
                }
                const_reference &operator=(const iterator &obj)
                {
                    this->count = obj.count;
                    return(*this);
                }
                const_reference operator++(int) // value++
                {
                    const_reference buf(count);
                    this->count = count + 1;
                    return(buf);
                }
                const_reference operator--(int) // value--
                {
                    const_reference buf(count);
                    this->count = count - 1;
                    return(buf);
                }
                const_reference &operator++() // ++value
                {
                    const_reference buf(count);
                    this->count = count + 1;
                    return(buf);
                }
                const_reference &operator--() // --value
                {
                    const_reference buf(count);
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