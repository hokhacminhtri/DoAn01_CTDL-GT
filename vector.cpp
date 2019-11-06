#include"vector.h"
void InputVector(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu thu " << i + 1 << " trong vector: ";
		cin >> a[i];
	}
}

void OutputVector(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void multiVector(double a[], int n, double x)
{
	cout << "\nTich cua vector voi 1 so: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] * x << " ";
	}
}

void addVector(double a[], double b[], int n)
{
	cout << "\nTong 2 vector: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] + b[i] << " ";
	}
}