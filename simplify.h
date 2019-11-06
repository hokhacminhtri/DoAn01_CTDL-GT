#pragma once
#include <iostream>
#include "map.h"
#include "list.h"

class simplify
{
private:
	int matrix[SIZE][SIZE];
	void makeCubes(list_of_lists&, int, int); //Tao cac  te bao lon 
	bool subset(list, list); //Kiem Tra trung` voi cac nhom khac
	bool commonPair(Point, list_of_lists, int);// Tim kiem cac cap chung
	void optimize(list_of_lists&);// Loai bo cac cap chung
	string parseToExp(list);

public:
	simplify(map);
	~simplify();
	void run();
};
