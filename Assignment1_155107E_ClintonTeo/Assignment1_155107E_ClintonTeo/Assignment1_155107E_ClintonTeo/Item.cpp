#include "Item.h"
#include "Outfit.h"
#include "Dweller.h"
#include "Weapon.h"

Item::Item(const string& kName, const int& initDura) : GameObject(kName), durability_(initDura)
{

}

void Item::receiveDamage(const int& itemDamage)
{
	
}

const int Item::getDurability()
{
	return durability_;
}

Item::~Item()
{

}