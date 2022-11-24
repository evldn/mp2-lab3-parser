#pragma once
#include <iostream>

using namespace std;
template <class T>
class Stack {
	int size;
	int top;
	T* mem;
public:
	Stack(int _size = 10) : size(_size), top(0), mem(new T[size]{}) { }
	Stack(const Stack& s) {
		size = s.size;
		top = s.top;
		mem = new T[size]{};
		for (int i = 0; i < top; i++) {
			mem[i] = s.mem[i];
		}
	}
	Stack& operator=(const Stack& s) {
		if (*this == s)
			return *this;
		if (size > 0)
			delete[] mem;
		size = s.size;
		top = s.top;
		mem = new T[size]{};
		for (int i = 0; i < top;i++) {
			mem[i] = s.mem[i];
		}
		return *this;
	}
	bool IsEmpty() {
		if (top == 0)
			return true;
		return false;
	}
	bool IsFull() {
		if (top == size - 1)
			return true;
		return false;
	}
	int getSize() {
		return top;
	}
	void Push(T s) {
		if (IsFull()) {
			int new_size = size * 2;
			T* tmp = new T[new_size]{};
			for (int i = 0; i < top; i++) {
				tmp[i] = mem[i];
			}
			if (size > 0)
				delete[] mem;
			mem = tmp;
			size = new_size;
		}
		mem[top] = s;
		top++;
	}
	T Top() {
		return mem[top - 1];
	}
	void Pop() {
		if (IsEmpty())
			throw - 1;
		top--;
	}
	~Stack() {
		if (size > 0)
			delete[] mem;
	}
};