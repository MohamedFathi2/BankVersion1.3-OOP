#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;


class clsFindClientScreen : protected clsScreen
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

public:

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return; // This will exit the function and it will not show the screen.
		}
		_DrawScreenHeader("\t Find Client Screen");
		string AccountNumber = "";

		cout << "Please Enter the Account Number of the Client you want to find: ";
		AccountNumber = clsInputValidate::ReadString();
	
		while (!(clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "\nAccount Number is not found, please enter a valid Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient is found :-) .\n";
		}
		else
		{
			cout << "\nClient is not found :-( .\n";
		}
		_PrintClient(Client);
	}
};