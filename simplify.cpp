#include "simplify.h"
#include <iostream>
using namespace std;

#define SIZE 4


simplify::simplify(map m) { m.getMatrix(matrix); }
simplify::~simplify() {}

//Tao cac khoi chung
void simplify::makeCubes(list_of_lists& groups, int i, int j)
{
	list group;
	Point temp;
	bool found = false;

	int d[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	temp.i = i; temp.j = j;
	group.push(temp);//them diem i j vao list

	for (unsigned int k = 0; k < SIZE; ++k)
	{
		// Do theo cap
		if (matrix[(i + d[k][0] + 4) % 4][(j + d[k][1] + 4) % 4] == 1)
		{
			temp.i = (i + d[k][0] + 4) % 4; temp.j = (j + d[k][1] + 4) % 4;
			group.push(temp);//them diem i j vao list

			// Do tuyen tinh
			if (matrix[(i + 2 * d[k][0] + 4) % 4][(j + 2 * d[k][1] + 4) % 4] == 1 &&
				matrix[(i + 3 * d[k][0] + 4) % 4][(j + 3 * d[k][1] + 4) % 4] == 1)
			{
				temp.i = (i + 2 * d[k][0] + 4) % 4; temp.j = (j + 2 * d[k][1] + 4) % 4;
				group.push(temp);
				temp.i = (i + 3 * d[k][0] + 4) % 4; temp.j = (j + 3 * d[k][1] + 4) % 4;
				group.push(temp);//them diem i j vao list

				// Do quang 8
				if (matrix[(i + 0 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4][(j + 0 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4] == 1 &&
					matrix[(i + 1 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4][(j + 1 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4] == 1 &&
					matrix[(i + 2 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4][(j + 2 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4] == 1 &&
					matrix[(i + 3 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4][(j + 3 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4] == 1)
				{
					temp.i = (i + 0 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4; temp.j = (j + 0 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4;
					group.push(temp);//them diem i j vao list

					temp.i = (i + 1 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4; temp.j = (j + 1 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4;
					group.push(temp);

					temp.i = (i + 2 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4; temp.j = (j + 2 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4;
					group.push(temp);

					temp.i = (i + 3 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4; temp.j = (j + 3 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4;
					group.push(temp);
				}
				groups.push(group);//them list vào list_of_list
				group.clear();//Xoa list cu di 
				found = true;
				break;//dung 
			}
			// Tu giac vuong
			if (matrix[(i + 0 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4][(j + 0 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4] == 1 &&
				matrix[(i + 1 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4][(j + 1 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4] == 1) {
				temp.i = (i + 0 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4; temp.j = (j + 0 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4;
				group.push(temp);

				temp.i = (i + 1 * d[k][0] + d[(k + 1) % 4][0] + 4) % 4; temp.j = (j + 1 * d[k][1] + d[(k + 1) % 4][1] + 4) % 4;
				group.push(temp);//them temp vao list
			}
			groups.push(group);//them list vào list_of_list
			group.clear();//Xoa list cu di 
			temp.i = i; temp.j = j;
			group.push(temp);
			found = true;
		}
	}
	//Neu khong co nhom,push don
	if (!found)
		groups.push(group);
}

bool simplify::subset(list l1, list l2)
{
	//Kiem tra thanh vien cua l1 co o l2 khong
	for (unsigned int i = 0; i < l1.size(); ++i)
	{
		bool found = false;

		for (unsigned int j = 0; j < l2.size(); ++j)
			if (l1.get(i).i * SIZE + l1.get(i).j == l2.get(j).i * SIZE + l2.get(j).j)
			{
				found = true;
				break;
			}

		// Neu khong tim thay return false
		if (!found)
			return false;
	}
	return true;
}

bool simplify::commonPair(Point pair, list_of_lists groups, int skip)
{
	// Tim kiem cac cap chung
	for (unsigned int i = 0; i < groups.size(); ++i)
		for (unsigned int j = 0; j < groups.get(i).size(); ++j)
			if (i != skip && groups.get(i).get(j).i * SIZE + groups.get(i).get(j).j == pair.i * SIZE + pair.j)
				return true;

	// Neu khong co return false
	return false;
}

void simplify::optimize(list_of_lists & groups)// Loai bo cac diem chung cua cac te bao lon
{
	list_of_lists temp;
	for (unsigned int i = 0; i < groups.size(); ++i)
	{
		bool sub = false;
		for (unsigned int j = 0; j < temp.size(); ++j)
			if (i != j && subset(groups.get(i), temp.get(j)))
			{
				sub = true;
				break;
			}

		if (!sub)
			temp.push(groups.get(i));
	}
	groups = temp;


	// Loai bo cac cap chung
	temp.clear();
	bool common;
	for (int i = 0; i < groups.size(); ++i)
	{

		common = true;
		for (int j = 0; j < groups.get(i).size(); j++)
			if (!commonPair(groups.get(i).get(j), groups, i))
			{
				common = false;
				break;
			}

		if (!common)
			temp.push(groups.get(i));
	}
	groups = temp;
}

string simplify::parseToExp(list group)//chuyen thanh bieu thuc ket qua
{

	string result;
	string columns[] = { "cd","cD","CD","Cd" };
	string rows[] = { "ab","aB","AB","Ab" };

	string temp2 = columns[group.get(0).j] + rows[group.get(0).i];

	for (unsigned int i = 0; i < group.size(); ++i)
	{
		result = "";
		string temp1 = columns[group.get(i).j] + rows[group.get(i).i];

		for (unsigned int j = 0; j < temp2.size(); ++j)
			if (temp1.find(temp2[j]) != -1)
				result += temp2[j];

		temp2 = result;
	}

	return result;
}

void simplify::run()
{
	// Dau tien tao mot khoi va luu tru chung trong nhom
	list_of_lists groups;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j) {
			if (matrix[i][j] == 1)
				makeCubes(groups, i, j);
		}
	}

	// Loai bo cac khoi du thua
	optimize(groups);

	//In cac khoi
	cout << "\nCac Te Bao Lon:\n";
	groups.print();
	cout << "\n";

	//Yao bieu thuc ket qua va luu tru chung
	bool firstExp = true;
	string result;
	for (int i = 0; i < groups.size(); i++)
	{
		if (!firstExp)
			result = result + "+" + parseToExp(groups.get(i));
		else
		{
			firstExp = false;
			result = result + parseToExp(groups.get(i));
		}
	}
	cout << "Bieu Thuc Thu Duoc La " << endl;
	cout << result << "\n";
}