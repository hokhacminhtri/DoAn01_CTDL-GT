#pragma once
struct Point { int i, j; };//The hien 2 gia tri hoanh do tung do cua ma tran

class list
{
private:
	Point arr[16];
	int count = 0;

public:
	list();
	~list();
	void push(Point);//them 1 point vao mang list
	void clear();//xoa mang chho count =0
	Point get(int);//tra ve Point thu i
	int size();//tra ve count hien tai
	void print();//In diem
};

class list_of_lists
{
private:
	list arr[64];
	int count = 0;

public:
	list_of_lists();//Cac ham tuong tu list
	void push(list);
	void remove(int);//Xoa list thu int i
	void clear();
	list get(int);
	int size();
	void print();
};
