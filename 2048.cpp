//Basem Walid
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "cppgraphics.hpp"
#include <Windows.h>
#include <tchar.h>
using namespace std;
using namespace cg;
const int arraysize = 4;
int check[4][4];
int board[4][4];
int b = 0;
void shiftrightstep(int[][arraysize]);
void shiftrightmerge(int[][arraysize]);
void shiftleftstep(int[][arraysize]);
void shiftleftmerge(int[][arraysize]);
void shiftupstep(int[][arraysize]);
void shiftupmerge(int[][arraysize]);
void shiftdownstep(int[][arraysize]);
void shiftdownmerge(int[][arraysize]);
void shiftright(int[][arraysize]);
void shiftleft(int[][arraysize]);
void shiftup(int[][arraysize]);
void shiftdown(int[][arraysize]);
bool checkhorizontal(int[][arraysize]);
bool checkvertical(int[][arraysize]);
int score = 0;
const int range = 50;
bool mawgood = false;
bool mo5tlf = true;
bool exist(string);
void starting(string);
void draw(int[][arraysize]);
void generateRandomTile(int[][arraysize]);
struct player {
	string nickname;
	int score;
	int highest_score;
};
void check_empty(string, player);
void menu();
void start_game();
string resume = "Press any key to resume";
void Tilestep(int[][arraysize]);
void StartGame();
void gameover();
int soccer;
int x;
int high;
int playtime = 0;
player info[range];
void win();
bool kesebt();


int main() {
	srand(time(0));
	start_game();
	return 0;
}





void shiftrightstep(int board[][arraysize])
{
	for (int i = 0;i < arraysize;i++) {
		for (int n = 0;n < arraysize;n++) {
			for (int m = 0;m < (arraysize - 1);m++)
			{

				if (board[n][m + 1] == 0)
				{
					board[n][m + 1] = board[n][m];
					board[n][m] = 0;


				}
			}
		}
	}
}
void shiftrightmerge(int board[][arraysize])
{
	for (int n = 0;n < arraysize;n++) {
		for (int m = (arraysize - 1);m > 0;m--) {
			if (board[n][m] == board[n][m - 1])
			{
				if (b != m - 1)
				{
					board[n][m] += board[n][m - 1];

					board[n][m - 1] = 0;
					b = m;
					score += board[n][m];

				}


			}

		}
		b = -1;
	}


}
void shiftright(int board[][arraysize])
{
	shiftrightstep(board);
	shiftrightmerge(board);
	shiftrightstep(board);
	Tilestep(board);
}

void shiftleftstep(int board[][arraysize])
{
	for (int i = 0;i < arraysize;i++) {
		for (int n = 0;n < arraysize;n++) {
			for (int m = (arraysize - 1);m > 0;m--)
			{

				if (board[n][m - 1] == 0)
				{
					board[n][m - 1] = board[n][m];
					board[n][m] = 0;


				}
			}
		}

	}
}
void shiftleftmerge(int board[][arraysize])
{
	for (int n = 0;n < arraysize;n++) {
		for (int m = 1;m < arraysize;m++) {
			if (board[n][m] == board[n][m - 1])
			{
				if (b != m)
				{
					board[n][m - 1] += board[n][m];

					board[n][m] = 0;
					b = m - 1;
					score += board[n][m - 1];
				}

			}

		}
		b = -1;
	}

}
void shiftleft(int board[][arraysize])
{
	shiftleftstep(board);
	shiftleftmerge(board);
	shiftleftstep(board);
	Tilestep(board);
}

void shiftupstep(int board[][arraysize])
{
	for (int i = 0; i < arraysize; i++)
	{
		for (int n = (arraysize - 1); n > 0; n--) {
			for (int m = 0; m < arraysize; m++)
			{

				if (board[n - 1][m] == 0)
				{
					board[n - 1][m] = board[n][m];
					board[n][m] = 0;
					
				}
			}
		}
	}
}
void shiftupmerge(int board[][arraysize])
{
	for (int n = 0;n < arraysize;n++) {
		for (int m = 0;m < arraysize - 1;m++) {
			if (board[m][n] == board[m + 1][n])
			{
				if (b != m)
				{
					board[m][n] += board[m + 1][n];

					board[m + 1][n] = 0;
					b = m + 1;
					score += board[m][n];

				}


			}

		}
		b = -1;
	}

}
void shiftup(int board[][arraysize])
{
	shiftupstep(board);
	shiftupmerge(board);
	shiftupstep(board);
	Tilestep(board);

}

void shiftdownstep(int board[][arraysize])
{
	for (int i = 0; i < arraysize; i++)
	{
		for (int n = 0; n < arraysize; n++)
		{
			for (int m = 0;m < (arraysize - 1); m++)
			{

				if (board[m + 1][n] == 0)
				{
					board[m + 1][n] = board[m][n];
					board[m][n] = 0;

				}
			}
		}
	}
}
void shiftdownmerge(int board[][arraysize])
{
	for (int n = 0; n < arraysize; n++)
	{
		for (int m = arraysize - 1; m > 0; m--)
		{
			if (board[m][n] == board[m - 1][n])
			{
				if (b != (m - 1))
				{
					board[m][n] += board[m - 1][n];

					board[m - 1][n] = 0;
					b = m;
					score += board[m][n];

				}


			}

		}
		b = -1;
	}

}
void shiftdown(int board[][arraysize])
{
	shiftdownstep(board);
	shiftdownmerge(board);
	shiftdownstep(board);
	Tilestep(board);
}




bool checkhorizontal(int board[][arraysize]) {

	for (int i = 0; i < arraysize; i++) {
		for (int j = 0; j < arraysize-1; j++) {
			if (board[i][j] == 0 || board[i][j + 1] == 0) {
				return false;
			}
			if (board[i][j] == board[i][j + 1]) {
				return false;
			}
		}
	}
	return true;
}

bool checkvertical(int board[][arraysize]) {

	for (int i = 0; i < arraysize-1; i++) {
		for (int j = 0; j < arraysize; j++) {
			if (board[i][j] == 0 || board[i + 1][j] == 0) {
				return false;
			}
			if (board[i][j] == board[i + 1][j]) {
				return false;
			}
		}
	}
	return true;
}


void generateRandomTile(int board[][arraysize]) {
	int numEmptyCells = 0;
	int emptyCells[arraysize * arraysize][2];

	for (int i = 0; i < arraysize; ++i) {
		for (int j = 0; j < arraysize; ++j) {
			if (board[i][j] == 0) {
				emptyCells[numEmptyCells][0] = i;
				emptyCells[numEmptyCells][1] = j;
				++numEmptyCells;
			}
		}
	}

	if (numEmptyCells > 0) {
		int index = rand() % numEmptyCells;
		int value = (rand() % 2 + 1) * 2;
		int row = emptyCells[index][0];
		int col = emptyCells[index][1];
		board[row][col] = value;
	}
}
void draw(int board[][arraysize]) {
	set_color(Black);
	set_fill_color(White);
	set_background_color(DarkBlue);
	clear();
	
	rectangle(100,20,150,100);
	text_centered("Score", 175, 50, 45);
	text_centered(std::to_string(score), 175, 90, 40);

	rectangle(500, 20, 200, 100);
	text_centered("Highest", 600, 50, 45);
	text_centered(std::to_string(info[x].highest_score), 600, 90, 40);
	for (int i = 0;i < arraysize;i++) {
		for (int j = 0;j < arraysize;j++) {
			rectangle(100 + i * 150, 150 + j * 150, 150, 150);
			if (board[j][i] != 0)
				text_centered(std::to_string(board[j][i]), 175 + i * 150, 225 + j * 150, 50);
		}
	}
}

void menu() {
	set_color(Black);
	set_fill_color(Black);
	set_background_color(White);
	clear();
	text_centered(resume, 400, 400, 50);

}
void win() {
	set_color(White);
	set_fill_color(White);
	set_background_color(Blue);
	clear();
	text_centered("You won!", 400, 400, 50);
}
void Tilestep(int board[][arraysize]) {
	
	int count=0;
	for (int i = 0;i < arraysize;i++) {
		for (int j = 0;j < arraysize;j++) {
			if (check[i][j] == board[i][j]) {
				count++;
			}
		}
	}
	if (count < 16) {
		generateRandomTile(board);
		bool play = PlaySound(_T("pop-39222.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}

	for (int i = 0;i < arraysize;i++) {
		for (int j = 0;j < arraysize;j++) {
			check[i][j] = board[i][j];
		}
	}

}



void StartGame() {

	for (int i = 0;i < 2;i++) {
		generateRandomTile(board);
	}
	create_window("2048", 800, 800);
	while (is_window_open) {
		draw(board);
		int key = wait_until_keypressed();
		if (key == KeyRight) {
			shiftright(board);
		}
		if (key == KeyLeft) {
			shiftleft(board);
		}
		if (key == KeyUp) {
			shiftup(board);
		}
		if (key == KeyDown) {
			shiftdown(board);
		}
		while (key == KeyEscape) {
			menu();
			key = wait_until_keypressed();
		}
		if (score > info[x].highest_score) {
			info[x].highest_score = score;
		}
		if (kesebt()) {
			info[x].score = score;
			win();
			bool play = PlaySound(_T("shalaby.wav"), NULL, SND_FILENAME | SND_ASYNC);
			score = 0;
			break;
		}
		if (checkhorizontal(board) && checkvertical(board)) {
			info[x].score = score;
			gameover();
			bool play = PlaySound(_T("tommoot.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;

		}


	}
	
	wait_until_closed();
	start_game();
}
void gameover() {
	set_color(White);
	set_fill_color(White);
	set_background_color(Black);
	clear();
	text_centered("Game over!", 400, 400, 50);
	for (int i = 0;i < arraysize;i++) {
		for (int j = 0;j < arraysize;j++) {
			board[i][j] = 0;
		}
	}
	score = 0;

}
void check_empty(string name, player info[]) {
	string name_to_replace;
	int counter = 0;
	for (int u = 0; u < range; u++)
	{
		if (info[u].nickname == "") {
			info[u].nickname = name;
			info[u].score = 0;
			info[u].highest_score = 0;
			x = u;
			break;
		}
		else {
			counter++;
		}
	}
	/*
	if (counter >= 5)
	{
		cout << "The list of players is full so choose a name to replace!" << endl;
		for (int h = 0; h < range; h++)
		{
			cout << info[h].nickname << endl;
		}
		cout << "Enter a name to replace : " << endl;
		cin >> name_to_replace;
		for (int r = 0; r < range; r++) {
			if (name_to_replace == info[r].nickname) {
				mot5lf = false;
			}
		}
		while (mot5lf == true) {
			cout << "MA E7NA ETNYLNA 2OLNA MN EL LIST : " << endl;
			for (int h = 0; h < range; h++)
			{
				cout << info[h].nickname << endl;
			}
			cout << "DA5AL ESM SA7 B2A : " << endl;
			cin >> name_to_replace;
			for (int r = 0; r < range; r++) {
				if (name_to_replace != info[r].nickname) {
					mot5lf = true;
				}
				else {
					mot5lf = false;
					break;
				}
			}
		}
		for (int v = 0; v < range; v++) {
			if (info[v].nickname == name_to_replace) {
				info[v].nickname = name;
				info[v].score = 0;
			}
		}
		cout << name << " is registered and the score is set to 0 " << endl;
		cout << "The list of players is now : " << endl;
		for (int z = 0; z < range; z++) {
			cout << info[z].nickname << endl;
		}
	}*/
}
bool exist(string name) {
	for (int i = 0; i < range; i++)
	{
		if (info[i].nickname == name) {
			mawgood = true;
			soccer = info[i].score;
			high = info[i].highest_score;
			x = i;
			break;
		}
	}
	return mawgood;
}
void starting(string option) {
	char first_name[50];
	char second_name[50];
	cout << "Enter your first & second name : " << endl;
	cin.getline(first_name, 50, ' ');
	cin.getline(second_name, 50, '\n');
	string user = strcat(strcat(first_name, " "), strcat(second_name,""));
	exist(user);
	if (mawgood == true) {
		cout << "ur score was " << soccer << endl;
		cout << "ur highest score is " << high << endl;
		mawgood = false;
		StartGame();
	}
	else {
		playtime++;
		cout << "U are a new player and your total and highest score is 0 until now!" << endl;
		check_empty(user, info);
		StartGame();
	}
}
void list(player info[]) {
	int swap_score;
	string swap_name;
	int swap_highest;
	for (int pass = 0; pass < range - 1; pass++) {

		for (int k = 0; k < range - 1; k++)
		{
			if (info[k].score < info[k + 1].score)
			{
				swap_score = info[k].score;
				info[k].score = info[k + 1].score;
				info[k + 1].score = swap_score;
				swap_name = info[k].nickname;
				info[k].nickname = info[k + 1].nickname;
				info[k + 1].nickname = swap_name;
				swap_highest = info[k].highest_score;
				info[k].highest_score = info[k + 1].highest_score;
				info[k + 1].highest_score = swap_highest;
			}
		}
	}
	if (playtime == 0) {
		cout << "No players " << endl;
	}
	else {
		for (int u = 0; u < playtime; u++)
		{
			cout << "Player " << u + 1 << " : " << info[u].nickname << " / Latest score is : " << info[u].score << " / highest score : " << info[u].highest_score << endl;
		}
	}
}

void start_game() {
	int i = 0;
	string button;
	cout << "Press s to start or l to show list or e to exit : " << endl;
	cin >> button;
	while (button != "e") {
		if (button != "s" && button != "l") {
			cout << "Invalid input,try again" << endl;
		}
		else {
			if (button == "s") {
				starting(button);
				cout << "Your score is now : " << endl;


				cout << info[x].score << endl;
				cout << "And highest score = " << info[x].highest_score << endl;
			}
			else if (button == "l") {
				list(info);
			}
		}
			cout << "Press s to start again or l to show list or e to exit : " << endl;
			cin >> button;
		}
	
	cout << "See u later ! " << endl;
	exit(1);
}
bool kesebt() {
	for (int i = 0;i < arraysize;i++) {
		for (int j = 0;j < arraysize;j++) {
			if (board[i][j]==32) {
				for (int i = 0;i < arraysize;i++) {
					for (int j = 0;j < arraysize;j++) {
						board[i][j] = 0;
					}
				}
				
				return true;
			}
		}
	}
	return false;
}
