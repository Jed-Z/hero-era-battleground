/* *************************
* FileName: AttackEquipment.cpp
* Author: Jed Zhang
* Site: https://www.jed123.com
* Date: 2018.5.23
* Description: Implementation of AttackEquipment class.
**************************/
#include "AttackEquipment.h"

/* Constructors and destructor */
AttackEquipment::AttackEquipment() :Equipment(), _phyAtk(0), _magAtk(0) {}
AttackEquipment::AttackEquipment(string name, int price, int phyAtk, int magAtk)
	:Equipment(name, price), _phyAtk(phyAtk), _magAtk(magAtk) {}
AttackEquipment::AttackEquipment(AttackEquipment& atkequip)
	: Equipment(atkequip), _phyAtk(atkequip.get_phyAtk()), _magAtk(atkequip.get_magAtk()) {}
AttackEquipment::~AttackEquipment() {}

/* Get functions */
int AttackEquipment::get_phyAtk() const { return _phyAtk; }
int AttackEquipment::get_magAtk() const { return _magAtk; }
