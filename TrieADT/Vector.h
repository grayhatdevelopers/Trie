#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Vector {
private:
	T* array;
	int size;
	int capacity;
public:
	typedef T* iterator;

	Vector() {
		array = nullptr;
		size = 0;
		capacity = 0;
	}

	Vector(int Size) {
		array = new T[Size];
		size = 0;
		capacity = Size;
	}

	Vector(int Size, T& initialize) {
		array = new T[Size];
		capacity = Size;
		for (int i = 0; i < capacity; i++)
			array[i] = initialize;
		size = capacity;
	}

	Vector(const Vector& toCopy) {
		array = new T[toCopy.Size()];
		for (int i = 0; i < toCopy.Size(); i++) {
			array[i] = toCopy.array[i];
		}
		size = toCopy.Size();
		capacity = toCopy.Capacity();
	}

	void resize(int capacity, T value = T()) {
		int i = 0;
		if (isEmpty())
			array = new T[capacity];
		else {
			Vector<T> tempstring = *this;
			delete[] this->array;
			this->array = new T[capacity];
			for (i = 0; i < size && i < capacity; i++)
				this->array[i] = tempstring[i];
		}
		for (int j = i; j < capacity; j++) {
			array[j] = value;
		}
		this->capacity = capacity;
	}

	T push_back(T data) {
		if (size == capacity)
			resize((capacity + 1) * 2);
		return array[size++] = data;
	}

	T pop() {
		if (isEmpty())
			return T();
		T returnTo = array[size - 1];
		size--;
		return returnTo;
	}

	int find(T ex) {
		for (int i = 0; i < size; i++)
			if (array[i] == ex)
				return i;
		return -1;
	}

	iterator begin() {
		return array;
	}

	iterator end() {
		return array + Size();
	}

	int Capacity() const {
		return capacity;
	}

	int Size() const {
		return size;
	}

	bool isEmpty() {
		return (array == nullptr) || (size == 0);
	}

	bool erase(iterator it) {
		for (iterator theit = it; theit != end() - 1; theit++)
			*theit = *(theit + 1);
		size--;
		return true;
	}


	void clear() {
		delete[] array;
		size = 0;
		capacity = 0;
	}


	T operator[](int index) {
		if (isEmpty())
			throw invalid_argument("The vector is empty!");
		if (index < 0 || index >= size)
			throw out_of_range("The index is out of range!");
		return array[index];
	}

	Vector<T> operator=(const Vector& toCopy) {
		if (!isEmpty())
			clear();
		array = new T[toCopy.Size()];
		capacity = toCopy.Capacity();
		for (int i = 0; i < toCopy.Size(); i++)
			array[i] = toCopy.array[i];
		size = toCopy.Size();
		return *this;
	}



	//append a Vector
	Vector<T> operator+(const Vector& toCopy) {

		Vector<T> tempvector;
		for (int i = 0; i < this->size; i++)
			tempvector.push_back(this->array[i]);

		for (int i = 0; i < toCopy.Size(); i++)
			tempvector.push_back(toCopy.array[i]);

		return tempvector;
	}

	//append a Vector
	Vector<T>& operator+=(const Vector& toCopy) {

		for (int i = 0; i < toCopy.Size(); i++)
			this->push_back(this->toCopy[i]);

		return *this;
	}
};