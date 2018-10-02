
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;
int global_I;
int global_J;
enum Controls
{
	LEFT = 75,
	RIGH = 77,
	UP = 72,
	DOWN = 80,
	R = 114
};
void my_set_cursor(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coords = {};
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(h, coords);
}
typedef enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
}ConsoleColor;
void set_color(ConsoleColor backgound_text_color, ConsoleColor text_color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((backgound_text_color << 4) | text_color));
}

void print_pole(const int SIZE) {
	my_set_cursor(0, 0);
	system("cls");
	for (int i = 0; i < SIZE; i++)
	{

		for (int j = 0; j < SIZE; j++) {

			if (((i == 0) || (i == 4) || (i == 8) || (i == 12) || (i == 16)) && (j != 0) && ((j != 4) && (j != 8) && (j != 12) && (j != 16)))
			{
				cout << char(205) << char(205);
			}

			else if (((j == 0) || (j == 4) || (j == 8) || (j == 12) || (j == 16)) && ((i != 0) && (i != 4) && (i != 8) && (i != 12) && (i != 16)))
			{
				cout << char(186) << " ";
			}
			else if ((i == 0) && (j == 0)) {
				cout << char(201);
			}
			else if ((i == 16) && (j == 0)) {
				cout << char(200);
			}
			else if ((i == 16) && (j == 16)) {
				cout << char(205) << char(188);
			}
			else if ((i == 0) && (j == 16)) {
				cout << char(205) << char(187);
			}

			else if ((j == 0) && ((i == 4) || (i == 8) || (i == 12)))
			{
				cout << char(204);
			}
			else if ((j == 16) && ((i == 4) || (i == 8) || (i == 12)))
			{
				cout << char(205) << char(185);
			}
			else if (((i == 4) && (j == 4)) || ((i == 4) && (j == 8)) || ((i == 4) && (j == 12))) {
				cout << char(205) << char(206);
			}
			else if (((i == 8) && (j == 4)) || ((i == 8) && (j == 8)) || ((i == 8) && (j == 12))) {
				cout << char(205) << char(206);
			}
			else if (((i == 12) && (j == 4)) || ((i == 12) && (j == 8)) || ((i == 12) && (j == 12))) {
				cout << char(205) << char(206);
			}
			else if ((i == 0) && ((j == 4) || (j == 8) || (j == 12)))
			{
				cout << char(205) << char(203);

			}
			else if ((i == 16) && ((j == 4) || (j == 8) || (j == 12)))
			{
				cout << char(205) << char(202);
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}

}

void print_matrix(int matrix[][4], const int ROW, const int COL) {
	my_set_cursor(0, 0);
	cout << endl << endl;


	for (int i = 0; i < ROW; i++)
	{

		for (int j = 0; j < COL; j++)
		{
			if (matrix[i][j] == 0) {
				cout << "   " << "  " << "\t";
			}
			else {
				cout << "   " << matrix[i][j] << "\t";
			}
		}

		cout << endl << endl << endl << endl;
	}

}

void mixer(int matrix[][4], const int ROW, const int COL) {
	srand(time(0));
	for (int m = 1000000 - rand() % 501, k = rand() % 4; m > 0; m--, k = rand() % 4)
	{
		if (k == 0 && global_I > 0)
		{
			swap(matrix[global_I][global_J], matrix[global_I - 1][global_J]);
			--global_I;
		}
		else if (k == 1 && global_I < ROW - 1) {
			swap(matrix[global_I][global_J], matrix[global_I + 1][global_J]);
			++global_I;
		}
		else if (k == 2 && global_J < COL - 1)
		{
			swap(matrix[global_I][global_J], matrix[global_I][global_J + 1]);
			++global_J;
		}
		else if (k == 3 && global_J > 0)
		{
			swap(matrix[global_I][global_J], matrix[global_I][global_J - 1]);
			--global_J;
		}
	}
}

bool winner(int matrix[][4], const int ROW, const int COL) {
	int arr[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0 };
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] != matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}

//cutok dizayna)
void index_zero(int matrix[][4], const int ROW, const int COL) {

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (matrix[i][j] == 0) {
				{
					global_I = i;
					global_J = j;
				}
			}
		}
	}
}
//funnkciya kotoraya obespecivaet tipo kak zapusk progi.
void begin() {
	system("cls");
	cout << "Program copyrighted by Togrul" << endl;
	cout << "All rights reserved" << endl;
	cout << endl << endl << endl << endl;
	cout << "\t   " << "PYATNAWKI";
	cout << endl << endl << endl << endl;
	cout << endl << endl << endl << endl;
	cout << "Press any KEY for start game";
	cout << endl << endl << endl << endl;


	char button_code;
	button_code = _getch();
}

void main() {
	set_color(ConsoleColor::Yellow, ConsoleColor::Black);
	system("mode con lines=20 cols=35");
	const int ROW = 4;
	const int COL = 4;
	int matrix[ROW][COL] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0 };
	index_zero(matrix, ROW, COL);
	char button_code;
	int steps = 0;
	begin();
	mixer(matrix, ROW, COL);
	print_pole(17);
	print_matrix(matrix, ROW, COL);

	cout << "COUNTER:" << steps;
	while ((!winner(matrix, 4, 4)))
	{
		button_code = _getch();

		if (button_code == Controls::UP && global_I > 0)
		{
			swap(matrix[global_I][global_J], matrix[global_I - 1][global_J]);
			--global_I;
			steps++;

		}
		else if (button_code == Controls::DOWN && global_I < 3) {
			swap(matrix[global_I][global_J], matrix[global_I + 1][global_J]);
			++global_I;
			steps++;
		}
		else if (button_code == Controls::RIGH && global_J < 3)
		{
			swap(matrix[global_I][global_J], matrix[global_I][global_J + 1]);
			++global_J;
			steps++;
		}
		else if (button_code == Controls::LEFT && global_J > 0)
		{
			swap(matrix[global_I][global_J], matrix[global_I][global_J - 1]);
			--global_J;
			steps++;
		}
		else if (button_code == Controls::R)
		{
			mixer(matrix, ROW, COL);
			steps = 0;
		}
		print_pole(17);
		print_matrix(matrix, 4, 4);
		cout << "COUNTER:" << steps;
	}
	system("cls");
	cout << "YOU WON!" << endl;
	cout << "COUNTER:" << steps << endl;
}