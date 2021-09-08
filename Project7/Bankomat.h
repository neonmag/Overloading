#pragma once
class Bankomat
{ // Initialisating lines
	int sumInBankomat = 0;
	int nominallo[7] = { 10,20,50,100,200,500,1000 };
	int minSum;
	int maxSum;
	char* identificator;
	int clientSum;
	char* clientSumString;
public: // Initialisating methods
	Bankomat(); // Constructor by default
	Bankomat(int clientSum); // Constructor
	~Bankomat(); // Destructor
	void InputMoney(); // Overloading methods
	void Input();
	void Print();
	bool Check();
	void Through();
	void ToString();
	void SetSumInBankomat(int sumInBankomat); // Realase overloading getters and setters
	int GetSumInBankomat();
	void SetMinSum(int minSum);
	int GetMinSum();
	void SetMaxSum(int maxSum);
	int GetMaxSum();
	void SetClientSum(int clientSum);
	int GetClientSum();
	void SetIdentificator(const char* identificator);
	const char* SetIdentificator();
	void SetClientSumString(const char* clientSumString);
	const char* SetClientSumString();
};

