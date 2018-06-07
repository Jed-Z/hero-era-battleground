/* *************************
* FileName: DefenceEquipment.cpp
* Author: Jed Zhang
* Site: https://www.jed123.com/hero-era-battleground-cpp.html
* Date: 2018.6.7
* Description: Declaration of Battlegroune class.
**************************/
#ifndef _BATTLEGROUND_H_
#define _BATTLEGROUND_H_
#include "Hero.h"
#include <iostream>
using namespace std;

class Battleground {
private:
	Hero _player;
	Hero _enemy;
	int _game;
	int _round;
	int _score;
	vector<Equipment*> _inventory;
public:
	Battleground(string playerName, string enemyName);
	/* Constructors */

	/* Get functions */
	int get_game() const;
	int get_round() const;
	int get_score() const;
	Equipment* get_inventory(int num) const;
	/* Print functionts*/
	void print_inventory() const;
	void print_final();

	/* Core loop functions */
	bool round_loop();
	void game_loop();
};

#endif