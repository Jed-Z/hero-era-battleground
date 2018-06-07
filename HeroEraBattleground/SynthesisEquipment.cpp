#include "SynthesisEquipment.h"
/* *************************
* FileName: SynthesisEquipment.cpp
* Author: Jed Zhang
* Site: https://www.jed123.com/hero-era-battleground-cpp.html
* Date: 2018.5.23
* Description: Implementation of SynthesisEquipment class.
**************************/

/* Constructors */
SynthesisEquipment::SynthesisEquipment() :AttackEquipment(), DefenceEquipment() {}
// Copy constructor
SynthesisEquipment::SynthesisEquipment(SynthesisEquipment& synequip)
	:AttackEquipment(synequip), DefenceEquipment(synequip) {
	set_name(synequip.get_name());
	set_price(synequip.get_price());
}

// Synthesize an Attack Equipment and a Defence Equipment.
SynthesisEquipment::SynthesisEquipment(AttackEquipment& atkequip, DefenceEquipment& defequip)
	: AttackEquipment(atkequip), DefenceEquipment(defequip) {
	set_name(atkequip.get_name() + "-plus-" + defequip.get_name());	// Rename the Synthesis Equipment
	set_price((atkequip.get_price() + defequip.get_price()));	// Give it a new price.
}
// Synthesize an Defence Equipment and a Attack Equipment.
SynthesisEquipment::SynthesisEquipment(DefenceEquipment& defequip, AttackEquipment& atkequip)
	: AttackEquipment(atkequip), DefenceEquipment(defequip) {
	set_name(atkequip.get_name() + "-plus-" + defequip.get_name());	// Rename the Synthesis Equipment
	set_price(1.2*(atkequip.get_price() + defequip.get_price()));	// Give it a new price.
}
