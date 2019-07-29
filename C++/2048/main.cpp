#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
using namespace std;
int MAP[4][4];
int over;

void Print();
void Add(int);
int Move();
int MoveUp();
int MoveLeft();
int MoveDown();
int MoveRight();
void StartGame();

int main() {
	StartGame();
	while (1) {
		int dir = Move();
		Add(dir);
		fflush(stdin);
		
		system("CLS");
		Print();
	}
	return 0;
}

/*Print the game*/
void Print() {
	printf("\t\t©°%s©¤©Ð%s©¤©Ð%s©¤©Ð%s©¤©´\n","©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤");
	printf("\t\t©¦      ©¦      ©¦      ©¦      ©¦\n");
	printf("\t\t©¦%4d  ©¦%4d  ©¦%4d  ©¦%4d  ©¦\n", MAP[0][0], MAP[0][1], MAP[0][2], MAP[0][3]);
	printf("\t\t©À%s©¤©à%s©¤©à%s©¤©à%s©¤©È\n", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤");
	printf("\t\t©¦      ©¦      ©¦      ©¦      ©¦\n");
	printf("\t\t©¦%4d  ©¦%4d  ©¦%4d  ©¦%4d  ©¦\n", MAP[1][0], MAP[1][1], MAP[1][2], MAP[1][3]);
	printf("\t\t©À%s©¤©à%s©¤©à%s©¤©à%s©¤©È\n", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤");
	printf("\t\t©¦      ©¦      ©¦      ©¦      ©¦\n");
	printf("\t\t©¦%4d  ©¦%4d  ©¦%4d  ©¦%4d  ©¦\n", MAP[2][0], MAP[2][1], MAP[2][2], MAP[2][3]);
	printf("\t\t©À%s©¤©à%s©¤©à%s©¤©à%s©¤©È\n", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤");
	printf("\t\t©¦      ©¦      ©¦      ©¦      ©¦\n");
	printf("\t\t©¦%4d  ©¦%4d  ©¦%4d  ©¦%4d  ©¦\n", MAP[3][0], MAP[3][1], MAP[3][2], MAP[3][3]);
	printf("\t\t©¸%s©¤©Ø%s©¤©Ø%s©¤©Ø%s©¤©¼\n", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤", "©¤©¤©¤©¤©¤");
	if (over == 0)
	{
		printf("\n");
	}
	else {
		printf("\t\t \tGAME OVER\n");
	}
	printf("\t Press [E] to Exit \t Press[R] to restart.");
}


void StartGame() {
	memset(MAP, 0, sizeof(MAP));
	Add(0);
	over = 0;
	Print();
}
int Move() {
	fflush(stdin);
	int key = _getch();
	int dir = -1;
	switch (key) {
	case 119:
		dir = 1;
		MoveUp();
		break;
	case 97:
		dir = 2;
		MoveLeft();
		break;
	case 115:
		dir = 3;
		MoveDown();
		break;
	case 100:
		dir = 4;
		MoveRight();
		break;
	case 69:
		exit(0);
	case 82:
		StartGame();
	}
	return dir;
}

/*
	Randomly add a number to the map, according to the input direction;
	0: initilize
	1: up
	2: left
	3: down
	4: right
*/
void Add(int dir) {
	srand((unsigned int)time(NULL));
	int num = rand();
	int flag = num % 2;

	if (flag == 0) {
		num = 2;
	}
	else {
		num = 4;
	}
	
	int row = rand() % 4;
	int col = rand() % 4;

	if (dir == 0) {
		MAP[row][col] = num;
	}
	else if (dir == 1) {
		if (MAP[3][col] == 0) {
			MAP[3][col] = num;
		}
		else {
			over = 1;
			for (int i = 0; i < 4; i++)
			{
				if (MAP[3][i] == 0)
				{
					MAP[3][i] = num;
					over = 0;
					break;
				}
			}
		}
	}
	else if (dir == 2) {
		if (MAP[row][3] == 0) {
			MAP[row][3] = num;
		}
		else {
			over = 1;
			for (int i = 0; i < 4; i++)
			{
				if (MAP[i][3] == 0)
				{
					MAP[i][3] = num;
					over = 0;
					break;
				}
			}
		}
	}
	else if (dir == 3) {
		if (MAP[0][col] == 0) {
			MAP[0][col] = num;
		}
		else {
			over = 1;
			for (int i = 0; i < 4; i++)
			{
				if (MAP[0][i] == 0)
				{
					MAP[0][i] = num;
					over = 0;
					break;
				}
			}
		}
	}
	else if (dir == 4) {
		if (MAP[row][0] == 0) {
			MAP[row][0] = num;
		}
		else {
			over = 1;
			for (int i = 0; i < 4; i++)
			{
				if (MAP[i][0] == 0)
				{
					MAP[i][0] = num;
					over = 0;
					break;
				}
			}
		}
	}
}

int MoveUp() {
	int row, col;

	for (col = 0; col < 4; col++) {
		for (row = 0; row < 3; row++) {
			if (MAP[row][col] == 0) continue;
			else{
				for (int temp = row + 1; temp < 4; temp++) {
					if (MAP[temp][col] != 0 && MAP[temp][col] != MAP[row][col]) break;
					if (MAP[temp][col] == MAP[row][col]) {
						MAP[row][col] *= 2;
						MAP[temp][col] = 0;
						break;
					}
				}
			}
		}
	}
	int counter;
	for (col = 0; col < 4; col++) {
		counter = 0;
		for (row = 0; row < 4; row++) {
			if (MAP[row][col] != 0) {
				MAP[counter][col] = MAP[row][col];
				if (counter != row)	MAP[row][col] = 0;
				counter++;
			}
		}
	}
	return 1;
}

int MoveLeft() {
	int row, col;

	for (row = 0; row < 4; row++) {
		for (col = 0; col < 3; col++) {
			if (MAP[row][col] == 0) continue;
			else {
				for (int temp = col + 1; temp < 4; temp++) {
					if (MAP[row][temp] != 0 && MAP[row][temp] != MAP[row][temp]) break;
					if (MAP[row][temp] == MAP[row][col]) {
						MAP[row][col] *= 2;
						MAP[row][temp] = 0;
						break;
					}
				}
			}
		}
	}

	int counter;
	for (row = 0; row < 4; row++) {
		counter = 0;
		for (col = 0; col < 4; col++) {
			if (MAP[row][col] != 0) {
				MAP[row][counter] = MAP[row][col];
				if (counter != col)	MAP[row][col] = 0;
				counter++;
			}
		}
	}
	return 1;
}

int MoveDown() {
	int row, col;
	
	for (col = 0; col < 4; col++) {
		for (row = 3; row > 0; row--) {
			if (MAP[row][col] == 0) continue;
			else {
				for (int temp = row - 1; temp >= 0; temp--) {
					if (MAP[temp][col] != 0 && MAP[temp][col] != MAP[row][col]) break;
					if (MAP[temp][col] == MAP[row][col]) {
						MAP[row][col] *= 2;
						MAP[temp][col] = 0;
						break;
					}
				}

			}
		}
	}

	int counter;
	for (col = 0; col < 4; col++) {
		counter = 3;
		for (row = 3; row >= 0; row--) {
			if (MAP[row][col] != 0) {
				MAP[counter][col] = MAP[row][col];
				if (counter != row) MAP[row][col] = 0;
				counter--;
			}
		}
	}
	return 1;
}

int MoveRight() {
	int row, col;

	for (row = 0; row < 4; row++) {
		for (col = 3; col > 0; col--) {
			if (MAP[row][col] == 0) continue;
			else {
				for (int temp = col - 1; temp >= 0; temp--) {
					if (MAP[row][temp] != 0 && MAP[row][temp] != MAP[row][col]) break;
					if (MAP[row][temp] == MAP[row][col]) {
						MAP[row][col] *= 2;
						MAP[row][temp] = 0;
						break;
					}
				}

			}
		}
	}

	int counter;
	for (row = 0; row < 4; row++) {
		counter = 3;
		for (col = 3; col >= 0; col--) {
			if (MAP[row][col] != 0) {
				MAP[row][counter] = MAP[row][col];
				if (counter != col) MAP[row][col] = 0;
				counter--;
			}
		}
	}
	return 1;
}