#pragma once
#include <cstddef>
#include <iostream>

class table {

private:
	int* arr;
	int size;
	int numItems;

public: 
	table(int num);
	~table();
	int hash(int input);
	int insert(int input);
	int find(int input);
	int remove(int input);
	void printTable();
	int getSize() { return size; }
	int getNumItems() { return numItems; }


};

inline table::table(int num)
{
	arr = new int[num];
	size = num;
	numItems = 0;

	for (int i = 0; i < num; i++)
		this->arr[i] = INT_MIN;
}

inline table::~table()
{
	delete[] arr;
}

inline int table::hash(int input)
{
	return input%size;
}

inline int table::insert(int input)
{
	int index = hash(input);
	if (arr[index] == INT_MIN) {
		arr[index] = input;
		this->numItems++;
		return 1;
	}
	int count = 1;
	while (arr[index] != INT_MIN) {
		int f = arr[index];
		index = (index + 1)%size;
		count++;
	}
	arr[index] = input;
	this->numItems++;
	return count;
}

inline int table::find(int input)
{
	int index = hash(input);
	if (arr[index] == input) {
		return 1;
	}
	int count = 1;
	while (arr[index] != input && count < size) {
		index = (index + 1)%size;
		count++;
	}
	return count;
}

inline int table::remove(int input)
{
	int index = hash(input);
	if (arr[index] == input) {
		arr[index] = INT_MIN;
		this->numItems--;
		return 1;
	}
	int count = 1;
	while (arr[index] != input && count < size) {
		index = (index + 1)%size;
		count++;
	}
	if (index < size) {
		arr[index] = INT_MIN;
		this->numItems--;
	}
	return count;
}

inline void table::printTable()
{

	for (int x = 0; x < size; x++) {
		if (arr[x] == INT_MIN)
			std::cout << " E ";
		else std::cout << " " << arr[x] << " ";
	}
}
