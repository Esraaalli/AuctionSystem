#include <iostream>
#include<string>
using namespace std;

int i = -1; //index of market item[i]
struct market //struct to store the data of item
{
	int item_id, bid_price, request = 0;
	string category, email1, name1, date;
};	struct market item[5];


void signin();
void signup();
void option();
void seller();
void buyer();
void items();
int main()
{
	option();


	system("pause");
}

void option() {
	int choice1;
	cout << "*********************WELCOME TO THE ONLINE AUCTION SYSTEM********************\n";
	cout << "1-Sign in\n";
	cout << "2-Sign up\n";
	cout << "3-Exit\n";
	cout << "Enter your choice: ";
	cin >> choice1;
	switch (choice1)
	{
	case 1: signin();
		break;

	case 2:signup();
		break;

	case 3:
		break;

	default:cout << "invalid choice\n"; option();
		break;
	}
}

void items() //the seller fill the data of item
{

	cout << "\nEnter your name: ";
	cin >> item[i].name1;
	cout << "\nEnter your e-mail: ";
	cin >> item[i].email1;
	cout << "\nEnter item id: ";
	cin >> item[i].item_id;

	do {
		cout << "\nEnter category(clothes,makeup,furniture,phone,car,book): ";
		cin >> item[i].category;

		if (item[i].category == "clothes" || item[i].category == "makeup" || item[i].category == "furniture" || item[i].category == "phone" || item[i].category == "car" || item[i].category == "book")
		{
			break;
		}
		else
		{
			cout << "\nInvalid category" << endl;
		}

	} while (item[i].category != "clothes" || item[i].category != "makeup" || item[i].category != "furniture" || item[i].category != "phone" || item[i].category != "car" || item[i].category != "book");

	cout << "\nEnter bid price: ";
	cin >> item[i].bid_price;
	cout << "\nEnter date: ";
	cin >> item[i].date;
	cout << "\nInsert item successful" << endl;
	seller();
}


void seller() //seller menu
{
	string feedback1, name2, accept;
	int choice2, found = 0;
	cout << "1-Insert new item\n";
	cout << "2-Handle buying requests\n";
	cout << "3-Top category\n";
	cout << "4-Give feedback\n";
	cout << "5-Sign out\n";
	cout << "Enter your choice : ";
	cin >> choice2;
	switch (choice2)
	{
	case 1:i++;
		items();
		break;
	case 2:
		cout << "\nPlease enter your name: ";
		cin >> name2;
		for (int k = 0; k < 5; k++)
		{
			if (name2 == item[k].name1 && item[k].request > 0)
			{
				cout << k + 1 << "-Number of requests :  " << item[k].request << "\n";
				cout << k + 1 << "-Item category :  " << item[k].category << "\n";
				cout << k + 1 << "-Item bid price: " << item[k].bid_price << "\n";
				cout << k + 1 << "-Item ID: " << item[k].item_id << "\n";
				cout << k + 1 << "-Item Date: " << item[k].date << "\n";
				found++;
				cout << "Your choice (yes,no): ";
				cin >> accept;

				if (accept == "yes")
				{
					item[k] = item[k + 1];

				}
				else if (accept == "No")
				{
					cout << "\nNot accepted" << endl;

				}

			}
		}
		if (found == 0)
		{
			cout << "\nNo requests found" << endl;

		}


		seller();
		break;

	case 3:    //display top category

		if (item[0].request > item[1].request && item[0].request > item[2].request && item[0].request > item[3].request && item[0].request > item[4].request)
		{
			cout << "The top category is: " << item[0].category << endl;
		}
		else if (item[1].request > item[0].request && item[1].request > item[2].request && item[1].request > item[3].request && item[1].request > item[4].request)
		{
			cout << "The top category is: " << item[1].category << endl;
		}
		else if (item[2].request > item[0].request && item[2].request > item[1].request && item[2].request > item[3].request && item[2].request > item[4].request)
		{
			cout << "The top category is: " << item[2].category << endl;

		}
		else if (item[3].request > item[0].request && item[3].request > item[1].request && item[3].request > item[2].request && item[3].request > item[4].request)
		{
			cout << "The top category is: " << item[3].category << endl;

		}
		else if (item[4].request > item[0].request && item[4].request > item[1].request && item[4].request > item[2].request && item[4].request > item[3].request)
		{
			cout << "The top category is: " << item[4].category << endl;

		}
		else
		{
			cout << "Not found top category" << endl;
		}
		seller();
		break;
	case 4:cout << "Your feedback: ";
		cin >> feedback1;
		seller();
		break;
	case 5: option();
		break;
	default:
		cout << "Invalid choice" << endl; seller();
	}
}

void buyer() //buyer menu
{

	string search;
	string feedback2;
	int choice2, id;
	int price, found = 0;


	cout << "\n1-Search by category\n";
	cout << "2-Search by price and catagory\n";
	cout << "3-Send buying request\n";
	cout << "4-Give feedback\n";
	cout << "5-Sell menu\n";
	cout << "6-Sign out\n";
	cout << "Enter yor choice: ";
	cin >> choice2;

	switch (choice2)
	{
	case 1:
		cout << "\nName of category: ";
		cin >> search;
		for (int j = 0; j < 5; j++)
		{
			if (search == item[j].category)
			{
				cout << "Name of seller is: " << item[j].name1 << "\n";
				cout << "E-mail of seller is: " << item[j].email1 << "\n";
				cout << "Item category: " << item[j].category << "\n";
				cout << "Item bid price: " << item[j].bid_price << "\n";
				cout << "Item ID: " << item[j].item_id << "\n";
				cout << "Item Date: " << item[j].date << "\n";
				found++;

			}
		}

		if (found == 0)
		{
			cout << "\nNot found item";
		}
		buyer();
		break;


	case 2:
		cout << "\nCategory of item: ";
		cin >> search;
		cout << "\nPrice of item: ";
		cin >> price;
		for (int j = 0; j < 5; j++)
		{
			if (search == item[j].category && price == item[j].bid_price)
			{
				cout << "\nName of seller is: " << item[j].name1 << "\t";
				cout << "E-mail of seller is: " << item[j].email1 << "\t";
				cout << "Item category: " << item[j].category << "\t";
				cout << "Item bid price: " << item[j].bid_price << "\t";
				cout << "Item ID: " << item[j].item_id << "\t";
				cout << "Item Date: " << item[j].date << "\t";
				found++;
			}
		}

		if (found == 0)
		{
			cout << "\nNot found item ";
		}
		buyer();
		break;

	case 3:
		cout << "\nInsert Id of the item you want: ";
		cin >> id;
		for (int j = 0; j < 5; j++)
		{
			if (id == item[j].item_id)
			{
				item[j].request++;
				found++;
				break;

			}
		}
		if (found == 0)
		{
			cout << "\nNot found item";
		}
		buyer();
		break;

	case 4:cout << "\nYour feedback: ";
		cin >> feedback2;
		buyer();
		break;

	case 5:seller();
		break;

	case 6:option();
		break;

	default:
		cout << "\nInvalid choice" << endl << "Enter your choice :"; buyer();
	}


}

void signin()
{
	string email2, password, type1;
	cout << "\nenter your email : ";
	cin >> email2;
	cout << "\nenter your password: ";
	cin >> password;
	cout << "\nSign-in successful";

	do {
		cout << "\nEnter your tybe buyer(B) or seller(S): ";
		cin >> type1;
		if (type1 == "S" || type1 == "B" || type1 == "s" || type1 == "b")
		{
			break;
		}
		else  cout << "\nInvalid type" << endl;

	} while (type1 != "S" || type1 != "B" || type1 != "s" || type1 != "b");

	if (type1 == "S" || type1 == "s")
	{
		seller();
	}
	if (type1 == "B" || type1 == "b")
	{
		buyer();
	}


}

void signup()
{
	string name3, email, password, address, type2;
	int phonenumber;
	cout << "\nEnter your name: ";
	cin >> name3;
	cout << "\nEnter your email,as(username@gmail.com):  ";
	cin >> email;
	cout << "\nEnter your password: ";
	cin >> password;
	cout << "\nEnter your adress: ";
	cin >> address;
	cout << "\nEnter your phone number:  ";
	cin >> phonenumber;
	cout << "\nsign-up successful\n";
	do
	{
		cout << "\nEnter your tybe buyer(B) or seller(S)";
		cin >> type2;
		if (type2 == "S" || type2 == "B" || type2 == "s" || type2 == "b")
		{
			break;
		}
		else cout << "\nInvalid type" << endl;


	} while (type2 != "S" || type2 != "B" || type2 != "s" || type2 != "b");

	cout << "\nYour name is: " << name3;
	if (type2 == "S" || type2 == "s")
	{
		seller();
	}
	if (type2 == "B" || type2 == "b")
	{
		buyer();
	}

}
