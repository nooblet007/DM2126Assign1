#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
using std::string;

class GameObject
{
private:
	const string kName;
	static int count_;
protected:
	GameObject(const string& kName);
public:
	virtual ~GameObject();
	string getName(void);
	static int getCount();
};

#endif