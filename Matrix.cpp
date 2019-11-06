#include"Matrix.h"

void Input_Matrix(int matrix[][10], int n) //Ham Nhap 1 Ma tran Vuong co kich thuc n
{
	cout << "Enter the elements of the matrix  :\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Row " << i + 1 << endl;
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
void Output_Matrix(int matrix[][10], int n)//Ham Xuat 1 Ma Tran Vuong co kich thuoc n
{
	cout << "The entered matrix  is :" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout <<"  "<< matrix[i][j] << "   ";
		}
		cout << endl;
	}	
}
int determinant(int matrix[10][10], int n)//input:1 ma tran vuong co hang=cot=n
{                                          //Output:tra ve gia tri dinh thuc cua ma tran
	int det = 0;
	int submatrix[10][10];
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
		}
	}
	return det;
}
void Inverse_Matrix(int matrix[10][10], int n)//Input 1 Ma tran vuong co kich thuoc hang=cot=n
{                                              //Output=1 mA TRAN NGHICH DAO
	int deter = determinant(matrix, n); //tinh dinh thuc cua ma tran input
	if (deter!=0)  //kiem tra dinh thuc khac 0
	{
		int submatrix[10][10];   //ma tran phu 
		float result[10][10];       //ma tran ket qua
		for (int i = 0; i < n; i++) {  //gan ma tran ket qua =0;
			for (int j = 0; j < n; j++)
				result[i][j] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp = 0;
				int subi = 0;
				for (int k = 0; k < n; k++)
				{
					int temp = 0;
					int subj = 0;
					if (j == k)
						continue;
					for (int l = 0; l < n; l++)
					{
						temp = i + j + 2;
						if (i == l)   
							continue;
						submatrix[subi][subj] = matrix[k][l];
						subj++;
					}
					subi++;
				}
				result[i][j] = pow(-1, temp) * float((determinant(submatrix, n - 1)));
			}
		}
		cout << "Inverse of the matrix is " << endl;
		for (int i = 0; i < n; i++) {
			cout <<"("<< "1" << "/" << deter<<")" << "*" <<"  ";
			cout << "(" << " ";
			for (int j = 0; j < n; j++)
				cout << result[i][j] << "    ";
			cout << ")" << " ";
			cout << endl;
		}
	}
	else//neu dinh thuc =0 .se in ra man hinh
	{
		cout << "Dinh Thuc Bang 0.Khong Co Ma Tran Kha Nghich" << endl;
	}
}
void Multiplication_Matrix(int matrix_1[][10], int matrix_2[][10], int row_1, int col_1, int row_2, int col_2)
{       
	//Input 2 ma tran voi 4 du lieu hang1,cot1,hang2,cot2.  col_1=row_2 .Output Ket qua phep nhan 
	if (col_1!=row_2)
	{
		cout << " Nhap khong hop le " << endl;
	}
	else
	{
		int resulf_matrix[10][10];  //ma tran ket qua
		for (int i = 0; i < row_1; i++)  //gan ma tran ket qua bang  0
		{
			for (int j = 0; j < col_2; j++)
			{
				resulf_matrix[i][j] = 0;
			}
		}
		for (int i = 0; i < row_1; i++)
		{
			for (int j = 0; j < col_2; j++)
			{
				for (int k = 0; k < col_1; k++)
				{                                                           //Dung 3 vong lap for voi 3 bien i,j,k
					resulf_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];//Ma tran ket qua [i][j]=matran1[i](k)+matran2[k][j]

				}
			}
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "RESULT           " << endl;
		for (int i = 0; i < row_1; i++) //in ket qua
		{
			for (int j = 0; j < col_2; j++)
			{
				cout << resulf_matrix[i][j] << "  ";
			}
			cout << endl;
		}
	}
}
void Input_Matrix(int matrix_1[][10], int matrix_2[][10], int row_1, int col_1, int row_2, int col_2)//Ham nhap 2 ma tran khac ma tran vuong
{
	cout << "Enter the elements of the matrix 1 :\n";//Nhap ma tran thu 1
	for (int i = 0; i < row_1; i++)
	{
		cout << "Row " << i + 1 << endl;
		for (int j = 0; j < col_1; j++)
		{
			cin >> matrix_1[i][j];
		}
	}
	cout << "Enter the elements of the matrix 2 :\n"; //Nhap ma tran thu 2
	for (int i = 0; i < row_2; i++)
	{
		cout << "Row " << i + 1 << endl;
		for (int j = 0; j < col_2; j++)
		{
			cin >> matrix_2[i][j];;
		}
	}
}
void Output_Matrix(int matrix_1[][10], int matrix_2[][10], int row_1, int col_1, int row_2, int col_2)
{                                              //Ham xuat 2 ma tran khac ma tran vuong
	cout << "The entered matrix 1 is :" << endl; //Xuat ma tran 1
	for (int i = 0; i < row_1; i++)
	{
		for (int j = 0; j < col_1; j++)
		{
			cout << matrix_1[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "The entered matrix 2 is :" << endl; //Xuat ma tran 2
	for (int i = 0; i < row_2; i++)
	{
		for (int j = 0; j < col_2; j++)
		{
			cout << matrix_2[i][j] << "  ";
		}
		cout << endl;
	}
}
void Solve_Matrix(int matrix_1[][10], int matrix_2[][1], int row_1)//He Phuong Trinh Co Dang AX=B(A=Matrix_1,B=Matrix_2)
{
	int submatrix[10][10];
	int denta[10];
	int deter = determinant(matrix_1,row_1);//tinh dinh thuc ma tran ban  dau 
	if (deter != 0)
	{
		int temp = row_1;
		int k = 0;
		while (temp > 0)
		{
			for (int i = 0; i < row_1; i++)
			{

				for (int i = 0; i < row_1; i++)
				{
					for (int j = 0; j < row_1; j++)
					{
						submatrix[i][j] = matrix_1[i][j];
					}
				}
				for (int j = 0; j < row_1; j++)
				{
					submatrix[j][i] = matrix_2[j][0];
				}
				denta[k] = determinant(submatrix, row_1);
				k++;
			}
			if (k == 2)
			{
				break;
			}
			temp--;
		}
		cout << "HE PHUONG TRINH CO " << row_1 << "NGHIEM" << endl;
		for (int i = 0; i < row_1; i++)
		{
			
			cout <<float(denta[i] /deter) << endl;
		}
	}
	else
	{
		int temp = row_1;
		int k = 0;
		while (temp > 0)
		{
			for (int i = 0; i < row_1; i++)
			{

				for (int i = 0; i < row_1; i++)
				{
					for (int j = 0; j < row_1; j++)
					{
						submatrix[i][j] = matrix_1[i][j];
					}
				}
				for (int j = 0; j < row_1; j++)
				{
					submatrix[j][i] = matrix_2[j][0];
				}
				denta[k] = determinant(submatrix, row_1);
				if (denta[k] != 0)
				{
					cout << endl;
					cout << "He Phuong Trinh Vo Nghiem " << endl;
					exit(0);
				}
				k++;
			}
			temp--;
		}
		cout << "He Phuong trinh co vo so nghiem hoac vo nghiem " << endl;
	}

}

void swap(int matrix[10][10], int row, int col, int row_a, int row_b)//Ham hcuyen doi vi tri cua rowa va row b
{
	if (row_a * row_b < 0 || row_a == row_b || row_a >= row || row_b >= row)
	{
		return;
	}
	for (int j = 0; j < col; j++)
	{
		int temp = matrix[row_a][j];
		matrix[row_a][j] = matrix[row_b][j];
		matrix[row_b][j] = temp;
	}
}

void Echelon_Matrix(int matrix[10][10], int result[10][10], int row, int col)//tim ma tran bac thang cua ma tran input
{
	//Gan cac phan tu matrix sang result
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			result[i][j] = float(matrix[i][j]);
		}
	}
	int i = 0, j = 0;
	while (i < row || j < col)
	{
		if (result[i][j] != 0)
		{
			for (int k = i + 1; k < row; k++)
			{
				int t = (1.0 * result[k][j]) / result[i][j];
				for (int h = 0; h < col; h++)
				{
					result[k][h] -= t * result[i][h];
				}
			}
			i++;
			j++;
		}
		else
		{
			bool flag = true;	//Gan co hieu(flag)
			for (int k = i + 1; k < row; k++)
			{
				if (result[k][j] != 0)
				{
					swap(result, row, col, i, k);
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				j++;
			}
		}
	}
}

//Tim hang cua ma tran dua tren ma tran bac thang
int Rank_Matrix(int matrix[10][10], int result[10][10], int row, int col)
{
	Echelon_Matrix(matrix, result, row, col);
	int rank = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (result[i][j] != 0)
			{
				rank++;
				break;
			}
		}
	}
	return rank;
}
