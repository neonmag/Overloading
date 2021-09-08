#include "Bankomat.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Bankomat::Bankomat() // There are all of overloaded methods
{
	srand(time(0));
	if (this->sumInBankomat == 0)
	{
		this->sumInBankomat = rand() % 10000;
	}
	this->minSum = 100;
	this->maxSum = 10000;
	this->clientSum = 0;
	this->identificator = nullptr;
	this->clientSumString = nullptr;
}

Bankomat::Bankomat(int clientSum)
{
	srand(time(0));
	this->sumInBankomat = rand() % 10000;
	this->minSum = 100;
	this->maxSum = 10000;
	this->clientSum = clientSum;
	this->clientSumString = nullptr;
	this->identificator = new char[9];
	for (size_t i = 0; i < 9; i++)
	{
		this->identificator[i] = 50 + rand() % 40;
	}
	this->identificator[8] = '\0';
}

Bankomat::~Bankomat()
{
	delete[]this->identificator;
	this->identificator = nullptr;
	delete[]this->clientSumString;
	this->clientSumString = nullptr;
}

void Bankomat::InputMoney()
{
	int money;
	cout << "Sum in bankomat: " << this->sumInBankomat << endl;
	cout << "Enter some money in the bankomat(All money can not be more than 9999 and less than 100): ";
	cin >> money;
	cout << endl;
	while (this->sumInBankomat + money > 9999 || this->sumInBankomat + money < 100)
	{
		cout << "Enter some money in the bankomat(All money can not be more than 9999 and less than 100): ";
		cin >> money;
		cout << endl;
	}
	this->sumInBankomat += money;
}

void Bankomat::Input()
{
	this->identificator = new char[9];
	for (size_t i = 0; i < 8; i++)
	{
		this->identificator[i] = 50 + rand() % 41;
	}
	this->identificator[8] = '\0';
	cout << "Enter your sum: ";
	cin >> this->clientSum;
}

void Bankomat::Print()
{
	cout << "Sum in a bankomat: " << this->sumInBankomat << "$" << endl;
	cout << "Min sum: " << this->minSum << "$" << endl;
	cout << "Max sum: " << this->maxSum << "$" << endl;
	cout << "Identificator: " << this->identificator << endl;
	cout << "Wanted sum to through: " << this->clientSum << "$" << endl;
}

bool Bankomat::Check()
{
	if (this->clientSum < this->minSum || this->clientSum > this->maxSum)
	{
		return false;
	}
	else if (this->clientSum % 10 == 1)
	{
		return false;
	}
	else if (this->clientSum % 10 == 0 && this->clientSum > this->sumInBankomat)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Bankomat::Through()
{
	for (int i = 6; i >= 0; i--)
	{
		if (this->clientSum - this->nominallo[i] >= 0)
		{
			cout << "Bankomat give you " << this->nominallo[i] << "$" << endl;
			this->clientSum -= this->nominallo[i];
			this->sumInBankomat -= this->nominallo[i];
			i++;
		}
	}
}

void Bankomat::ToString()
{
	this->clientSumString = new char[20];
	_itoa_s(this->sumInBankomat, this->clientSumString, 19, 10); // Using method from <cstdlib>,where we make char from int(реализация в 10-чной системе исчисления)
	this->clientSumString[19] = '\0';
	cout << "Money in bankomat in string: " << this->clientSumString << endl;
}

void Bankomat::SetSumInBankomat(int sumInBankomat)
{
	this->sumInBankomat = sumInBankomat;
}

int Bankomat::GetSumInBankomat()
{
	return 0;
}

void Bankomat::SetMinSum(int minSum)
{
	this->minSum = minSum;
}

int Bankomat::GetMinSum()
{
	return 0;
}

void Bankomat::SetMaxSum(int maxSum)
{
	this->maxSum = maxSum;
}

int Bankomat::GetMaxSum()
{
	return 0;
}

void Bankomat::SetClientSum(int clientSum)
{
	this->clientSum = clientSum;
}

int Bankomat::GetClientSum()
{
	return 0;
}

void Bankomat::SetIdentificator(const char* identificator)
{
	if (this->identificator != nullptr)
	{
		delete[]this->identificator;
	}
	this->identificator = new char[strlen(identificator) + 1];
	strcpy_s(this->identificator, strlen(identificator) + 1, identificator);
}

const char *Bankomat::SetIdentificator()
{
	return this->identificator;
}

void Bankomat::SetClientSumString(const char* clientSumString)
{
	if (this->clientSumString != nullptr)
	{
		delete[]this->clientSumString;
	}
	this->clientSumString = new char[strlen(clientSumString) + 1];
	strcpy_s(this->clientSumString, strlen(clientSumString) + 1, clientSumString);
}

const char* Bankomat::SetClientSumString()
{
	return this->clientSumString;
}
