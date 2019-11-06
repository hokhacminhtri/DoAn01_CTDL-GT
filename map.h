#pragma once
#include <string>
using std::string;

#define SIZE 4

class map
{
private:
	int matrix[SIZE][SIZE] = { 0 }; //Ban Do cua ma tran
	inline int convertToGray(int); //chuyen tu binary sang gray

public:
	map();
	~map();
	void parseToMap(int[], int);// Xu li so lieu nhap vao 

	void getMatrix(int m[4][4]);//sao chep ma tran sang 1 ma tran khac

	void printMap();//in Map
};

