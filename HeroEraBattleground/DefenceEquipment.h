/* *************************
* FileName: DefencekEquipment.h
* Author: Jed Zhang
* Site: https://www.jed123.com/hero-era-battleground-cpp.html
* Date: 2018.5.23
* Description: Declaration of DefenceEquipment class. This is a derived class of Equipment.
**************************/
#ifndef _DEFEQUIP_H_
#define _DEFEQUIP_H_
#include "Equipment.h"
using namespace std;

class DefenceEquipment :virtual public Equipment {
private:
	int _phyDef;
	int _magDef;
public:
	/* Constructors and destructor */
	DefenceEquipment();	// Default
	DefenceEquipment(string name, int price, int phyDef, int magDef);	// Normal
	DefenceEquipment(DefenceEquipment& defequip);	// Copy
	virtual ~DefenceEquipment();	// Virtual destructor

	// Get functions
	int get_phyDef() const;
	int get_magDef() const;
};

#endif