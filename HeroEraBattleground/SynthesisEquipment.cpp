#include "SynthesisEquipment.h"
/* *************************
* FileName: SynthesisEquipment.cpp
* Author: Jed Zhang
* Site: https://www.jed123.com
* Date: 2018.5.23
* Description:
**************************/

SynthesisEquipment::SynthesisEquipment() :AttackEquipment(), DefenceEquipment() {}
SynthesisEquipment::SynthesisEquipment(SynthesisEquipment& synequip)
	:AttackEquipment(synequip), DefenceEquipment(synequip) {
	set_name(synequip.get_name());
	set_price(synequip.get_price());
}

SynthesisEquipment::SynthesisEquipment(AttackEquipment& atkequip, DefenceEquipment& defequip)
	: AttackEquipment(atkequip), DefenceEquipment(defequip) {
	set_name(atkequip.get_name() + "-plus-" + defequip.get_name());
	set_price((atkequip.get_price() + defequip.get_price()));
}
SynthesisEquipment::SynthesisEquipment(DefenceEquipment& defequip, AttackEquipment& atkequip)
	: AttackEquipment(atkequip), DefenceEquipment(defequip) {
	set_name(atkequip.get_name() + "-plus-" + defequip.get_name());
	set_price(1.2*(atkequip.get_price() + defequip.get_price()));
}