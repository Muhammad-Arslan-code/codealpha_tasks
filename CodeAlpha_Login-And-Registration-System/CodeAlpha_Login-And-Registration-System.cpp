#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class user
{
private:
	string username;
	string password;
public:
	void register_user()
	{
		string check_username;
		cout << "Enter Username: ";
		cin >> username;

		ifstream read("users.txt");
		while (read >> check_username)
		{
			read >> password;
			if (check_username == username)
			{
				cout << "Username Already Exists..." << endl;
				read.close();
				return;
			}
		}
		read.close();
		cout << "Enter Password: ";
		cin >> password;

		ofstream write("users.txt", ios::app);
		write << username << " " << password << endl;
		write.close();
		cout << "Registration Successful..." << endl;
	}

	void login_user()
	{
		string login_username;
		string login_password;
		string stored_username;
		string stored_password;

		bool found = false;

		cout << "Enter Username: ";
		cin >> login_username;
		cout << "Enter Password: ";
		cin >> login_password;

		ifstream read("users.txt");
		while (read >> stored_username >> stored_password)
		{
			if (stored_username == login_username &&
				stored_password == login_password)
			{
				found = true;
				break;
			}
		}
		read.close();
		if (found)
		{
			cout << "Login Successful..." << endl;
		}
		else
		{
			cout << "Invalid Username or Password..." << endl;
		}
	}
};

int main()
{
	user u;
	int choice;

	do
	{
		cout << "  LOGIN & REGISTRATION SYSTEM  " << endl;

		cout << "1. Register" << endl;
		cout << "2. Login" << endl;
		cout << "3. Exit" << endl;

		cout << "Enter Choice: ";
		cin >> choice;
		if (choice == 1)
		{
			u.register_user();
		}
		else if (choice == 2)
		{
			u.login_user();
		}
		else if (choice == 3)
		{
			cout << "Program Ended..." << endl;
		}
		else
		{
			cout << "Invalid Choice..." << endl;
		}

	} while (choice != 3);

	return 0;
}