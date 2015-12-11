#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon : public Item
{
private:
	const int kAttackDmg;
public:
	Weapon(const string& kName, const int& initDura, const int& weapDmg);
	virtual ~Weapon();
	const int getAttackDmg();
	virtual void receiveDamage(const int& itemDamage);
};


#endif