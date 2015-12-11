#ifndef DWELLER_H
#define DWELLER_H
#include "GameObject.h"
#include "Vec2D.h"
#include "Weapon.h"
#include "Outfit.h"

class Dweller : public GameObject
{
private:
	Vec2D position_;
	int SPECIAL_;
	int health_;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit* outfit_;
	Weapon* weapon_;

public:
	Dweller(const string& kName, const int& SPECIAL_);
	virtual ~Dweller();

	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDmg();

	void setPosition(const Vec2D&);
	const Vec2D getPosition();

	void receiveHealthDamage(const int& healthdmg);
	void receiveRadDamage(const int& raddmg);
	void receiveEquipmentDamage(const int& equipdmg);

	void addStimpak(const int& stimpaksAdd);
	void addRadAway(const int& radawayAdd);

	void useStimpak();
	void useRadAway();

	Outfit* assignOutfit(Outfit*);
	Weapon* assignWeapon(Weapon*);

	bool isDead();
};

#endif