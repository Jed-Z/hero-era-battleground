/* *************************
* FileName: Hero.h
* Author: Jed Zhang
* Site: https://www.jed123.com
* Date: 2018.5.23
* Description: Declaration of Hero class.
**************************/
#ifndef _HERO_H_
#define _HERO_H_
#include <iostream>
#include <string>
#include <vector>
#include "SynthesisEquipment.h"
using namespace std;

class Hero {
private:
	string _name;	// The name of a hero.
	int _health;	// The health point of a hero (HP).
	int _phyAtk;	// Physical attack damage. [Attack Damage]
	int _magAtk;	// Magical attack damage. [Ability Power]
	int _phyDef;	// Physical defence. [Armor]
	int _magDef;	// Magical defence. [Magic Defence]
	int _money;		// The amount of money a hero owns.
	vector<Equipment*> _equipvec;	// Contains pointers to equipments.

	/* Remove equipment (private) */
	bool remove_equipment(int num);	// Remove by index number
	bool remove_equipment(Equipment* equip);	// Remove by pointer

	/* Battle functions (private) */
	int crit(Hero& that);
	int normal_attack(Hero& that);
	int damage_taken(int n);

public:
	/* Constructors and destructor */
	Hero();	// Default
	// Normal
	Hero(string name, int money = 800, int health = 100, int phyAtk = 10, int magAtk = 10, int phyDef = 10, int magDef = 10);
	~Hero();

	/* Reset function */
	void reset(string name, int money = 800, bool reset_equip = true, Equipment* equipn = nullptr);

	/* Get functions */
	string get_name() const;
	int get_health() const;
	int get_phyAtk() const;
	int get_magAtk() const;
	int get_phyDef() const;
	int get_magDef() const;
	int get_equipcnt() const;
	int get_money() const;
	Equipment* get_equipment(int num) const;
	int get_real_phyAtk() const;
	int get_real_magAtk() const;
	int get_real_phyDef() const;
	int get_real_magDef() const;
	double get_crit_chance() const;

	/* Judge whether the hero is dead. */
	bool isalive() const;

	/* Print function */
	void printinfo() const;
	friend ostream& operator<<(ostream &os, const Hero &data);

	/* Buy equipment */
	bool buy_equipment(Equipment* equip);
	Hero& operator+=(Equipment* equip);

	/* Sell equipment */
	bool sell_equipment(int num);	// Sell a equipment and earn 60% its price
	Hero& operator-=(int num);

	/* Synthesis equipments */
	// Only if one is AttackEquipment and the other is 
	//DefenceEquipment can you synthesis two equipments.
	bool syn_equipment(int x, int y);

	/* Battle functions */
	int attack(Hero& that);
	bool recover();
};

#endif