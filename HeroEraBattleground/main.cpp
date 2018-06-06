/* *************************
 * FileName: main.cpp
 * Author: Jed Zhang
 * Site: https://www.jed123.com
 * Date: 2018.6.2
 * Description: Program entrance. And game_main function.
**************************/
#include "Hero.h"
#include "ui.h"
#include "Battleground.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

void game_main();
double myrand();
void trim(string &s);

string enemyNameArr[] = { "Hydra", "Donald Trump", "Thanos", "Megatron", "Whiplash" };

// The main function only contains some settings and a infinite loop. The game
// starts in another function called "game_main".
int main()
{
	/* Environment settings */
	{
		system("mode con cols=120 lines=30");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	/* UI infinite loop */
	while (true) {
		print_introduction();
		char ch = _getch();
		// Press H for help.
		if (ch == 'h' || ch == 'H') {
			print_help();
			_getch();
			continue;
		}
		// Press ESC to exit. Note that 27 is the ASCII of ESC.
		else if (ch == 27) {
			print_bye();
			break;
		}
		// Press SPACE to start game.
		else if (ch == ' ') {
			// This is the "real" main function. Battleground generates here.
			// Note that game_main() can only be called once, then break the while loop.
			game_main();
			continue;
		}
		// If user press other button, then do nothing.
		else {
			continue;
		}
	}
	return 0;
}

// Battleground will be generated here.
void game_main() {
	string username;
	cout << "What is your name, my hero?" << endl;
	getline(cin, username);
	trim(username);
	while (username.length() > 14 || username.length() == 0) {
		cout << "Name illeagle. Your name can have 1~14 letters." << endl;
		cout << "What is your name, my hero?" << endl;
		getline(cin, username);
		trim(username);
	}

	Battleground bg(username, enemyNameArr[static_cast<int>(5 * myrand())]);
	/****** Battleground generated. Battle starts now *****/
	bg.game_loop();

}

/* My random number generator */
double myrand() {
	// Because of the bad behaviour that "rand()" does,
	// I have to write my own random number generator.
	// This function generate a double number in [0,1).
	return static_cast<double>(clock() % 1000) / 1000.0;
}

/* String trim function */
void trim(string &s)
{
	if (!s.empty())
	{
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
}