//走迷宫算法实现
#include<iostream>
#include<Windows.h>
using namespace std;
int maze[7][7] = { {2,2,2,2,2,2,2},
				  {2,0,0,2,2,0,2},
				  {2,0,2,2,0,0,2},
				  {2,0,0,0,0,0,2},
				  {2,0,2,0,2,0,2},
				  {2,0,2,0,2,0,2},
				  {2,2,2,2,2,2,2} };
void printMaze(){
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (maze[i][j] == 2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
				cout << "□";
			}
			if (maze[i][j] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_GREEN);
				cout << "○";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
			}
			if (maze[i][j] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
				cout << "◇";
			}
		}
		cout << endl;
	}
}
int visit(int i, int j) {
	maze[i][j] = 1;
	if (i == 5 && j == 5) {
		printMaze();
		return 0;
	}
	if (maze[i + 1][j] == 0)visit(i + 1, j);
	if (maze[i][j + 1] == 0)visit(i, j + 1);
	if (maze[i - 1][j] == 0)visit(i - 1, j);
	if (maze[i][j - 1] == 0)visit(i, j - 1);
	maze[i][j] = 0;
}
int main() {
	cout << "迷宫如下：" << endl;
	printMaze();
	cout << "按任意键开始走迷宫！" << endl;
	system("pause");
	visit(1, 1);
	system("pause");
}