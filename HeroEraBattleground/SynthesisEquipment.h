/* *************************
* FileName: SynthesisEquipment.h
* Author: Jed Zhang
* Site: https://www.jed123.com
* Date: 2018.5.23
* Description:
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
	SynthesisEquipment(AttackEquipment& atkequip, DefenceEquipment& defequip);	// Normal
	SynthesisEquipment(DefenceEquipment& defequip, AttackEquipment& atkequip);	// Normal
};
#endif