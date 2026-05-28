
#include <iostream>
#include <iomanip>
#include<string>
using namespace std;
class account
{
private:
	int account_number;
	string name;
	float balance;
public:
	void create_account()
	{
		cout << "Enter Account Number: ";
		cin >> account_number;
		cin.ignore();
		cout << "Enter Customer Name: ";
		getline(cin, name);
		cout << "Enter Initial Balance: ";
		cin >> balance;
		while (balance < 0)
		{
			cout << "Invalid Balance..." << endl;
			cout << "Enter Balance Again: ";
			cin >> balance;
		}
	}
	void deposit()
	{
		float amount;
		cout << "Enter Deposit Amount: ";
		cin >> amount;
		while (amount <= 0)
		{
			cout << "Invalid Amount..." << endl;
			cout << "Enter Amount Again: ";
			cin >> amount;
		}
		balance += amount;
		cout << "Deposit Successful..." << endl;
	}
	void withdraw()
	{
		float amount;
		cout << "Enter Withdraw Amount: ";
		cin >> amount;

		while (amount <= 0)
		{
			cout << "Invalid Amount..." << endl;
			cout << "Enter Amount Again: ";
			cin >> amount;
		}
		if (amount > balance)
		{
			cout << "Insufficient Balance..." << endl;
		}
		else
		{
			balance -= amount;

			cout << "Withdrawal Successful..." << endl;
		}
	}
	void transfer(account& receiver)
	{
		float amount;
		cout << "Enter Transfer Amount: ";
		cin >> amount;
		while (amount <= 0)
		{
			cout << "Invalid Amount..." << endl;
			cout << "Enter Amount Again: ";
			cin >> amount;
		}
		if (amount > balance)
		{
			cout << "Insufficient Balance..." << endl;
		}
		else
		{
			balance -= amount;
			receiver.balance += amount;
			cout << "Transfer Successful..." << endl;
		}
	}
	int get_account_number()
	{
		return account_number;
	}
	void display_account()
	{
		cout << "    ACCOUNT DETAILS   " << endl;
		cout << "Account Number: " << account_number << endl;
		cout << "Customer Name: " << name << endl;
		cout << fixed << setprecision(2);
		cout << "Balance: " << balance << endl;
	}
};
int main()
{
	account accounts[10];
	int total_accounts = 0;
	int choice;

	do
	{
		cout << "       BANKING SYSTEM        " << endl;

		cout << "1. Create Account" << endl;
		cout << "2. Deposit Money" << endl;
		cout << "3. Withdraw Money" << endl;
		cout << "4. Transfer Money" << endl;
		cout << "5. Display Account" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		if (choice == 1)
		{
			accounts[total_accounts].create_account();

			total_accounts++;

			cout << "Account Created Successfully..." << endl;
		}
		else if (choice == 2)
		{
			int acc_no;
			bool found = false;
			cout << "Enter Account Number: ";
			cin >> acc_no;
			for (int i = 0; i < total_accounts; i++)
			{
				if (accounts[i].get_account_number() == acc_no)
				{
					accounts[i].deposit();

					found = true;

					break;
				}
			}
			if (!found)
			{
				cout << "Account Not Found..." << endl;
			}
		}
		else if (choice == 3)
		{
			int acc_no;
			bool found = false;
			cout << "Enter Account Number: ";
			cin >> acc_no;
			for (int i = 0; i < total_accounts; i++)
			{
				if (accounts[i].get_account_number() == acc_no)
				{
					accounts[i].withdraw();

					found = true;

					break;
				}
			}
			if (!found)
			{
				cout << "Account Not Found..." << endl;
			}
		}
		else if (choice == 4)
		{
			int sender;
			int receiver;
			int sender_index = -1;
			int receiver_index = -1;
			cout << "Enter Sender Account Number: ";
			cin >> sender;
			cout << "Enter Receiver Account Number: ";
			cin >> receiver;
			for (int i = 0; i < total_accounts; i++)
			{
				if (accounts[i].get_account_number() == sender)
				{
					sender_index = i;
				}
				if (accounts[i].get_account_number() == receiver)
				{
					receiver_index = i;
				}
			}
			if (sender_index == -1 || receiver_index == -1)
			{
				cout << "Invalid Account Number..." << endl;
			}
			else
			{
				accounts[sender_index].transfer(accounts[receiver_index]);
			}
		}
		else if (choice == 5)
		{
			int acc_no;
			bool found = false;

			cout << "Enter Account Number: ";
			cin >> acc_no;

			for (int i = 0; i < total_accounts; i++)
			{
				if (accounts[i].get_account_number() == acc_no)
				{
					accounts[i].display_account();
					found = true;
					break;
				}
			}
			if (!found)
			{
				cout << "Account Not Found..." << endl;
			}
		}
		else if (choice == 6)
		{
			cout << "Program Ended..." << endl;
		}
		else
		{
			cout << "Invalid Choice..." << endl;
		}
	} while (choice != 6);

	return 0;
}