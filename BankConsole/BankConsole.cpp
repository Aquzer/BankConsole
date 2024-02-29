#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;

class Person
{
public:
	Person(string fn = "", string ln = "", string pn = "", string ad = "", int ag = 0) 
	{ firstName = fn; lastName = ln; phoneNumber = pn; address = ad; age = ag; isHaveBankAcc = false; };

	void setFirstName(string str) { firstName = str; }
	void setLastName(string str) { lastName = str;; }
	void setPhoneNumber(string str) { phoneNumber = str;; }
	void setAddress(string str) { address = str;; }
	void setAge(int num) { age = num; }
	void setIsHaveBankAcc(bool bl) { isHaveBankAcc = bl; }

	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	string getPhoneNumber() { return phoneNumber; }
	string getAddress() { return address; }
	int getAge() { return age; }
	bool getIsHaveBankAcc() { return isHaveBankAcc; }

	//friend class BankSystem;

private:
	string firstName, lastName, phoneNumber, address;
	int age;
	bool isHaveBankAcc;
};
//
//class BankSystem
//{
//public:
//	BankSystem() {};
//	BankSystem(Person p, double bal, int acc) {
//		person = p;
//		balance = bal;
//		account = acc;
//		person.isHaveBankAcc = true;
//	};
//	~BankSystem();
//
//private:
//	Person person;
//	double balance;
//	int account;
//};

void addPerson();
void deletePerson();
void editPerson();
void searchPerson();
void viewAllPersons();
void quit();

void showPerson(Person p, int i) {
	cout << "PERSON FOUND\n\n";
	cout << "id[" << i << "] \n\n";
	cout << "FIRSTNAME: " << p.getFirstName() << "\n";
	cout << "LASTNAME: " << p.getLastName() << "\n";
	cout << "PHONE NUMBER: " << p.getPhoneNumber() << "\n";
	cout << "ADDRESS: " << p.getAddress() << "\n";
	cout << "AGE: " << p.getAge() << "\n";
	cout << "IS HAVE BANK ACCOUNT: " << p.getIsHaveBankAcc() << "\n\n";
}

vector<Person> persons;

int main() {
	signed char choice;
	system("CLS");
	cout << "PERSONS SYSTEMS\n\n";
	cout << "[1]ADD PERSON\n";
	cout << "[2]DELETE PERSON\n";
	cout << "[3]EDIT PERSON\n";
	cout << "[4]SEARCH PERSON\n";
	cout << "[5]VIEW ALL PERSONS\n";
	cout << "[6]QUIT\n\n";

	cout << "ENTER YOUR CHOICE: ";
	cin >> choice;
	system("CLS");
	cin.ignore();

	switch (choice)
	{
	case '1':
		addPerson();
		break;
	case '2':
		deletePerson();
		break;
	case '3':
		editPerson();
		break;
	case '4':
		searchPerson();
		break;
	case '5':
		viewAllPersons();
		break;
	case '6':
		quit();
		break;
	default:
		main();
		break;
	}

	_getch();
	return 0;
}

void addPerson() {
	string firstName, lastName, phoneNumber, address;
	int age;
	cout << "ADD PERSON\n\n";

	cout << "ENTER FIRSTNAME: ";
	getline(cin, firstName);
	cout << "ENTER LASTNAME: ";
	getline(cin, lastName);
	cout << "ENTER PHONENUMBER: ";
	getline(cin, phoneNumber);
	cout << "ENTER ADDRESS: ";
	getline(cin, address);
	cout << "ENTER AGE: ";
	cin >> age;
	while (age > 100 && age < 18)
	{
		cout << "ENTER VALID AGE: ";
		cin >> age;
	}
	Person p(firstName, lastName, phoneNumber, address, age);
	persons.push_back(p);
	cout << "\n\nPERSON ADDED SUCCESSFULLY!\nPress any key to continue . . .";
	_getch();
	main();
}

void deletePerson() {
	int id;
	cout << "DELETE PERSON\n\n";
	cout << "ENTER PERSON ID: ";
	cin >> id;
	if (id <= persons.size())
	{
		persons.erase(persons.begin() + id);
	}
	else
	{
		cout << "NO PERSONS TO DELETE\nPress any key to continue . . .";
	}
	_getch();
	main();
}

void editPerson() {
	string par;
	signed char choice;
	int id;
	bool isContinue = true;
	cout << "EDIR PERSON\n\n";
	cout << "ENTER PERSON ID: ";
	cin >> id;
	while (isContinue)
	{
		if (id > persons.size())
		{
			cout << "NO PERSONS TO DELETE\nPress any key to continue . . .";
		}
		break;
		if (id <= persons.size())
		{
			cout << "ENTER PARAMETR TO EDIT: \n";
			cout << "[1]FIRSTNAME\n";
			cout << "[2]LASTNAME\n";
			cout << "[3]PHONENUMBER\n";
			cout << "[4]ADDRESS\n";
			cout << "[5]AGE\n";

			cin >> choice;

			switch (choice)
			{
			case '1':
				cout << "PREVIOUS FIRST NAME: " << persons[id].getFirstName() << "\n";
				cout << "ENTER NEW FIRSTNAME: ";
				getline(cin, par);
				persons[id].setFirstName(par);
				cout << "PERSON MODIFIED SUCCESSFULY\nCONTINUE EDITING THIS PERSON?\n[1] yes\n[2] no";
				cin >> isContinue;
				break;
			default:
				break;
			}
		}
	}
	_getch();
	main();
}

void searchPerson() {
	signed char choice;
	string par;
	cout << "SEARCH PERSON\n\n";
	if (persons.size() == 0)
	{
		cout << "THERE IS NO PERSON TO SEARCH!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout << "[1]FIRSTNAME\n";
	cout << "[2]LASTNAME\n";
	cout << "[3]PHONENUMBER\n";
	cout << "[4]ADDRESS\n";
	cout << "[5]AGE\n";
	cin >> choice;
	system("CLS");

	switch (choice)
	{
	case '1':
		cout << "ENTER FIRSTNAME: ";
		getline(cin, par);
		for (int i = 0; i < persons.size(); i++)
		{
			if (persons[i].getFirstName() == par) {
				showPerson(persons[i], i);
			}
		}
		break;
	case '2':
		cout << "ENTER LASTNAME: ";
		getline(cin, par);
		for (int i = 0; i < persons.size(); i++)
		{
			if (persons[i].getLastName() == par) {
				showPerson(persons[i], i);
			}
		}
		break;
	case '3':
		cout << "ENTER PHONENUMBER: ";
		getline(cin, par);
		for (int i = 0; i < persons.size(); i++)
		{
			if (persons[i].getPhoneNumber() == par) {
				showPerson(persons[i], i);
			}
		}
		break;
	case '4':
		cout << "ENTER ADDRESS: ";
		getline(cin, par);
		for (int i = 0; i < persons.size(); i++)
		{
			if (persons[i].getAddress() == par) {
				showPerson(persons[i], i);
			}
		}
		break;
	case '5':
		cout << "ENTER AGE: ";
		getline(cin, par);

		for (int i = 0; i < persons.size(); i++)
		{
			if (persons[i].getAge() == stoi(par)) {
				showPerson(persons[i], i);
			}
		}
		break;
	default:
		cout << "PERSON NOT FOUND!\n\nPress any key to continue . . .";
		_getch();
		main();
		break;
	}
}

void viewAllPersons() {
	cout << "VIEW ALL PERSONS\n\n";
	for (int i = 0; i < persons.size(); i++)
	{
		cout << "PERSON DETAILS\n\n";
		cout << "id[" << i << "] " << "FIRSTNAME: " << persons[i].getFirstName() << "\n";
		cout << "LASTNAME: " << persons[i].getLastName() << "\n";
		cout << "PHONE NUMBER: " << persons[i].getPhoneNumber() << "\n";
		cout << "ADDRESS: " << persons[i].getAddress() << "\n";
		cout << "AGE: " << persons[i].getAge() << "\n";
		cout << "IS HAVE BANK ACCOUNT: " << persons[i].getIsHaveBankAcc() << "\n\n";
	}
	cout << "Press any key to continue . . .";
	_getch();
	main();
}

void quit() {
	_exit(1);
}
