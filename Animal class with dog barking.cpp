#include<iostream>
#include<Windows.h>
#include<mmsystem.h>
#include<string>

#pragma comment(lib, "Winmm.lib")
using namespace std; 

class Animal
{
	string name; //homo sapiens (canis familiaris)

};



class Tail
{
	int length;
	int width;
	bool isBushy;
public:
	void printTailObject();
	Tail(int length, int width, bool isBushy);
};

class Nose
{
	int length;
	int width;
	bool isDry;

public:
	void printNoseObject();
	Nose(int length, int width, bool isDry);
};

class Dog : public Animal
{
	string name; 
	
	Tail tailObject; 
	Nose noseObject;

public:
	void bark()
	{
		PlaySound(TEXT("small-dog-barking-102658.wav"), NULL, SND_FILENAME | SND_ASYNC);

		string input;
		getline(cin, input);
	}
	Dog(string name, int tailLength, int tailWidth, bool isBushy, int noseLength, int noseWidth, bool isDry);
	
};

Tail::Tail(int length, int width, bool isBushy)
{
	Tail::length = length;
	Tail::width = width;
	Tail::isBushy = isBushy;
}

void Tail::printTailObject()
{
	cout << "The tail length: " << length << " inches" << endl;
	cout << "The tail width: " << width << " inches" << endl;
	cout << "The tail is bushy?: " << isBushy << endl;
	cout << boolalpha;
}

Nose::Nose(int length, int width, bool isDry)
{
	Nose::length = length;
	Nose::width = width;
	Nose::isDry = isDry;
}

void Nose::printNoseObject()
{
	cout << "The nose length: " << length << " inches" << endl;
	cout << "The nose width: " << width << " inches" << endl;
	cout << "The nose is dry?: " << isDry << endl;
	cout << boolalpha;
}
Dog::Dog(string name, int tailLength, int tailWidth, bool isBushy, int noseLength, int noseWidth, bool isDry)
	: name(name), tailObject(tailLength, tailWidth, isBushy), noseObject(noseLength, noseWidth, isDry)
{
	Dog::name = name;
	cout << "The dog name: " << name << "\n\n\n";
	tailObject.printTailObject();
	cout << endl;
	noseObject.printNoseObject();
}


int main()
{

	Dog myDog{ "Lucy",4, 3, true, 1, 2, false };
	//in silico 
	myDog.bark();

	return 0;
}


 