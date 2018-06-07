/* *************************
 * FileName: main.cpp
 * Author: Jed Zhang
 * Site: https://www.jed123.com/hero-era-battleground-cpp.html
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
void game_test();
double myrand();
void trim(string &s);

string enemyNameArr[] = { "Hydra", "Donald Trump", "Thanos", "Megatron", "Whiplash" };

// The main function only contains some settings and a infinite loop. The game
// starts in another function called "game_main".
int main(int argc, char* argv[])
{
	/* Environment settings */
	{
		system("mode con cols=120 lines=30");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	// Run the program with argument "t" to run testing mode.
	if (argc > 1 && (argv[1][1]=='t')) {
		MessageBox(GetForegroundWindow(), "You are now in the testing mode!!!!", "Warning - Hero Era Battleground", 0);
		game_test();
	}
	// Normal gaming mode.
	else {
		/* UI. Infinite loop */
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
				// Note that the program will exit inside print_bye function.
				print_bye();
				break;
			}
			// Press SPACE to start game.
			else if (ch == ' ') {
				// This is the "real" main function. Battleground generates there and game starts there.
				game_main();
				continue;
			}
			// If user press any other button, then do nothing.
			else {
				continue;
			}
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

// Hero testing. This is not part of this game. This function
// is used to test the classes, member functions.
void game_test() {
	// Hero myhero(name, money, health, phyAtk, magAtk, phyDef, magDef)
	Hero myhero("My Hero", 99999, 100, 10, 10, 10, 10);
	Hero enemy("Enemy");
	cout << myhero << endl << enemy << endl;
	system("pause");

	// Test 1: Attack test.
	myhero.attack(enemy);
	cout << enemy << endl;
	system("pause");

	// Test 2: Recover test.
	enemy.attack(myhero);
	enemy.attack(myhero);
	enemy.attack(myhero);
	cout << myhero << endl;
	system("pause");

	myhero.recover();
	cout << myhero << endl;
	system("pause");

	// This are two demo equipment.
	AttackEquipment* knife = new AttackEquipment("Knife", 400, 20, 0);
	DefenceEquipment* shield = new DefenceEquipment("Shield", 800, 40, 10);
	// Test 3: Buy a equipment in two ways (function and operator overloading).
	myhero.buy_equipment(knife);
	cout << myhero << endl;
	system("pause");

	myhero.attack(enemy);
	cout << enemy << endl;
	system("pause");

	myhero += shield;
	cout << myhero << endl;
	system("pause");

	// Test 4: Synthesize two equipments.
	myhero.syn_equipment(0, 1);
	cout << myhero << endl;
	system("pause");

	// Test 5: Sell equipment.
	myhero.sell_equipment(0);
	cout << myhero << endl;
	system("pause");

	cout << "Test is over." << endl;
	system("pause");
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