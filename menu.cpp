#include"Matrix.h"
#include"vector.h"
#include"simplify.h"
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void bangchon(int chon, int choncu)
{
	if (chon == 1)
	{
		if (choncu == 2)
		{
			gotoxy(26, 11);
			printf(" ");
			gotoxy(46, 11);
			printf(" ");
		}
		gotoxy(26, 10);
		printf("[");
		gotoxy(70, 10);
		printf("]");
	}
	if (chon == 2)
	{
		if (choncu == 1)
		{
			gotoxy(26, 10);
			printf(" ");
			gotoxy(70, 10);
			printf(" ");
		}
		if (choncu == 3)
		{
			gotoxy(26, 12);
			printf(" ");
			gotoxy(50, 12);
			printf(" ");
		}
		gotoxy(26, 11);
		printf("[");
		gotoxy(46, 11);
		printf("]");
	}
	if (chon == 3)
	{
		if (choncu == 2)
		{
			gotoxy(26, 11);
			printf(" ");
			gotoxy(46, 11);
			printf(" ");
		}
		if (choncu == 4)
		{
			gotoxy(26, 13);
			printf(" ");
			gotoxy(50, 13);
			printf(" ");
		}
		gotoxy(26, 12);
		printf("[");
		gotoxy(50, 12);
		printf("]");
	}
	if (chon == 4)
	{
		if (choncu == 3)
		{
			gotoxy(26, 12);
			printf(" ");
			gotoxy(50, 12);
			printf(" ");
		}
		gotoxy(26, 13);
		printf("[");
		gotoxy(50, 13);
		printf("]");
		if (choncu == 5)
		{
			gotoxy(26, 14);
			printf(" ");
			gotoxy(50, 14);
			printf(" ");
		}
		gotoxy(26, 13);
		printf("[");
		gotoxy(50, 13);
		printf("]");
	}
	if (chon == 5)
	{
		if (choncu == 4)
		{
			gotoxy(26, 13);
			printf(" ");
			gotoxy(50, 13);
			printf(" ");
		}
		gotoxy(26, 14);
		printf("[");
		gotoxy(50, 14);
		printf("]");
		if (choncu == 6)
		{
			gotoxy(26, 15);
			printf(" ");
			gotoxy(50, 15);
			printf(" ");
		}
		gotoxy(26, 14);
		printf("[");
		gotoxy(50, 14);
		printf("]");
	}
	if (chon == 6)
	{
		if (choncu == 5)
		{
			gotoxy(26, 14);
			printf(" ");
			gotoxy(50, 14);
			printf(" ");
		}
		if (choncu == 7)
		{
			gotoxy(26, 16);
			printf(" ");
			gotoxy(50, 16);
			printf(" ");
		}
		gotoxy(26, 15);
		printf("[");
		gotoxy(50, 15);
		printf("]");
	}
	if (chon == 7)
	{
		if (choncu == 6)
		{
			gotoxy(26, 15);
			printf(" ");
			gotoxy(50, 15);
			printf(" ");
		}
		gotoxy(26, 16);
		printf("[");
		gotoxy(50, 16);
		printf("]");
		if (choncu == 8)
		{
			gotoxy(26, 17);
			printf(" ");
			gotoxy(57, 17);
			printf(" ");
		}
		gotoxy(26, 16);
		printf("[");
		gotoxy(50, 16);
		printf("]");
	}
	if (chon == 8)
	{
		if (choncu == 7)
		{
			gotoxy(26, 16);
			printf(" ");
			gotoxy(50, 16);
			printf(" ");
		}
		gotoxy(26, 17);
		printf("[");
		gotoxy(57, 17);
		printf("]");
	}

}
void menu()
{
	system("cls");
	int chon = 1;
	int choncu = 0;
	gotoxy(25, 9);
	printf(">> DO AN CAU TRUC DU LIEU VA GIAI THUAT <<");
	gotoxy(30, 10);
	printf("TIM TAT CA DA THUC TOI TIEU CUA HAM BOOL \n");
	gotoxy(30, 11);
	printf("CONG HAI VECTO \n");
	gotoxy(30, 12);
	printf("NHAN VECTO VOI 1 SO \n");
	gotoxy(30, 13);
	printf("DINH THUC MA TRAN");
	gotoxy(30, 14);
	printf("MA TRAN NGICH DAO");
	gotoxy(30, 15);
	printf("NHAN HAI MA TRAN");
	gotoxy(30, 16);
	printf("HANG CUA MA TRAN \n");;
	gotoxy(30, 17);
	printf("HE PHUONG TRINH TUYEN TINH \n");

	bangchon(chon, choncu);
	while (1)
	{
		int h;
		if (_kbhit())
		{
			h = _getch();
			if (h == 13)
				break;
			if (h == 80)
			{
				if (chon < 8)
				{
					choncu = chon;
					chon++;
					bangchon(chon, choncu);
				}
			}
			if (h == 72)
			{
				if (chon > 1)
				{
					choncu = chon;
					chon--;
					bangchon(chon, choncu);
				}
			}
		}
	}
	if (chon == 1)
	{
		system("cls");
		int size;
		cout << "Tham khao cach nhap o anh trong Resourcce Files " << endl;
		cout << "Nhap So Luong Cac Minterms: ";
		cin >> size;

		//Khoi tao 1 mang
		int* minterm = new int[size];
		//Neu khong co khoang tron exit(0);
		if (!minterm) exit(0);

		// Nhap cac Minterms
		cout << "Nhap Minterms : ";
		for (unsigned int i = 0; i < size; ++i)
			cin >> minterm[i];

		// Chuyen doi du lieu nhap vao thanh map
		map map;
		map.parseToMap(minterm, size);
		// In K_Map
		cout << "\nK-Map:\n";
		map.printMap();
		cout << "\n";

		simplify simplify(map);

		simplify.run();
		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
	if (chon == 2)
	{
		system("cls");
		double vector1[10], vector2[10];
		int	n;
		cout << "Enter the size of the vector";
		cin >> n;
		InputVector(vector1, n);
		InputVector(vector2, n);
		addVector(vector1, vector2, n);
		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
	if (chon == 3)
	{
		system("cls");
		double vector[10];
		int	n, x;
		cout << "Enter the size of the vector";
		cin >> n;
		cout << "Enter the value to multiply";
		cin >> x;
		InputVector(vector, n);
		multiVector(vector, n, x);
		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
	if (chon == 4)
	{
		system("cls");
		int n;
		int matrix[10][10];
		cout << "Enter the size of the matrix:\n";
		cin >> n;
		Input_Matrix(matrix, n);
		Output_Matrix(matrix, n);
		determinant(matrix, n);
		cout << "Determinant of the matrix is " << determinant(matrix, n) << endl;
		cout << endl;
		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
	if (chon == 5)
	{
		system("cls");
		int n;
		int matrix[10][10];
		cout << "Enter the size of the matrix:\n";
		cin >> n;
		Input_Matrix(matrix, n);
		Output_Matrix(matrix, n);
		Inverse_Matrix(matrix, n);
		cout << endl;
		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
	if (chon == 6)
	{
		system("cls");
		int matrix_1[10][10], matrix_2[10][10], row_1, col_1, row_2, col_2;
		cout << "Enter the row of the matrix 1 : \n";
		cin >> row_1;
		cout << "Enter the col of the matrix 1: \n";
		cin >> col_1;
		cout << "Enter the row of the matrix 2 : \n";
		cin >> row_2;
		cout << "Enter the col of the matrix 2: \n";
		cin >> col_2;
		Input_Matrix(matrix_1, matrix_2, row_1, col_1, row_2, col_2);
		Output_Matrix(matrix_1, matrix_2, row_1, col_1, row_2, col_2);
		Multiplication_Matrix(matrix_1, matrix_2, row_1, col_1, row_2, col_2);
		cout << endl;
		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
	if (chon == 7)
	{
		system("cls");
		int matrix[10][10],result[10][10],row,col;
		cout << "Enter the row of the matrix  : \n";
		cin >> row;
		cout << "Enter the col of the matrix : \n";
		cin >> col;
		cout << "Enter the elements of the matrix  :\n";
		for (int i = 0; i < row; i++)
		{
			cout << "Row " << i + 1 << endl;
			for (int j = 0; j < col; j++)
			{
				cin >> matrix[i][j];
			}
		}
		cout << "Hang cua ma tran la " << endl;
		cout<< Rank_Matrix(matrix, result, row, col);
		cout << endl;
		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
	
	if (chon == 8)
	{
			system("cls");
			int matrix_1[10][10], matrix_2[10][1], row;//row=col. Co Dang AX=B.A=matrix_1.B=matrix_2
			cout << " He Phuong Trinh tuyen tinh co dang AX=B " << endl;
			cout << " Row A =Col A = Row B " << endl;
			cout << " Col B =1 " << endl;
			cout << "Enter the row of the matrix A : \n";
			cin >> row;
			Input_Matrix(matrix_1, row);
			Output_Matrix(matrix_1, row);
			cout << "Enter the elements of the matrix B  :\n";
			for (int i = 0; i < row; i++)
				{
				cout << "Row " << i + 1 << endl;
				for (int j = 0; j < 1; j++)
				{
					cin >> matrix_2[i][0];
				}
				}
			cout << "The entered matrix B  is :" << endl;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < 1; j++)
				{
					cout << matrix_2[i][0] << "  ";
				}
				cout << endl;
			}
			Solve_Matrix(matrix_1, matrix_2, row);
			cout << endl;
			cout << "Press enter to return to menu";
			while (1)
				if (_kbhit())
				{
					int in = _getch();
					if (in == 13)
						system("cls");
					break;
				}
			menu();
	}
}
