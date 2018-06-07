/* *************************
* FileName: DefenceEquipment.cpp
* Author: Jed Zhang
* Site: https://www.jed123.com/hero-era-battleground-cpp.html
* Date: 2018.5.23
* Description: Implementation of DefenceEquipment class.
**************************/
#include "DefenceEquipment.h"

/* Constructors and destructor */
DefenceEquipment::DefenceEquipment() :Equipment(), _phyDef(0), _magDef(0) {}
DefenceEquipment::DefenceEquipment(string name, int price, int phyDef, int magDef)
	:Equipment(name, price), _phyDef(phyDef), _magDef(magDef) {}
DefenceEquipment::DefenceEquipment(DefenceEquipment& defequip)
	: Equipment(defequip), _phyDef(defequip.get_phyDef()), _magDef(defequip.get_magDef()) {}
DefenceEquipment::~DefenceEquipment() {}

/* Get functions */
int DefenceEquipment::get_phyDef() const { return _phyDef; }
int DefenceEquipment::get_magDef() const { return _magDef; }