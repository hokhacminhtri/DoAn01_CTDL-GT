#include <iostream>
#include "list.h"
using std::cout;

list::list() {}
list::~list() {}

void list::push(Point p)
{
	arr[count] = p;
	count++;
}

void list::clear() { count = 0; }

Point list::get(int i) { return arr[i]; }

int list::size() { return count; }

void list::print()
{
	for (int i = 0; i < count; ++i)
	{
		int greyI = arr[i].i ^ (arr[i].i >> 1);
		int greyJ = arr[i].j ^ (arr[i].j >> 1);
		cout << greyI * 4 + greyJ << " ";
	}
}

// Danh sach cac List
list_of_lists::list_of_lists() {}

void list_of_lists::push(list p)
{
	arr[count] = p;
	count++;
}

void list_of_lists::remove(int n)
{
	for (unsigned int i = n; i < count - 1; ++i)
		arr[n] = arr[n + 1];

	count--;
}

void list_of_lists::clear() { count = 0; }

list list_of_lists::get(int i) { return arr[i]; }

int list_of_lists::size() { return count; }

void list_of_lists::print()
{
	for (int i = 0; i < count; ++i)
	{
		arr[i].print();
		cout << "\n";
	}
}
