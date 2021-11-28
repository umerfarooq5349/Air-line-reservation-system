#include<iostream>
using namespace std;
struct Air_Line_Ticket {
	int cnic;
	string Name;
	Air_Line_Ticket* next;
};
Air_Line_Ticket* first = new Air_Line_Ticket();
class Get_Air_line {
public:
	void get_ticket(int no,string name) {
		//system("cls");
		Air_Line_Ticket* temp = new Air_Line_Ticket();
		temp->cnic = no;
		temp->Name = name;
		temp->next = first;
		cout << " Your ticket is booked (:" << endl<<endl;
		first = temp;

	}
	void search(string n) {
		//system("cls");
		Air_Line_Ticket* t = first;
		while (t->next != NULL) {
			if (t->Name == n) {
				cout << n<<" Congrajulations your ticket is confirmed (:" << endl;
				break;
			}
			t = t->next;
		}
	}
	void display() {
		system("cls");
		Air_Line_Ticket* temp = first;
		while (temp->next != NULL) {
			cout << "Passenger name: " << temp->Name 
				 << "\t passenger CNIC: "<<temp->cnic
				 << endl;
			temp = temp->next;
		}
	}
	void cancelTicket(string name) {
		//system("cls");
		Air_Line_Ticket* cancel = first;
		while (cancel->next != NULL) {
			if (cancel->Name == name) {
				cout <<cancel->Name<< " Your ticket is canceled ):" << endl; 
				//first = cancel->next->next;
				free(cancel->next);
				break;
			}
			cancel = cancel->next;
		}
	}
};
int main() {

	Get_Air_line n1;
	int choice;
	int cnic;
	string name;
a:  system("cls");
	cout << "\n\n\tWelcome to Air line reservation system" << endl << endl
		 << "  Press 1: Reserve a ticket\n"
		 << "  Press 2: See All booked tickets\n"
		 << "  Press 3: Check for your resevation\n"
		 << "  Press 4: Cancel your ticket\n"
		 << "\n\tPlease enter your choice: ";
	cin >> choice;
	if (choice == 1) {

		cout << " Enter your name: ";
		cin >> name;
		cout << " Enter your CNIC: ";
		cin >> cnic;
		n1.get_ticket(cnic, name);
		system("pause");
		goto a;
	}
	if (choice == 2) {
		n1.display();
		cout << endl;
		system("pause");
		goto a;
	}
	if (choice == 3) {
		cout << " Enter your name: ";
		cin >> name;
		n1.search(name);
		cout << endl;
		system("pause");
		goto a;
	}
	if (choice == 4) {
		cout << " Enter your name: ";
		cin >> name;
		n1.cancelTicket(name);
		cout << endl;
		system("pause");
		goto a;
	}
	return 0;
}