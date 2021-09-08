#include <iostream>
#include "Bankomat.h" // Include my library

using namespace std;

bool Change() // Method for change side
{
	int check;
	cout << "Are you bank,or user?(1,or 2): ";
	cin >> check;
	cout << endl;
	while (check < 1 || check > 2)
	{
		cout << "Are you bank,or user?(1,or 2): ";
		cin >> check;
		cout << endl;
	}
	if (check == 1)
	{
		return true;
	}
	if (check == 2)
	{
		return false;
	}
}

int main()
{
	Bankomat obj1; // Initialisating class
	while (Change() == true)
	{
		obj1.InputMoney(); // Input money in bankomat
	}
	obj1.Input(); // Input user's money
	obj1.Print(); // Print information
	if (obj1.Check() == true) // Money checker
	{
		cout << "Bankomat will give you your money :0" << endl;
		obj1.Through();
	}
	else
	{
		cout << "Your sum is wrong,bye :)" << endl;
	}
	obj1.ToString(); // Formate in to string
}