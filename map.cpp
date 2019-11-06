#include <iostream>
#include "map.h"
using std::cout;
#define SIZE 4
map::map() {};
map::~map() {};
void map::parseToMap(int arr[], int _size)// Chuyen doi ve ma gray tu mang nhap vao 
{
	for (unsigned int i = 0; i < _size; ++i)
	{
		int row = convertToGray(arr[i] / SIZE);
		int column = convertToGray(arr[i] % SIZE);
		matrix[row][column] = 1;
	}
}
void map::getMatrix(int m[4][4])//sao chep ma tran sang 1 ma tran khac
{
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			m[i][j] = matrix[i][j];
}
void map::printMap() //in map
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
			cout << matrix[i][j] << "  ";

		cout << "\n";
	}
}
inline int map::convertToGray(int n) { return (n >> 1) ^ n; }//Chuyen doi thanh ma Gray