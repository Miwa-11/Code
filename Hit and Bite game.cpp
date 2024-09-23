//Hit and Bite Game


#include<iostream>

using namespace std;

bool setNumbers(int a, int b, int c)
{
	if (0 <= a && a <= 9 && 0 <= b && b <= 9 && 0 <= c && c <= 9 && a != b && b != c && a != c)
	{
		return true;
	}
	else
		return false;
}

void CheckHitBite(int a, int b, int c, int d, int e, int f)
{

	int hit = 0, bite = 0;
	if (a == d)
	{
		hit += 1; //hit = hit + 1;
	}
	if (b == e)
	{
		hit += 1;
	}
	if (c == f)
	{
		hit += 1;
	}
	if (a != d && (a == e || a == f))
	{
		bite += 1;
	}
	if (b != e && (b == d || b == f))
	{
		bite += 1;
	}
	if (c != f && (c == e || c == d))
	{
		bite += 1;
	}
	cout << hit << " hit(s)  " << bite << " bite(s)" << endl;
}

int main()
{
	int x1, x2, x3, y1, y2, y3, z1, z2, z3, w1, w2, w3;
	string player1, player2;

	cout << "Enter player 1's name" << endl;
	cin >> player1;
	cout << "\nEnter player 2's name" << endl;
	cin >> player2;

	cout << "\n" << player1 << ":\nEnter your three numbers. (Put the space between the each number) Each numbers shoud be 0-9 and don't put the same number.\n";

	while (true)
	{
		cin >> x1 >> x2 >> x3;
		if (setNumbers(x1, x2, x3) == true)
			break;
		else
			cout << "Put the numbers again." << endl;
	}

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << player2 << ":\nEnter your three numbers. (Put the space between the each number) Each numbers shoud be 0-9 and don't put the same number.\n";

	while (true)
	{
		cin >> y1 >> y2 >> y3;
		if (setNumbers(y1, y2, y3) == true)
			break;
		else
			cout << "Put the numbers again." << endl;
	}

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

	while (true)
	{
		cout << player1 << ": Guess the three numbers. (Put the space between the each numbers.)" << endl;
		cin >> z1 >> z2 >> z3;

		CheckHitBite(y1, y2, y3, z1, z2, z3);


		cout << player2 << ": Guess the three numbers. (Put the space between the each numbers.)" << endl;
		cin >> w1 >> w2 >> w3;

		CheckHitBite(x1, x2, x3, w1, w2, w3);

		cout << endl;

		if (y1 == z1 && y2 == z2 && y3 == z3 && x1 == w1 && x2 == w2 && x3 == w3)
		{
			cout << "Draw" << endl;
			break;
		}
		else if (y1 == z1 && y2 == z2 && y3 == z3)
		{
			cout << player1 <<" wins!" << endl;
			break;
		}
		else if (x1 == w1 && x2 == w2 && x3 == w3)
		{
			cout << player2 << " wins!" << endl;
			break;
		}
	}
	return 0;
}
