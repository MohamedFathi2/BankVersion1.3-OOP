#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>



class clsWithdrawScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber()
	{
		cout << "\n\nPlease Enter Account Number? ";
		string AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}
public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t  Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!(clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "Client with [" << AccountNumber << "] does not exist.";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;
		cout << "\nPlease enter withdraw amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction? [Y/N]? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdrawed Successfully.\n";
				cout << "\nNew Balance is: " << Client.AccountBalance << "\n";
			}
			else
			{
				cout << "\nCannot withdraw, Insufficient Balance!\n\n";
				cout << "Amount to withdraw : " << Amount << "\n";
				cout << "Current Balance    : " << Client.AccountBalance << "\n";
			}
		}
		else
		{
			cout << "\nOpeartion is canceled.\n";
		}
	}

};