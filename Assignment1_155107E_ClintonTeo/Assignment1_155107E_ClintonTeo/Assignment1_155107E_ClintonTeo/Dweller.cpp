#include "Dweller.h"

Dweller::Dweller(const string& kName, const int& SPECIAL) : GameObject(kName), SPECIAL_(SPECIAL)
{
	setPosition(Vec2D(0, 0));
	Dweller*SPECIAL_ (0);
	radiation_ = 0;
	health_ = 100 - radiation_;
	stimpak_ = 0;
	radaway_ = 0;
	outfit_ = NULL;
	weapon_ = NULL;
}

const int Dweller::getSPECIAL()
{
	if (SPECIAL_ > 9999999)// checks if special is invalid
	{
		SPECIAL_ = 9999999;
	}
	if (SPECIAL_ < 0)
	{
		SPECIAL_ = 0;
	}
	if (outfit_ && outfit_->getDurability() > 0)// checks whether outfit is equipped and whether it is broken
	{
		int tempSPECIAL = 0;
		int outfitSPECIAL = outfit_->getSPECIAL();
		for (int i = 7; i > 0; i--) // adds each digit of the special values
		{
			int tempSPECIAL2 = 0;
			int power = pow(10.f, static_cast<float> (i)) / 10;
			tempSPECIAL2 = (SPECIAL_ / power) + (outfitSPECIAL/ power);
			SPECIAL_= SPECIAL_ % power;
			outfitSPECIAL = outfitSPECIAL % power;
			if (tempSPECIAL2 > 9)
			{
				tempSPECIAL2 = 9;
			}
			if (tempSPECIAL2 < 0)
			{
				tempSPECIAL2 = 0;
			}
			tempSPECIAL += (tempSPECIAL2 * power);
		}
		return tempSPECIAL;
	}
	else
	{
		return SPECIAL_;
	}
}

const int Dweller::getCurrentHealth()
{
	return health_;
}

const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}

const int Dweller::getAttackDmg()
{
	if (weapon_ && weapon_->getDurability() > 0)// checks if weapon is equipped and whether weapon is broken
	{
		return weapon_->getAttackDmg();
	}
	else
	{
		return 1;
	}
}

void Dweller::setPosition(const Vec2D& position_)
{
	this->position_ = Vec2D(position_.x, position_.y);
}

const Vec2D Dweller::getPosition()
{
	return position_;
}

void Dweller::receiveHealthDamage(const int& healthdmg)
{
	health_ -= healthdmg;
}

void Dweller::receiveRadDamage(const int& raddmg)
{
	radiation_ += raddmg;
}

void Dweller::receiveEquipmentDamage(const int& equipdmg)
{

	if (weapon_ && weapon_->getDurability() > 0)// checks if weapon is equipped and whether weapon is broken
	{
		weapon_->receiveDamage(equipdmg);
	}
	if (outfit_ && outfit_->getDurability() > 0)// checks if outfit is equipped and whether outfit is broken
	{
		outfit_->receiveDamage(equipdmg);
	}

}

void Dweller::addStimpak(const int& stimpaksAdd)
{
	stimpak_+= stimpaksAdd;
}

void Dweller::addRadAway(const int& radawayAdd)
{
	radaway_+= radawayAdd;
}

void Dweller::useStimpak()
{
	if (health_ < 100 - radiation_ && stimpak_ != 0)//check if player is at max health after radiation and if player has a stimpak
	{
		stimpak_--;
		health_ += 20;
		if (health_ > 100 - radiation_)// check if player is more than max possible health after radiation after healing
		{
			health_ = 100 - radiation_;
		}
	}
}

void Dweller::useRadAway()
{
	if (radiation_ > 0 && radaway_ != 0)//check if player is at min radiation and has a radaway
	{
		radaway_--;
		radiation_ -= 10;
		if (radiation_ < 0)// check if player has less than min possible radiation after using radaway
		{
			radiation_ = 0;
		}
	}
}

Outfit* Dweller::assignOutfit(Outfit * outfit)
{
	if (outfit)
	{
		this->outfit_ = outfit;// equip outfit
		return outfit_;
	}
	else
	{
		return NULL;
	}
}

Weapon* Dweller::assignWeapon(Weapon * weapon)
{
	if (weapon)
	{
		this->weapon_ = weapon;// equip weapon
		return weapon_;
	}
	else
	{
		return NULL;
	}
}

bool Dweller::isDead()
{
	if (health_ <= 0)// check if dweller is dead
	{
		return true;
	}
	else
	{
		return false;
	}
}

Dweller::~Dweller()
{

}