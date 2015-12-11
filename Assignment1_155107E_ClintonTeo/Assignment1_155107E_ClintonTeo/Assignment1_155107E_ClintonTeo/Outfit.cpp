#include "Outfit.h"

Outfit::Outfit(const string& kName, const int& initDura, const int& outfitSPECIAL) : Item(kName,initDura), kSPECIAL(outfitSPECIAL)
{
}


const int Outfit::getSPECIAL()
{
	return kSPECIAL;
}

void Outfit::receiveDamage(const int& itemDamage)
{
	durability_ -= itemDamage;
}

Outfit::~Outfit()
{

}