/* *************************
* FileName: Equipment.h
* Author: Jed Zhang
* Site: https://www.jed123.com/hero-era-battleground-cpp.html
* Date: 2018.5.23
* Description: Declaration of Equipment class.
**************************/
#ifndef _EQUIPMENT_H_
#define _EQUIPMENT_H_
#include <string>
using namespace std;

class Equipment {
private:
	string _name;	// The name of a equipment.
	int _price;		// The price one need to pay for this equipment.
public:
	/* Constructors and destructor */
	Equipment();	// Default
	Equipment(string name, int price);	// Normal
	Equipment(Equipment &equip);	// Copy
	virtual ~Equipment();	// Virtual destructor

	/* Get functions */
	string get_name() const;
	int get_price() const;

	/* Set functions */
	void set_name(string name);
	void set_price(int price);
};

#endif