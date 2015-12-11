#include "Weapon.h"

Weapon::Weapon(const string& kName, const int& initDura, const int& weapDmg) : Item(kName, initDura), kAttackDmg(weapDmg)
{
}

const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}

void Weapon::receiveDamage(const int& itemDamage)
{
	durability_ -= itemDamage / 2; //weapon takes half equipment damage
}

Weapon::~Weapon()
{

}
