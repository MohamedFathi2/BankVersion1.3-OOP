#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include <iomanip>

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:

	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eShowMainMenue = 6
	};

	static short ReadManageUsersScreenOption()
	{
		cout << setw(37) << left << "" << "Choose what you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter a Number between 1 to 6? ");
		return Choice;
	}

	static void _ShowListUserScreen()
	{
		// cout << "\nList User Screen Will be here...\n";
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen()
	{
		// cout << "\nAdd New User Screen Will be here...\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		// cout << "\nDelete User Screen Will be here...\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		// cout << "\nUpdate User Screen Will be here...\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		// cout << "\nFind User Screen Will be here...\n";
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _ShowMainMenueScreen()
	{
		// do nothing here, The main screen will handle it.
	}
	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\n\tPress any key to go back to Transactions Menue . . . \n";
		system("pause>0");
		ShowManageUsersMenue();
	}
	static void _PerfromManageUsersScreen(enManageUsersMenueOptions ManageUsersMenueOption)
	{
		switch (ManageUsersMenueOption)
		{
		case enManageUsersMenueOptions::eListUsers:
			system("cls");
			_ShowListUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersMenueOptions::eShowMainMenue:
			// do nothing here, The main screen will handle it.
			break;
		}
	}

public:

	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return; // This will exit the function and it will not show the screen.
		}
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromManageUsersScreen((enManageUsersMenueOptions)ReadManageUsersScreenOption());
	}
};