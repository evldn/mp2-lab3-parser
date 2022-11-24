#pragma once
#include <iostream>

using namespace std;

template<class T>
class Queue {
	int size;
	int start;
	int end;
	T* mem;
	int next(int i) { return (i + 1) % size; }
public:
	Queue(int _size = 1) : size(_size), end(0), start(next(end)), mem(new T[size]) { }
	Queue(const Queue<T>& q) {
		size = q.size;
		start = q.start;
		end = q.end;
		mem = new T[size];
		for (int i = start; i != next(end); i = next(i)) {
			mem[i] = q.mem[i];
		}
	}
	Queue<T>& operator=(const Queue<T>& q) {
		if (this == &q)
			return *this;
		if (size > 0)
			delete[] mem;
		size = q.size;
		end = q.end;
		start = q.start;
		mem = new T[size];
		for (int i = start; i != next(end); i = next(i)) {
			mem[i] = q.mem[i];
		}
		return *this;
	}
	int getSize() {
		if (IsEmpty())
			return 0;
		if (end < start) {
			return  size - start + end + 1;
		}
		else {
			return end - start + 1;
		}
	}
	bool IsEmpty() {
		if (next(end) == start)
			return true;
		return false;
	}
	bool IsFull() {
		if (next(next(end)) == start)
			return true;
		return false;
	}
	void Push(T val) {
		if (IsFull()) {
			int new_size = size * 2;
			T* tmp = new T[new_size];
			int index = 1;
			for (int i = start; i != next(end); i = next(i)) {
				tmp[index] = mem[i];
				index++;
			}
			delete[] mem;
			mem = tmp;
			end = size - 1;
			start = 1;
			size = new_size;
		}
		end = next(end);
		mem[end] = val;
	}
	T Top() {
		return mem[start];
	}
	void Pop() {
		if (IsEmpty())
			throw - 1;
		start = next(start);
	}
	~Queue() {
		if (size > 0)
			delete[] mem;
	}
};