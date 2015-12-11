#ifndef OUTFIT_H
#define OUTFIT_H
#include "Item.h"
#include <string>
using std::string;

class Outfit : public Item
{
private:
	const int kSPECIAL;
public:
	Outfit(const string& kName, const int& initDura, const int& outfitSPECIAL);
	virtual ~Outfit();
	const int getSPECIAL();
	virtual void receiveDamage(const int& itemDamage);
};


#endif