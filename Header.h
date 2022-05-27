#pragma once

#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;


template <typename T> class MyVector
{

	// arr is the integer pointer
	// which stores the address of our vector
	T* arr;

	int capacity; //talpa

	int current; //elementu kiekis

public:
		//member functions
	MyVector() //default konstruktorius
	{
		arr = new T[1];
		capacity = 1;
		current = 0;
	}
	~MyVector()
	{
		delete[] arr;
	};

	MyVector& operator =(const MyVector& rhs)
	{
		if (rhs.current > current)
		{
			delete[] arr;
			capacity = rhs.current + 5;
			arr = new int[capacity];
		}
		for (int i = 0; i < rhs.current; i++)
		{
			arr[i] = rhs.arr[i];
		}

		current = rhs.current;

		return *this;
	}

	
		//element access
	T& operator[](int a)
	{
		return arr[a];
	}
	T& at(int index)
	{
		return arr[index];
	}
	T& front()
	{
		return arr[0];
	}
	T& back()
	{
		return arr[current - 1];
	}
	T& data()
	{
		return arr;
	}
		//iterators
	
	T& begin()
	{
		return arr[0];
	}
	T& end()
	{
		return arr[current - 1];
	}
	T& rbegin()
	{
		return arr[current - 1];
	}
	T& rend()
	{
		return arr[0];
	}

		//capacity
	int size() { return current; }// function to get size of the vector
	int getcapacity() { return capacity; }// function to get capacity of the vector
	bool empty()
	{
		return current == 0;
	}
	void reserve(int n)
	{
		if (n < capacity)
		{
			capacity = n;
		}
		
	}
	void shrink_to_fit()
	{
		capacity = current;
		T* newarr = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;
	}

		//modifiers
	void clear()
	{
		current = 0;
	}
	void insert(int index, int value)
	{
		if (capacity != current)
		{
			for (int i = current - 1; i >= index; i--)
			{
				arr[i + 1] = arr[i];
			}
			arr[index] = value;
			current++;
		}
		else
		{
			capacity *= 2;
			T* newarray = new T[capacity];
			for (int i = 0; i < current; i++)
			{
				newarray[i] = arr[i];
			}
			delete[] arr;
			arr = newarray;
			insert(index, value);
		}
	}
	void erase(int index)
	{
		for (int i = index; i < current - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		current--;
	}
	void resize(int n)
	{
		capacity = n;
		T* newarr = new T[capacity];
		for (int i = 0; i < current; i++)
		{
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;
	}
	
	
	void push_back(T data) //std::vector push
	{
		if (current == capacity) { //jeigu sutampa talpa su elementu skaiciumi, padidiname talpa
			T* temp = new T[2 * capacity];

			for (int i = 0; i < capacity; i++) { //perkopijuojame visus elementus
				temp[i] = arr[i];
			}

			delete[] arr; //istriname pradini masyva
			capacity *= 2;
			arr = temp;
		}

		arr[current] = data; //irasome naujus duomenis
		current++;
	}

	T get(int index) //funkcija gauti norima elementa zinant jo numeri
	{
		if (index < current) 
			return arr[index];
	}

	void pop_back() //funkcija istrinanti paskutini elementa
	{ 
		current--;
	} 
	
		//operatoriai
	bool operator==(const MyVector& rhs) const
	{
		if (size() != rhs.size())
		{
			return false;
		}
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] != rhs.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator!=(const MyVector& rhs) const
	{
		return !(*this == rhs);
	}
	bool operator<(const MyVector& rhs) const
	{
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] > rhs.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator<=(const MyVector& rhs) const
	{
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] >= rhs.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator>(const MyVector& rhs) const
	{
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] < rhs.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator>=(const MyVector& rhs) const
	{
		for (int i = 0; i < size(); i++)
		{
			if (arr[i] <= rhs.arr[i])
			{
				return false;
			}
		}
		return true;
	}



	void print()
	{
		for (int i = 0; i < current; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

};
