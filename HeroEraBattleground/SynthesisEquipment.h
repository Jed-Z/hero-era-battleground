/* *************************
* FileName: SynthesisEquipment.h
* Author: Jed Zhang
* Site: https://www.jed123.com/hero-era-battleground-cpp.html
* Date: 2018.5.23
* Description: Declaration of SynthesisEquipment class.
*              This is a derived class of both AttackEquipment and DefenceEquipment.
**************************/
#ifndef _SYNEQUIP_H_
#define _SYNEQUIP_H_
#include "AttackEquipment.h"
#include "DefenceEquipment.h"
using namespace std;

class SynthesisEquipment :public AttackEquipment, public DefenceEquipment {
public:
	/* Constructors */
	SynthesisEquipment();	// Default
	SynthesisEquipment(SynthesisEquipment& synequip);	// Copy
	// Synthesize an Attack Equipment and a Defence Equipment
	SynthesisEquipment(AttackEquipment& atkequip, DefenceEquipment& defequip);
	// Synthesize an Defence Equipment and a Attack Equipment
	SynthesisEquipment(DefenceEquipment& defequip, AttackEquipment& atkequip);
};

#endif