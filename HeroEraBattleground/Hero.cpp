/* *************************
* FileName: Hero.cpp
* Author: Jed Zhang
* Site: https://www.jed123.com
* Date: 2018.6.2
* Description: Implementation of  Hero class.
**************************/
#include "Hero.h"
#include "macro.h"
#include <iomanip>
#include <cstdlib>
#include <Windows.h>

extern double myrand();	// This function ss defined in main.cpp.

/* Constructors and destructor */
Hero::Hero() :_name("My Hero"), _money(0), _health(0), _phyAtk(0), _magAtk(0), _phyDef(0), _magDef(0) {}
Hero::Hero(string name, int money, int health, int phyAtk, int magAtk, int phyDef, int magDef)
	:_name(name), _money(money), _health(health), _phyAtk(phyAtk), _magAtk(magAtk),
	 _phyDef(phyDef), _magDef(magDef) {
	// Function body is empty.
}
Hero::~Hero() {
	// Delete the pointers in _equipvec one by one.
	while (_equipvec.size()) {
		Equipment* temp = _equipvec.back();
		//delete temp;
		_equipvec.pop_back();
	}
}

/* Reset function */
void Hero::reset(string name, int money, bool reset_equip, Equipment* equip) {
	// If reset_equip is true, then delete every existing
	//equipments and buy a new one according to equip.
	if (reset_equip) {
		while (_equipvec.size()) {
			Equipment* temp = _equipvec.back();
			_equipvec.pop_back();
		}
		_money = 9999999;
		// If equip is not nullptr, then buy it. Otherwise ignore.
		if (equip) {
			buy_equipment(equip);
		}
	}
	_name = name;	// Reset name.
	_health = 100;	// Reset health.
	_money = money;	// Reset money.
}

/* Get functions */
string Hero::get_name() const { return _name; }
int Hero::get_health() const { return _health; }
int Hero::get_phyAtk() const { return _phyAtk; }
int Hero::get_magAtk() const { return _magAtk; }
int Hero::get_phyDef() const { return _phyDef; }
int Hero::get_magDef() const { return _magDef; }
int Hero::get_equipcnt() const { return _equipvec.size(); }
int Hero::get_money() const { return _money; }
Equipment* Hero::get_equipment(int num) const {
	// Valid.
	if (num >= 0 && num < _equipvec.size()) {
		return  _equipvec[num];
	}
	// Invalid, return nullptr.
	else {
		return nullptr;
	}
}
int Hero::get_real_phyAtk() const {
	// Initialize result with the hero's basic phyAtk
	int result = get_phyAtk();
	// Iterate all equipments, if it is a Attack Equipment (use downcasting
	// to judge), then we count its phyAtk value. Otherwise we ignore it.
	for (auto it = _equipvec.begin(); it != _equipvec.end(); it++) {
		AttackEquipment* atkequipPtr = dynamic_cast<AttackEquipment*>(*it);
		if (atkequipPtr) { result += atkequipPtr->get_phyAtk(); }
	}
	return result;
}
int Hero::get_real_magAtk() const {
	// Initialize result with the hero's basic magAtk
	int result = get_magAtk();
	// Iterate all equipments, if it is a Attack Equipment (use downcasting
	// to judge), then we count its magAtk value. Otherwise we ignore it.
	for (auto it = _equipvec.begin(); it != _equipvec.end(); it++) {
		AttackEquipment* atkequipPtr = dynamic_cast<AttackEquipment*>(*it);
		if (atkequipPtr) { result += atkequipPtr->get_magAtk(); }
	}
	return result;
}
int Hero::get_real_phyDef() const {
	// Initialize result with the hero's basic phyDef
	int result = get_phyAtk();
	// Iterate all equipments, if it is a Defence Equipment (downcasting),
	// then we count its phyDef value. Otherwise we ignore it.
	for (auto it = _equipvec.begin(); it != _equipvec.end(); it++) {
		DefenceEquipment* defequipPtr = dynamic_cast<DefenceEquipment*>(*it);
		if (defequipPtr) { result += defequipPtr->get_phyDef(); }
	}
	return result;
}
int Hero::get_real_magDef() const {
	// Initialize result with the hero's basic magDef
	int result = get_magAtk();
	// Iterate all equipments, if it is a Defence Equipment (downcasting),
	// then we count its magDef value. Otherwise we ignore it.
	for (auto it = _equipvec.begin(); it != _equipvec.end(); it++) {
		DefenceEquipment* defequipPtr = dynamic_cast<DefenceEquipment*>(*it);
		if (defequipPtr) { result += defequipPtr->get_magDef(); }
	}
	return result;
}
double Hero::get_crit_chance() const {
	return (get_money() >= C_CRIT_MONEY) ? 1.0 : static_cast<double>(get_money()) / C_CRIT_MONEY;
}
bool Hero::isalive() const { return get_health() > 0; }

/* Print functions */
void Hero::printinfo() const {
	cout << *this;
}
ostream& operator<<(ostream &os, const Hero &hero)
{
	SET_WHITE;
	/* THE 1ST LINE BEGIN */
	os << "©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©Ð©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´ " << endl;	/* THE 1ST LINE END*/
	/* THE 2ND LINE BEGIN */
	os << "©¦  ";
	SET_CYAN;
	os << left << setw(16) << hero.get_name();
	SET_WHITE;
	os << "[HP] ";
	if (hero.get_health() >= 50) { SET_GREEN; }
	else if (hero.get_health() >= 20) { SET_YELLOW; }
	else { SET_RED; }
	os << setw(3) << hero.get_health();
	SET_WHITE;
	os << "    [Crit Chance] " << right << setw(3) << static_cast<int>(100*hero.get_crit_chance());
	os << "% ©¦       Equipments       ©¦ " << endl;	/* THE 2ND LINE END */
	/* THE 3RD LINE BEGIN */
	os << "©¦  [MONEY] $" << left << setw(7) << hero.get_money()
	   << "[Equipment] ";
	if (hero.get_equipcnt()) {
		os << hero.get_equipcnt();
	}
	else {
		os << "-";
	}
	os << "                  ©À©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©È " << endl;	/* THE 3RD LINE END */
	/* THE 4TH LINE BEGIN */
	os << "©¦  [Attack Damage] " << setw(4) << hero.get_real_phyAtk() << " = " << setw(3) <<hero.get_phyAtk();
	for (int i = 0; i < hero.get_equipcnt(); i++) {
		AttackEquipment* atkequipPtr = dynamic_cast<AttackEquipment*>(hero.get_equipment(i));
		if (atkequipPtr) {
			os << " + " << setw(3) << atkequipPtr->get_phyAtk();
		}
		else {
			os << " + " << setw(3) << 0;
		}
	}
	// This loop is used to fill spaces so that the frame could be printed correctly
	for (int j = 0; j < 3 - hero.get_equipcnt(); j++) {
		os << "      ";
	}
	os << "   ©¦";
	if (hero.get_equipcnt() >= 1) {
		os << "  0. " << setw(19) << (hero.get_equipment(0))->get_name() << "©¦ ";
	}
	else {
		os << "                        ©¦ ";
	}
	os << endl;	/* THE 4TH LINE END */
	/* THE 5TH LINE BEGIN */
	os << "©¦  [Ability Power] " << setw(4) << hero.get_real_magAtk() << " = " << setw(3) << hero.get_magAtk();
	for (int i = 0; i < hero.get_equipcnt(); i++) {
		AttackEquipment* atkequipPtr = dynamic_cast<AttackEquipment*>(hero.get_equipment(i));
		if (atkequipPtr) {
			os << " + " << setw(3) << atkequipPtr->get_magAtk();
		}
		else {
			os << " + " << setw(3) << 0;
		}
	}
	// This loop is used to fill spaces so that the frame could be printed correctly
	for (int j = 0; j < 3 - hero.get_equipcnt(); j++) {
		os << "      ";
	}
	os << "   ©¦";
	if (hero.get_equipcnt() >= 2) {
		os << "  1. " << setw(19) << (hero.get_equipment(1))->get_name() << "©¦ ";
	}
	else {
		os << "                        ©¦ ";
	}
	os << endl;	/* THE 5TH LINE END */
	/* THE 6TH LINE BEGIN */
	os << "©¦  [Armor]         " << setw(4) << hero.get_real_phyDef() << " = " << setw(3) << hero.get_phyDef();
	for (int i = 0; i < hero.get_equipcnt(); i++) {
		DefenceEquipment* defequipPtr = dynamic_cast<DefenceEquipment*>(hero.get_equipment(i));
		if (defequipPtr) {
			os << " + " << setw(3) << defequipPtr->get_phyDef();
		}
		else {
			os << " + " << setw(3) << 0;
		}
	}
	// This loop is used to fill spaces so that the frame could be printed correctly
	for (int j = 0; j < 3 - hero.get_equipcnt(); j++) {
		os << "      ";
	}
	os << "   ©¦";
	if (hero.get_equipcnt() >= 3) {
		os << "  2. " << setw(19) << (hero.get_equipment(2))->get_name() << "©¦ ";
	}
	else {
		os << "                        ©¦ ";
	}
	os << endl;	/* THE 6TH LINE END */
	/* THE 7TH LINE BEGIN */
	os << "©¦  [Magic Defence] " << setw(4) << hero.get_real_magDef() << " = " << setw(3) << hero.get_magDef();
	for (int i = 0; i < hero.get_equipcnt(); i++) {
		DefenceEquipment* defequipPtr = dynamic_cast<DefenceEquipment*>(hero.get_equipment(i));
		if (defequipPtr) {
			os << " + " << setw(3) << defequipPtr->get_magDef();
		}
		else {
			os << " + " << setw(3) << 0;
		}
	}
	// This loop is used to fill spaces so that the frame could be printed correctly
	for (int j = 0; j < 3 - hero.get_equipcnt(); j++) {
		os << "      ";
	}
	os << "   ©¦                        ©¦ " << endl;	/* THE 7TH LINE END */
	/* THE 8TH LINE BEGIN */
	os << "©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©Ø©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼ ";
	/* THE 8TH LINE WILL BE ENDED BY USER */
	return os;
}

/* Buy equipment */
bool Hero::buy_equipment(Equipment* equip) {
	if (get_money() < equip->get_price()) {
		// Error: Not enough money!
		SET_CYAN;
		cerr << get_name();
		SET_WHITE;
		cerr << " has only ";
		SET_RED;
		cerr << "$" << get_money();
		SET_WHITE;
		cerr << ". Not enough to buy a ";
		SET_RED;
		cerr << "$" << equip->get_price();
		SET_CYAN;
		cerr << " " << equip->get_name();
		SET_WHITE;
		cerr << "!" << endl;
		return false;
	}
	else if (get_equipcnt() >= 3) {
		// Error: Maximum amount (3) of equipment
		SET_CYAN;
		cerr << get_name();
		SET_WHITE;
		cerr << " already has ";
		SET_RED;
		cerr << "3";
		SET_WHITE;
		cerr << " equipments! No more!" << endl;
		return false;
	}
	else {
		// Buy a equipment successfully
		_equipvec.push_back(equip);
		_money -= equip->get_price();
		SET_CYAN;
		cout << get_name();
		SET_WHITE;
		cout << " bought a ";
		SET_CYAN;
		cout << equip->get_name();
		SET_WHITE;
		cout << ", spent ";
		SET_YELLOW;
		cout << "$" << equip->get_price();
		SET_WHITE;
		cout << "." << endl;
		return true;
	}
}
Hero& Hero::operator+=(Equipment* equip) {
	this->buy_equipment(equip);
	return *this;
}

/* Remove equipment (private) */
// Remove by index number (private)
bool Hero::remove_equipment(int num) {
	if (num >= 0 && num < get_equipcnt()) {
		_equipvec.erase(_equipvec.begin() + num);	// num begins from zero
	}
	else {
		// Invalid num
		cerr << "REMOVE ERROR!" << endl;
		return false;
	}
}
// Remove by pointer (private)
bool Hero::remove_equipment(Equipment* equip) {
	for (auto it = _equipvec.begin(); it != _equipvec.end();) {
		if (*it == equip) {
			_equipvec.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
	// Not found.
	cerr << "REMOVE ERROR!" << endl;
	return false;
}

/* Sell equipment */
bool Hero::sell_equipment(int num) {
	if (num >= 0 && num < get_equipcnt()) {
		SET_CYAN;
		cout << get_name();
		SET_WHITE;
		cout << " has sold a ";
		SET_CYAN;
		cout << get_equipment(num)->get_name();
		SET_WHITE;
		cout << ", earned ";
		SET_YELLOW;
		cout << "$" << C_SELL * get_equipment(num)->get_price();
		SET_WHITE;
		cout << "!" << endl;
		// Sell a equipment and earn C_IMMUNE% its price
		_money += C_SELL * (get_equipment(num)->get_price());
		remove_equipment(num);
		return true;
	}
	else {
		// Invalid num
		cerr << "Something wrong. Check again." << endl;
		return false;
	}
}
Hero& Hero::operator-=(int num) {
	this->sell_equipment(num);
	return *this;
}

/* Synthesis equipments*/
bool Hero::syn_equipment(int x, int y) {
	// Input may be valid. Try downcasting.
	if (x >= 0 && y >= 0 && x < get_equipcnt() && y < get_equipcnt() && x != y) {
		// Neither of x nor y can be a synthesis equipment. Ohterwise return false.
		if (dynamic_cast<SynthesisEquipment*>(get_equipment(x)) || dynamic_cast<SynthesisEquipment*>(get_equipment(y))) {
			cerr << "A Synthesis Equipment cannot be synthesized again!" << endl;
			return false;
		}
		AttackEquipment* atkequipPtr = dynamic_cast<AttackEquipment*>(get_equipment(x));
		DefenceEquipment* defequipPtr = dynamic_cast<DefenceEquipment*>(get_equipment(y));

		// If the previous downcasting failed, try again by exchanging x and y.
		if ((atkequipPtr == nullptr) && (defequipPtr == nullptr)) {
			atkequipPtr = dynamic_cast<AttackEquipment*>(get_equipment(y));
			defequipPtr = dynamic_cast<DefenceEquipment*>(get_equipment(x));
		}

		// Downcasting successfully.
		// Check if money is enough for synthesizing. Note that you
		// need 15% extra to synthesize. Read the document for more details.
		if (atkequipPtr && defequipPtr) {

			int money_needed = 0.15 * (get_equipment(x)->get_price() + get_equipment(y)->get_price());
			// Enough money. Make a SynthesisEquipment now.
			if (get_money() >= money_needed) {
				SynthesisEquipment* result = new SynthesisEquipment(*atkequipPtr, *defequipPtr);
				// Print success message.
				SET_CYAN;
				cout << get_name();
				SET_WHITE;
				cout << " has synthesized a ";
				SET_CYAN;
				cout << atkequipPtr->get_name();
				SET_WHITE;
				cout << " with a ";
				SET_CYAN;
				cout << defequipPtr->get_name();
				SET_WHITE;
				cout << " into a ";
				SET_CYAN;
				cout << result->get_name();
				SET_WHITE;
				cout << ". Spent ";
				SET_YELLOW;
				cout << "$" << money_needed;
				SET_WHITE;
				cout << "." << endl;

				// All tests succeed, begin synthesize.
				_money -= money_needed;
				remove_equipment(atkequipPtr);
				remove_equipment(defequipPtr);
				_equipvec.push_back(result);
			}
			// Error: You are so poor. No enough money to synthesize.
			else {
				SET_CYAN;
				cerr << get_name();
				SET_WHITE;
				cerr << " has only ";
				SET_RED;
				cerr << "$" << get_money();
				SET_WHITE;
				cerr << ". You need at least ";
				SET_RED;
				cerr << "$" << money_needed;
				SET_WHITE;
				cerr << " to synthesize a ";
				SET_CYAN;
				cerr << atkequipPtr->get_name();
				SET_WHITE;
				cerr << " with a ";
				SET_CYAN;
				cerr << defequipPtr->get_name();
				SET_WHITE;
				cerr << "!" << endl;
				return false;
			}
		}

		// Error: Synthesizing two equipments of the same type is not allowed!
		else {
			cerr << "No synthesizing two equipments of the same type!" << endl;
			return false;
		}
	}
	// Error: Invalid input. x or y out of range, or x is the same as y.
	else {
		cerr << "You are synthesize nothing! Check again!" << endl;
		return false;
	}
}

/* Battle functions */
int Hero::attack(Hero& that) {
	int damage_given;
	// Crit instead of normal attack, and print "CRIT!!!"
	if (myrand() < get_crit_chance()) {
		damage_given = crit(that);
		_money += (C_RECEIVE * damage_given) * 0.8;
		cout << "CRIT!! ";
		SET_CYAN;
		cout << get_name();
		SET_WHITE;
		cout << " ATTACK " << that.get_name() << " and cause " << damage_given << " damage!!!" << endl;
	}
	// Normal attack
	else {
		damage_given = normal_attack(that);
		_money += C_RECEIVE * damage_given;
		SET_CYAN;
		cout << get_name();
		SET_WHITE;
		cout << " ATTACK " << that.get_name() << " and cause " << damage_given << " damage!!!" << endl;
	}
	return damage_given;
}
bool Hero::recover() {
	// Enough money.
	if (get_money() >= 200) {
		_money -= 200;
		_health += 15;
		// If HP extends 100, set it 100.
		if (get_health() > 100) { _health = 100; }
		SET_CYAN;
		cout << get_name();
		SET_WHITE;
		cout << " tries to recover and got 15HP using $200!" << endl;
		return true;
	}
	// Error: No enough money.
	else {
		SET_CYAN;
		cerr << get_name();
		SET_WHITE;
		cerr << " has only ";
		SET_RED;
		cerr << "$" << get_money();
		SET_WHITE;
		cerr << ". Not enough to recover. Chance wasted!" << endl;
		return false;
	}
}

/* Battle functions (private) */
int Hero::crit(Hero& that) {
	int phyAtk = get_real_phyAtk(), magAtk = get_real_magAtk();
	int phyDef = that.get_real_phyDef(), magDef = that.get_real_magDef();
	int phyDamage = (1 - static_cast<double>(phyDef) / (phyDef + C_IMMUNE)) * phyAtk;
	int magDamage = (1 - static_cast<double>(magDef) / (magDef + C_IMMUNE)) * magAtk;
	int damage_given = that.damage_taken( C_CRIT * (phyDamage + magDamage) / 2);
	return damage_given;
}
int Hero::normal_attack(Hero& that) {
	int phyAtk = get_real_phyAtk(), magAtk = get_real_magAtk();
	int phyDef = that.get_real_phyDef(), magDef = that.get_real_magDef();
	int phyDamage = (1 - static_cast<double>(phyDef) / (phyDef + C_IMMUNE)) * phyAtk;
	int magDamage = (1 - static_cast<double>(magDef) / (magDef + C_IMMUNE)) * magAtk;
	int damage_given = that.damage_taken((phyDamage + magDamage) / 2);
	return damage_given;
}
int Hero::damage_taken(int n) {
	int temp = get_health();
	// The hero is still alive after being damaged.
	if (temp > n) {
		_health -= n;
	}
	// The hero is dead after being damaged.
	else {
		_health = 0;
	}
	return temp - get_health();
}