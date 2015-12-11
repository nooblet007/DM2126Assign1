#include "Dweller.h"
#include "Outfit.h"
#include "Weapon.h"
#include "Item.h"
#include "GameObject.h"
#include "Vec2D.h"

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

void testNames()
{
	Dweller *d = new Dweller("Pip-Boy", 2222222);
	Outfit *o = new Outfit("Minuteman", 10, 2200220);
	Weapon *w = new Weapon("Gauss", 16, 16);
	Vec2D currentPos(3.54, 6.32);

	// hold a list of game objects that was instantiated.
	vector<GameObject *> gameObjectList;
	gameObjectList.push_back(d);
	gameObjectList.push_back(o);
	gameObjectList.push_back(w);

	// test Dweller public functions
	cout << d->getSPECIAL() << endl;
	d->getCurrentHealth();
	d->getCurrentRadDamage();
	d->getAttackDmg();
	d->setPosition(currentPos);
	d->getPosition();
	d->receiveHealthDamage(13);
	d->receiveRadDamage(15);
	d->receiveEquipmentDamage(4);
	d->addStimpak(2);
	d->addRadAway(5);
	d->useStimpak();
	d->useRadAway();
	d->assignOutfit(o);
	d->assignWeapon(w);
	d->isDead();
	cout << d->getSPECIAL() << endl;

	// test Outfit public functions
	o->getSPECIAL();
	o->receiveDamage(1);

	// test Weapon public functions
	w->getAttackDmg();
	w->receiveDamage(3);

	// test Item inheritance
	Item *i = o;
	cout << i->getDurability() << endl;
	i->receiveDamage(1);

	i = w;
	cout << i->getDurability() << endl;
	i->receiveDamage(1);

	// test game object inheritance
	for (auto go : gameObjectList)
	{
		go->getName();
	}
	GameObject::getCount();

	// release the memory
	for (auto go : gameObjectList)
	{
		delete go;
	}
}

void shouldNotCompile()
{
	// comment out the #define line below to test out all the cases that should not compile
	// You can also comment out individual lines in case there are too many errors for you to check through
#define SHOULD_NOT_COMPILE
#ifndef SHOULD_NOT_COMPILE
	GameObject go;
	Item i;


#endif
}