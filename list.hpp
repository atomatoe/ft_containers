/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomatoe <atomatoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:40:07 by atomatoe          #+#    #+#             */
/*   Updated: 2020/12/13 18:02:55 by atomatoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_HPP
# define FT_LIST_HPP

#include <iostream>
// #include <iterator>
// При создании пустого массива в стандартном list, max size = max_size()объем доступной оперативной памяти.
// Это значение обычно отражает теоретический предел размера контейнера, 
// не более станд :: numeric_limits < difference_type > :: макс ( ). 
// Во время выполнения размер контейнера может быть ограничен значением, меньшим, чем max_size()объем доступной оперативной памяти.

// throw Ft_list::error();

template <class T>
class Ft_list
{
private:
	size_t			max_len; // максимальное количество возможных элементов в массиве
    size_t			count; // количество элементов на данный момент в массиве
    T				*pull; // массив
public:
    Ft_list() // пустой список
    {
        pull = NULL;
        count = 0;
		max_len = 0;
    }
    Ft_list(size_t value) // список состоит из value чисел, каждый элемент имеет значение по умолчанию
    {
		max_len = value;
      	pull = new T[value];
		count = 0;
      	while(count < value)
      	{
       		pull[count] = 0;
        	count++;
      	}
    }
    Ft_list(size_t value, T value2) // список состоит из value чисел, каждый элемент имеет значение value2
    {
		max_len = value;
      	pull = new T[value];
		count = 0;
      	while(count < value)
      	{
       		pull[count] = value2;
        	count++;
      	}
    }
    ~Ft_list() // деструктор
    {
        if(pull != NULL)
		{
			delete [] pull;
		}
    }
    Ft_list(const Ft_list &name) // конструктор копирования 
    {

    }
    size_t size(void) // Возвращает количество элементов в векторе	
    {
		return(count);
    }
    size_t max_size(void) // Возвращает максимально возможное количество элементов в векторе	
    {
		return(max_len);
    }
    void resize(size_t value) // Изменяет размер вектора на заданную величину
    {
		//count = value;
    }
    bool empty(void) // Возвращает true, если вектор пуст	
    {
		bool status = true;
		if(count > 0)
			status = false;
		return(status);
    }
    void clear(void) // удаляет все элементы вектора
    {
		for(int i = 0; i < count; i++)
		{
			delete pull[i];
			pull[i] = NULL;
		}
		count = 0;
    }
    void push_back(T name) // Вставка элемента в конец листа
    {
		if(!name)
			return ;
		else
		{
			if(count == 0)
			{
				pull = new T[1];
				pull[0] = name;
				count++;
			}
			else
			{
				count += 1;
				T* newPull = pull;
				pull = new T[count];
				for (unsigned int i = 0; i < count - 1; ++i)
					pull[i] = newPull[i];
				delete [] newPull;
				pull[count - 1] = name;
			}
		}
    }
    void push_front(T name) // Вставка элемента в начало листа
    {

		if(!name)
			return ;
		else
		{
			if(count == 0)
			{
				pull = new T[1];
				pull[0] = name;
				count++;
			}
			else
			{
				int len = 0;
				count += 1;
				T* newPull = pull;
				pull = new T[count];
				pull[0] = name;
				for (unsigned int i = 1; i < count; i++)
					pull[i] = newPull[len++];
				delete [] newPull;
			}
		}
    }
    void pop_back(void) // Удалить последний элемент листа
    {
		count--;
		pull[count] = 0;
    }
    void swap(Ft_list &name) // Обменять содержимое двух векторов
    {

    }
	//

	void print(void)
	{
		for(int i = 0; i < count; i++)
			std::cout << pull[i] << std::endl;
	}

	//
	T front(void)
	{
		return(pull[0]);
	}
	T back(void)
	{
		if(count == 0)
			return(pull[0]);
		return(pull[count - 1]);
	}
    Ft_list & operator=(const Ft_list &name) // оператор присваивания
	{

	}
	class error: public std::exception
    {
    public:
        virtual const char* what() const throw()
		{
			return ("Error! List is full, give me memory !!!");
		}
    };
};


#endif