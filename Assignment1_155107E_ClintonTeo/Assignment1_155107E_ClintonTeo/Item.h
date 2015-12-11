#ifndef ITEM_H
#define ITEM_H
#include "GameObject.h"

class Item : public GameObject
{
protected:
	int durability_;
public:
	Item(const string& kName, const int& initDura);
	virtual ~Item();
	virtual void receiveDamage(const int& itemDamage) = 0;
	const int getDurability();
};


#endif