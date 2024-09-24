#include<iostream>
#include<iomanip>
//#include<stdio.h>
//#include<conio.h>
//#include<dos.h>
//#include<unistd.h>

#include<Windows.h>

using namespace std;

class Clock
{
	int hour, minute, second;

public:
	Clock(int Hour, int Minitue, int Second) : hour(Hour), minute(Minitue), second(Second) {}

	bool operator< (const Clock& other) const
	{
		if (hour != other.hour)
			return hour < other.hour;

		if (minute != other.minute)
			return minute < other.minute;

		else
			return second < other.second;
	}

	bool operator==(const Clock& other) const
	{
		return hour == other.hour && minute == other.minute && second == other.second;
		
	}
	
	Clock& operator++()
	{
		second++;
		if (second >= 60)
		{
			second = 0;
			minute++;
			if (minute >= 60)
			{
				minute = 0;
				hour++;
				if (hour >= 24)
					hour = 0;
			}	
		}
		return *this;
	}

	friend ostream& operator<< (ostream& COUT, const Clock& clock)
	{
		COUT << setfill('0') << setw(2) << clock.hour << ":"
			<< setfill('0') << setw(2) << clock.minute << ":"
			<< setfill('0') << setw(2) << clock.second;
		return COUT;

	}
};

int main()
{
	//cout << "something BEFORE sleeping for 1000 milliseconds.\n";
	//Sleep(3000); //sleeps for 3000 ms (milliseconds)
	//synchronous
	//cout << "something AFTER sleeping for 1000 milliseconds.\n";

	Clock midnight(0, 0, 0);
	Clock threePM(15, 0, 0);
	Clock myAlarmTime(06, 30, 0);

	cout << "Initial value: " << endl;
	cout << "Midnight: " << midnight << endl;
	cout << "Three PM: " << threePM << endl;
	cout << "My Alarm Time: " << myAlarmTime << endl;

	cout << "\nComparisons: " << endl;
	cout << boolalpha;
	cout << "Is Midnight equal to Three PM? ... " << (midnight == threePM) <<  endl;
	cout << "Is my Alarm Time less than Three PM? ... " << (myAlarmTime < threePM) << endl;

	cout << "\nIncrementing my Alarm Time... " << endl;
	++myAlarmTime;
	cout << "Updated my Alarm Time: " << myAlarmTime << endl;

	cout << "\nRunning clock update loop: " << endl;
	for (int i = 0; i < 100; i++)
	{
		cout << "Current Time: "  << myAlarmTime << endl;
		
		Sleep(1000);
		//system("cls");
		++myAlarmTime;
	}
}	