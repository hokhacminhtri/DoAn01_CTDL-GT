#pragma once
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<iostream>
#include<math.h>
using namespace std;
void Input_Matrix(int matrix[][10], int n);//Ham Nhap 1 Ma tran Vuong co kich thuc n
void Output_Matrix(int matrix[][10], int n);//Ham Xuat 1 Ma Tran Vuong co kich thuoc n
int determinant(int matrix[10][10], int n);//input:1 ma tran vuong co hang=cot=n.Output:tra ve gia tri dinh thuc cua ma tran
void Inverse_Matrix(int matrix[10][10], int n);//Input 1 Ma tran vuong co kich thuoc hang=cot=n.Output=1 mA TRAN NGHICH DAO
void Multiplication_Matrix(int matrix_1[][10], int matrix_2[][10], int row_1, int col_1, int row_2, int col_2);//Input 2 ma tran voi 4 du lieu hang1,cot1,hang2,cot2.Output Ket qua phep nhan 
void Input_Matrix(int matrix_1[][10], int matrix_2[][10], int row_1, int col_1, int row_2, int col_2); //Ham nhap 2 ma tran khac ma tran vuong
void Output_Matrix(int matrix_1[][10], int matrix_2[][10], int row_1, int col_1, int row_2, int col_2);//Ham xuat 2 ma tran khac ma tran vuong
void Solve_Matrix(int matrix_1[][10], int matrix_2[][1],int row_1);//row=col
void swap(int matrix[10][10], int row, int col, int row_a, int row_b);	//Ham swap hoan doi row_a va row_b trong matrix
void Echelon_Matrix(int matrix[10][10], int result[10][10], int row, int col);	//Ham tim ma tran bac thang
int Rank_Matrix(int matrix[10][10], int result[10][10], int row, int col);
