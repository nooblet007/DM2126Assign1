#include "GameObject.h"

int GameObject::count_ = 0;

GameObject::GameObject(const string& kName) : kName(kName)
{
	count_++;
}

string GameObject::getName(void)
{
	return kName;
}

int GameObject::getCount()
{
	return count_;
}

GameObject::~GameObject()
{
	count_--;
}