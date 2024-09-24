#include<iostream>

using namespace std;

class Computer
{
	string cpuName;
	double teraFLOPS;

public:
	Computer(string cpu_name, double Tflops) : cpuName(cpu_name), teraFLOPS(Tflops) {};

	void printComputerContents()
	{
		cout << "CPU name: " << cpuName << endl;
		cout << "TeraFLOPS: " << teraFLOPS << endl;
	}
};

class PersonalComputer : public Computer
{
	string monitorName;
	
public:
	PersonalComputer(string cpu_name, double Tflops, string monitor_name) : Computer(cpu_name, Tflops), monitorName(monitor_name) {};

	void printPersonalComputerContents()
	{
		cout << "Personal Computer Details: " << endl;
		printComputerContents();
		cout << "Monitor Name: " << monitorName << endl;
	}

};

class SmartPhone : public Computer
{
	int batteryLife;

public:
	SmartPhone(string cpu_name, double Tflops, int battery_life) : Computer(cpu_name, Tflops), batteryLife(battery_life) {};

	void printSmartPhoneContents()
	{
		cout << "Smartphone Details: " << endl;
		printComputerContents();
		cout << "The battery life: " << batteryLife << "%" << endl;
	}

};

class GameConsole : public Computer
{
	int ControllerCount;

public:
	GameConsole(string cpu_name, double Tflops, int controllerCount) : Computer(cpu_name, Tflops), ControllerCount(controllerCount) {};

	void printGameConsoleContents()
	{
		cout << "Game console Detail: " << endl;
		printComputerContents();
		cout << "Controller count: " << ControllerCount << endl;
	}

};




int main()
{
	Computer client1("Intel Core i7-10700K", 35.58);
	client1.printComputerContents();

	cout << endl;

	PersonalComputer client2("AMD Ryzen 9 5900X", 23.04, "Dell UltraSharp U2719D");
	client2.printPersonalComputerContents();

	cout << endl;

	SmartPhone client3("Apple M1", 2.6, 85);
	client3.printSmartPhoneContents();

	cout << endl;

	GameConsole client4("Custom AMD Zen 2 CPU", 1.6, 4);
	client4.printGameConsoleContents();

	return 0;
}