/* *************************
* FileName: DefenceEquipment.cpp
* Author: Jed Zhang
* Site: https://www.jed123.com/hero-era-battleground-cpp.html
* Date: 2018.6.7
* Description: Implementation of Battlegroune class.
**************************/
#include "macro.h"
#include "Battleground.h"
#include "ui.h"
#include <iomanip>
#include <conio.h>
#include <Windows.h>
using namespace std;

extern double myrand();	// This function is defined in main.cpp.
extern string enemyNameArr[];	// This variable is in main.cpp. Contains several enemys' names.

/* Constructors */
Battleground::Battleground(string playerName, string enemyName)
	:_player(playerName), _enemy(enemyName), _game(0), _round(0), _score(0) {
	/* Set console window to 120x30 */
	system("mode con cols=120 lines=30");

	/* Prepare equipments inventory */
	AttackEquipment* knife = new AttackEquipment("Knife", 400, 20, 0);
	AttackEquipment* sword = new AttackEquipment("Sword", 650, 40, 25);
	AttackEquipment* poison = new AttackEquipment("Poison", 1000, 30, 50);
	AttackEquipment* ak47 = new AttackEquipment("AK47", 1400, 90, 10);
	DefenceEquipment* vest = new DefenceEquipment("Vest", 500, 30, 20);
	DefenceEquipment* shield = new DefenceEquipment("Shield", 800, 40, 10);
	DefenceEquipment* immunity = new DefenceEquipment("Immunity", 1200, 50, 50);
	DefenceEquipment* magnetic_field = new DefenceEquipment("Magnetic Field", 1500, 80, 20);
	_inventory.push_back(knife);
	_inventory.push_back(sword);
	_inventory.push_back(poison);
	_inventory.push_back(ak47);
	_inventory.push_back(vest);
	_inventory.push_back(shield);
	_inventory.push_back(immunity);
	_inventory.push_back(magnetic_field);
}

/* Get functions */
int Battleground::get_game() const { return _game; }
int Battleground::get_round() const { return _round; }
int Battleground::get_score() const { return _score; }
Equipment* Battleground::get_inventory(int num) const {
	if (num >= 0 && num < _inventory.size()) {
		return _inventory[num];
	}
	else {
		// If the given num is invalid, return nullptr.
		return nullptr;
	}
}

/* Print functionts*/
void Battleground::print_inventory() const {
	cout << "©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´ " << endl;
	cout << "©¦         ***  INVENTORY  ***         ©¦ " << endl;
	cout << "©À©¤©¤©¤©¤©Ð©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©Ð©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©È " << endl;
	cout << "©¦" << " No " << "©¦" << " Equipment          " << "©¦" << " Price     " << "©¦ " << endl;
	int i = 0;
	for (auto it = _inventory.begin(); it != _inventory.end(); it++, i++) {
		cout << "©¦ " << left << setw(3) << i;
		cout << "©¦ " << setw(19) << (*it)->get_name() << "©¦ ";
		if ((*it)->get_price() <= _player.get_money()) { SET_GREEN; }
		else { SET_RED; }
		cout << "$" << setw(4) << (*it)->get_price();
		SET_WHITE;
		cout << "     ©¦ " << endl;
	}
	cout << "©¸©¤©¤©¤©¤©Ø©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©Ø©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼ " << endl;
	cout << endl;
}
void Battleground::print_final()
{
	system("cls");
	SET_CYAN;
	cout << _player.get_name() << "\n" << endl;
	SET_WHITE;
	cout << "You have played " << get_game() << " games.\n" << endl;
	cout << "Your final score: ";
	SET_GREEN;
	cout << get_score();
	SET_WHITE;
	cout << "\nPress [ ANY KEY ] to go back to main menu.\n" << endl;
}


/* Core loop functions */
// Attention! The relationship between "game" and "round" is explained in the document.
bool Battleground::round_loop() {
	while (true)
	{
		_round++;	// A new round begins. Note that _round was initialized to 0.
		system("cls");	// Clear screen.
		cout << string(43, ' ') << "¡ï¡ï¡ï Game " << get_game() << " * Round " << get_round() << " ¡ï¡ï¡ï";
		cout << string(30, ' ') << "Score: " << get_score() << endl;

		cout << _player << endl << _enemy << endl;
		int damage;	// Temp variable.
		bool is_ok;	// Temp variable.

		/* Player's turn BEGIN */
		while (true) {
			cout << "Round " << get_round() << ": ";
			cout << "It's your turn. [ A ] Attack, [ R ] Recover, [ B ] Buy, [ S ] Sell. [ Y ] Synthesize.\n" << endl;
			char action = _getch();
			// [A] for attack.
			if (action == 'a' || action == 'A') {
				damage = _player.attack(_enemy);
				_score += damage;
				break;
			}
			// [R] for recover.
			else if (action == 'r' || action == 'R') {
				is_ok = _player.recover();
				break;
			}
			else if (action == 'b' || action == 'B') {
				print_inventory();
				cout << "You have ";
				SET_GREEN;
				cout << "$" << _player.get_money();
				SET_WHITE;
				cout << ". Enter the number of the equipment you want to buy and hit [ ENTER ]." << endl;
				int buy;
				// Input, and check if the input it correct.
				while (!(cin >> buy) || buy < 0 || buy >= _inventory.size()) {
					cin.clear();
					while (cin.get() != '\n');	// Discard every wrong input characters.
					SET_RED;
					cout << "Illeagle input!" ;
					SET_WHITE;
					cout << "You have ";
					SET_GREEN;
					cout << "$" << _player.get_money();
					SET_WHITE;
					cout << ". Enter the number of the equipment you want to buy and hit [ ENTER ]." << endl;
				}
				cout << endl;
				if (_player.buy_equipment(get_inventory(buy))) { break; }
				else { continue; }
			}
			// [Y] for synthesizing.
			else if (action == 'y' || action == 'Y') {
				if (_player.get_equipcnt() >= 2) {
					cout << "Which two equipments do you want to synthesize? Enter two numbers, separated by a space." << endl;
					int syn1, syn2;
					cin >> syn1 >> syn2;
					_player.syn_equipment(syn1, syn2);
					break;
				}
				else {
					SET_RED;
					cout << "Failed! ";
					SET_WHITE;
					cout << "You need at least 2 equipments to synthesize!" << endl;
					continue;
				}
			}
			// ESC for exit
			else if (action == 's' || action == 'S') {
				if (_player.get_equipcnt()) {
					cout << "What do you want to sell? Enter a number of your equipment." << endl;
					int sell;
					cin >> sell;
					_player.sell_equipment(sell);
					break;
				}
				else {
					SET_RED;
					cout << "Failed! ";
					SET_WHITE;
					cout << "You don't have any equipment to sell!" << endl;
					continue;
				}
			}
			// Unknown input, try again.
			else {
				continue;
			}
		}
		_score += 100;
		/* Player's turn END */
		Sleep(500);

		/* If the enemy is dead */
		if (!_enemy.isalive()) {
			SET_GREEN;
			cout << "\nYou win!" << endl;
			SET_WHITE;
			return true;
		}

		/* Enemy's turn BEGIN */
		while (true) {
			// Opponent HP < 30
			if (_player.get_health() < 30) {
				damage = _enemy.attack(_player);
				break;
			}
			// HP>50, attack
			else if (_enemy.get_health() > 40) {
				damage = _enemy.attack(_player);
				break;
			}
			else {
				if (myrand() < 0.7 && _enemy.get_money()>=200) {
					_enemy.recover();
				}
				else {
					_enemy.attack(_player);
				}
				break;
			}
		}	/* Enemy's turn END */
		Sleep(500);

		/* If the player is dead */
		if (!_player.isalive()) {
			system("color 4F");
			for (int i = 0; i < 5; i++) {
				Sleep(75);
				system("color F");
				Sleep(75);
				system("color 4F");
			}
			Sleep(800);
			system("color");
			SET_YELLOW;
			cout << "\nYou die!" << endl;
			SET_WHITE;
			return false;
		}
		cout << "\nPress [ ANY KEY ] to continue the next round..." << endl;
		_getch();
	}
}

void Battleground::game_loop() {
	bool status;
	while (true) {
		_round = 0;
		_game++;
		for (int i = 3; i >= 1; i--) {
			system("cls");
			cout << string(10, '\n') << "              Okay, ";
			SET_CYAN;
			cout << _player.get_name();
			SET_WHITE;
			cout << ", get ready.\n" << endl;
			cout << "              GAME " << get_game() << " will start in " << i << " seconds." << endl;
			Sleep(1000);
		}
		status = round_loop();
		if (status) {
			cout << "ANOTHER GAME? (Y/N)" << endl;
			char another = _getch();
			cout << another;
			// Player is still alive, but don't want to play another game.
			if (another=='n' || another=='N') { break; }
			// Player wants to play another game, reset two heroes.
			else {
				int premoney = _player.get_money();
				int newmoney;
				if (premoney < 300) { newmoney = 800; }
				else { newmoney = premoney + 500; }
				_player.reset(_player.get_name(), newmoney, false);
				_enemy.reset(enemyNameArr[static_cast<int>(5 * myrand())], 800 + 200*get_game(), true, get_inventory(get_game()%_inventory.size()));
				continue;
			}
		}
		else {
			// Player is dead.
			cout << "Press [ ANY KEY ] to see your score." << endl;
			_getch();
			system("color F");
			break;
		}
	}	/* END WHILE */
	/* Print final score and go back to main menu */
	_score += 200 * get_game();
	print_final();
	_getch();
}