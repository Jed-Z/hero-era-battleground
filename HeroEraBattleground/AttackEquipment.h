/* *************************
* FileName: AttackEquipment.h
* Author: Jed Zhang
* Site: https://www.jed123.com/hero-era-battleground-cpp.html
* Date: 2018.5.23
* Description: Declaration of the AttackEquipment class. This is a derived class of Equipment.
**************************/
#ifndef _ATKEQUIP_H_
#define _ATKEQUIP_H_
#include "Equipment.h"
using namespace std;

class AttackEquipment :virtual public Equipment {
private:
	int _phyAtk;	// Attack Damage of an AttackEquipment.
	int _magAtk;	// Ability Power of an AttackEquipment.
public:
	/* Constructors and destructor */
	AttackEquipment();	// Default
	AttackEquipment(string name, int price, int phyAtk, int magAtk);	// Normal
	AttackEquipment(AttackEquipment& atkequip);	// Copy
	virtual ~AttackEquipment();	// Virtual destructor

	/* Get functions */
	int get_phyAtk() const;
	int get_magAtk() const;
};

#endif