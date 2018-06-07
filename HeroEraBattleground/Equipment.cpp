/* *************************
* FileName: Equipment.cpp
* Author: Jed Zhang
* Site: https://www.jed123.com/hero-era-battleground-cpp.html
* Date: 2018.5.23
* Description: Implementation of the Equipment class.
**************************/
#include "Equipment.h"

/* Constructors and destructor */
Equipment::Equipment() : _name(""), _price(0) {}
Equipment::Equipment(string name, int price) :_name(name), _price(price) {}
Equipment::Equipment(Equipment &equip) : _name(equip.get_name()), _price(equip.get_price()) {}
Equipment::~Equipment() {}

/* Get functions */
string Equipment::get_name() const { return _name; }
int Equipment::get_price() const { return _price; }

/* Set functions */
void Equipment::set_name(string name) { _name = name; }
void Equipment::set_price(int price) { _price = price; }
